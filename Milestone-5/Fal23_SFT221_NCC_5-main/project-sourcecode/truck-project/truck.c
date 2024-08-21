#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "shipment.h"
#include "truck.h"
#include "mapping.h"

// Implementation of the findTruckForShipment function, -1 = invalid, anything else is valid
int findTruckForShipment(const struct Map* map, const struct Truck trucks[], const int numTrucks, const struct Shipment shipment)
{
	// Initialize variables to store the best truck index and the minimum distance
	int bestTruckIndex = -1;
	double minDistance = INT_MAX;

	// safety check
	if (map && trucks)
	{
		// Iterate through each truck to find the best one for the shipment
		for (int i = 0; i < numTrucks; i++)
		{
			// Check if the truck can accommodate the shipment based on weight and size
			if (!IsTruckFull(trucks[i]) &&
				IsValidSize4Truck(trucks[i], shipment.boxSize) &&
				IsValidWeight4Truck(trucks[i], shipment.weight))
			{

				// Calculate the distance from the truck's current position to the shipment destination
				struct Point shipmentDestination = shipment.destination;
				int closeestPointId = getClosestPoint(&trucks[i].route, shipmentDestination);
				struct Point closestpoint = trucks[i].route.points[closeestPointId];
				struct Route route = shortestPath(map, closestpoint, shipmentDestination);
				double distance = (double)route.numPoints;

				// Check if this truck has a shorter distance than the current minimum
				if (distance < minDistance)
				{
					minDistance = distance;
					bestTruckIndex = i;
				}
			}
		}
	}

	// Return the index of the best truck for the shipment (-1 if no suitable truck is found)
	return bestTruckIndex;
}

// Implementation of the IsValidSize4Truck function
int IsValidSize4Truck(const struct Truck truck, double size)
{
	// Check if adding the package size exceeds the maximum cargo volume limit
	if (IsValidSize(size) && truck.size + size <= TRUCK_MAX_SIZE)
	{
		// Package size is valid, not overloaded
		return 1;
	}
	else
	{
		// Package size exceeds the maximum cargo volume, making it invalid
		return 0;
	}
}

// Implementation of the IsValidWeight4Truck function
int IsValidWeight4Truck(const struct Truck truck, int weight)
{
	// Check if adding the package weight exceeds the maximum cargo weight limit
	if (weight > 0 && truck.weight + weight <= TRUCK_MAX_WEIGHT)
	{
		// Package weight is valid, not overloaded
		return 1;
	}
	else
	{
		// Package weight exceeds the maximum cargo weight, making it invalid
		return 0;
	}
}

// Implementation of the IsValidSize function
int IsValidSize(const float size)
{
	int result = 1; // default valid

	if (size != 0.5 && size != 1 && size != 2)
	{
		result = 0;
	}

	return result;
}

// Implementation of the IsTruckFull function
int IsTruckFull(const struct Truck truck)
{
	// Check if the truck's weight exceeds the maximum cargo weight
	// or the truck's size exceeds the maximum cargo size
	if (truck.weight >= TRUCK_MAX_WEIGHT || truck.size >= TRUCK_MAX_SIZE)
	{
		// Truck is full, cannot receive anything else
		return 1;
	}
	else
	{
		// Truck can still receive packages
		return 0;
	}
}

// Integration of every function, the main function of delivery
int deliveryMain(const struct Map* map, struct Truck trucks[])
{
	int ok = 1;

	// for printing the final map
	struct Map curmap = *map;

	// header
	printf("\n");
	printf("=================\n");
	printf("Seneca Deliveries\n");
	printf("=================\n");

	// initialize
	int weight = 0;
	double size = 0;
	int row = 0;
	int col = 0;
	char rcChar[4] = { 0 };

	do
	{
		// get user input
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		scanf("%d %lf %s", &weight, &size, &rcChar);

		// clear input buffer to prevent deadend loop
		fflush(stdin);

		if (weight != 0 && size != 0 && strcmp(rcChar, "x") != 0)
		{
			// convert user input string to int for row and column
			if (!convertStringToRowCol(rcChar, &row, &col))
			{
				printf("Invalid input\n");
				continue;
			}

			// validate destination
			if (!(row >= 0 && row <= 24) || !(col >= 0 && col <= 24) ||
				map->squares[row][col] == 1)
			{
				// invalid
				printf("Invalid destination\n");
				continue;
			}

			// validate size
			if (!IsValidSize(size))
			{
				// invalid
				printf("Invalid size\n");
				continue;
			}

			// validate weight
			if (!(weight >= 1 && weight <= 1000))
			{
				// invalid
				printf("Invalid weight (must be 1-1000Kg.)\n");
				continue;
			}

			struct Shipment shipment = { weight, size,{row,col} };

			int truckid = findTruckForShipment(map, trucks, 3, shipment);

			if (truckid != -1)
			{
				printf("Ship on %s LINE", trucks[truckid].routeName);

				// get diverted path
				int clsPtId = getClosestPoint(&trucks[truckid].route, shipment.destination);
				struct Point closestpoint = trucks[truckid].route.points[clsPtId];
				struct Route droute = finalizeRoute(shortestPath(map, closestpoint, shipment.destination));

				// display diverted path if any
				int i = 0;
				int j = clsPtId;
				int divertCount = 0;
				for (i = 0; i < droute.numPoints; i++)
				{
					// if it is not the original route
					if (j > trucks[truckid].route.numPoints ||
						!eqPt(trucks[truckid].route.points[j], droute.points[i]))
					{
						struct Point pt = droute.points[i];
						divertCount++;
						printf(", %d%c", pt.row + 1, pt.col + 'A');
					}
					j++;
				}
				if (divertCount == 0)
				{
					printf(", no diversion");
				}

				printf("\n");

				// store shipment to truck
				trucks[truckid].size += shipment.boxSize;
				trucks[truckid].weight += shipment.weight;
				trucks[truckid].payloads[trucks[truckid].payloadNum++] = shipment;

				curmap = addRoute(&curmap, &droute);
			}
			else
			{
				printf("Sorry, No available truck for this shipment!\n");
			}
		}
	} while (weight != 0 && size != 0 && strcmp(rcChar, "x") != 0);

	printf("Thanks for shipping with Seneca!\n\n");

	printMap(&curmap, 1, 1);

	return ok;
}

int convertStringToRowCol(char input[], int* row, int* col)
{
	int ok = 1;

	// convert row and col from string to int
	char rowStr[3] = { 0 };
	char colCha = 'x';
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (isdigit(input[i]))
		{
			rowStr[i] = input[i];
		}
		else if (isalpha(input[i]))
		{
			colCha = input[i];
		}
	}
	rowStr[2] = '\0';		 // teminate string
	*row = atoi(rowStr) - 1; // convert string to int
	*col = colCha - 'A';	 // convert char to int

	// simple validation
	if (row < 0 || col < 0)
	{
		ok = 0;
	}

	return ok;
}
