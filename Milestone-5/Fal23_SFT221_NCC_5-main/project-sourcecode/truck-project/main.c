#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "mapping.h"
#include "truck.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route yellowRoute = getYellowRoute();
	struct Route greenRoute = getGreenRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);
	routeMap = addRoute(&routeMap, &greenRoute);

	printMap(&routeMap, 1, 1);

	// define trucks
	struct Truck trucks[3] = { { 0,0,0,{0}, blueRoute, "BLUE" },
							   { 0,0,0,{0}, yellowRoute, "YELLOW" } ,
							   { 0,0,0,{0}, greenRoute, "GREEN" } };

	// delivery program start
	deliveryMain(&routeMap, trucks);

	printf("Press Enter to continue!\n");
	getchar();

	printf("Thanks for shipping with Seneca!\n\n");

	return 0;
}