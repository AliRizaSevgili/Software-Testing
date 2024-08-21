#ifndef TRUCK_H
#define TRUCK_H

#define TRUCK_MAX_WEIGHT 1500
#define TRUCK_MAX_SIZE 48

#include "shipment.h"
#include "mapping.h"

struct Truck
{
	/// @brief in kg
	/// Use TRUCK_MAX_WEIGHT to get the limit
	int weight;
	/// @brief cubic meters
	/// Use TRUCK_MAX_SIZE to get the limit
	double size;
	/// @brief number of payload
	int payloadNum;
	/// @brief Contains the loaded boxes
	struct Shipment payloads[99];
	/// @brief Route taken by this truck
	struct Route route;
	/// @brief Route name
	char routeName[7];
};

// Function prototype
int findTruckForShipment(const struct Map* map, const struct Truck trucks[], const int numTrucks, const struct Shipment shipment);
int IsValidSize4Truck(const struct Truck truck, double size);
int IsValidWeight4Truck(const struct Truck truck, int weight);
int IsValidSize(const float size);
int IsTruckFull(const struct Truck truck);
int deliveryMain(const struct Map* map, struct Truck trucks[]);
int convertStringToRowCol(char input[], int* row, int* col);

#endif