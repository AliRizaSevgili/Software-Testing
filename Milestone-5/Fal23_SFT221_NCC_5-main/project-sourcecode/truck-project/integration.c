#include "integration.h"

// Add blue truck route to base map
int t01()
{
	printf("t01 - Add blue truck route to base map\n\n");
	struct Map map = populateMap();
	struct Route blue = getBlueRoute();
	map = addRoute(&map, &blue);
	printf("\n");
	printMap(&map, 1, 1);
	printf("----------------------------------------\n");
	printf("\n");
	return 1;
}
// Add green truck route to base map
int t02() {
	printf("t02 - Add green truck route to base map\n\n");
	struct Map map = populateMap();
	struct Route green = getGreenRoute();
	map = addRoute(&map, &green);
	printf("\n");
	printMap(&map, 1, 1);
	printf("----------------------------------------\n");
	printf("\n");
	return 1;
}
// Add yellow truck route to base map
int t03() {
	printf("t03 - Add yellow truck route to base map\n\n");
	struct Map map = populateMap();
	struct Route yellow = getYellowRoute();
	map = addRoute(&map, &yellow);
	printf("\n");
	printMap(&map, 1, 1);
	printf("----------------------------------------\n");
	printf("\n");
	return 1;
}
// Add all the three truck routes to base map
int t04()
{
	printf("t04 - Add all the three truck routes to base map\n\n");
	struct Map map = populateMap();
	struct Route yellow = getYellowRoute();
	map = addRoute(&map, &yellow);
	struct Route green = getGreenRoute();
	map = addRoute(&map, &green);
	struct Route blue = getBlueRoute();
	map = addRoute(&map, &blue);
	printf("\n");
	printMap(&map, 1, 1);
	printf("----------------------------------------\n");
	printf("\n");
	return 1;
}
// Calculate distance for the shortest path
int t05()
{
	printf("t05 - Calculate distance for the shortest path\n\n");
	struct Map map = populateMap();
	struct Point st = { 0, 0 };
	struct Point end = { 9,24 };
	struct Route route = finalizeRoute(shortestPath(&map, st, end));
	map = addRoute(&map, &route);
	printf("\n");
	printMap(&map, 1, 1);
	printf("----------------------------------------\n");
	printf("\n");
	return 1;
}
// Calculate distance for an invalid path
int t06()
{
	printf("t06 - Calculate distance for an invalid path\n\n");
	struct Map map = populateMap();
	struct Point st = { 0, 0 };
	struct Point end = { 23, 24 };
	struct Route route = finalizeRoute(shortestPath(&map, st, end));
	map = addRoute(&map, &route);
	printf("\n");
	printMap(&map, 1, 1);
	printf("----------------------------------------\n");
	printf("\n");
	return 1;
}
// Calculate distance for an empty path
int t07()
{
	printf("t07 - Calculate distance for an empty path\n\n");
	struct Map map = populateMap();
	struct Point st = { 0, 0 };
	struct Point end = { 0, 0 };
	struct Route route = finalizeRoute(shortestPath(&map, st, end));
	map = addRoute(&map, &route);
	printf("\n");
	printMap(&map, 1, 1);
	printf("----------------------------------------\n");
	printf("\n");
	return 1;
}
// Calculate distance with invalid parameters
int t08()
{
	printf("t08 - Calculate distance with invalid parameters\n\n");
	struct Map map = populateMap();
	struct Point st = { -1, -1 };
	struct Point end = { 9, 24 };
	struct Route route = finalizeRoute(shortestPath(&map, st, end));
	map = addRoute(&map, &route);
	printf("\n");
	printMap(&map, 1, 1);
	printf("----------------------------------------\n");
	printf("\n");
	return 1;
}
// Calculate distance for the closest route
int t09()
{
	printf("t09 - Calculate distance for the closest route\n\n");
	struct Map map = populateMap();
	// 1st route
	struct Point pt1[5] = { {0, 0}, {4,0},{9,24} };
	struct Route route1 = { {0}, 0, BLUE };
	double distance1 = 0;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		struct Route newRoute = finalizeRoute(shortestPath(&map, pt1[i], pt1[i + 1]));
		int j = 0;
		for (j = 0; j < newRoute.numPoints; j++)
		{
			addPointToRouteIfNot(&route1, newRoute.points[j].row, newRoute.points->col, route1);
			if (j < newRoute.numPoints - 1)
			{
				distance1 += distance(&newRoute.points[j], &newRoute.points[j + 1]);
			}
		}
	}

	// 2nd route
	struct Point pt2[5] = { {0, 0}, {8, 8}, {17, 17}, {9, 24} };
	struct Route route2 = { {0}, 0, BLUE };
	double distance2 = 0;
	for (i = 0; i < 5; i++)
	{
		struct Route newRoute = finalizeRoute(shortestPath(&map, pt2[i], pt2[i + 1]));
		int j = 0;
		for (j = 0; j < newRoute.numPoints; j++)
		{
			addPointToRouteIfNot(&route2, newRoute.points[j].row, newRoute.points->col, route2);
			if (j < newRoute.numPoints - 1)
			{
				distance2 += distance(&newRoute.points[j], &newRoute.points[j + 1]);
			}
		}
	}

	map = addRoute(&map, &route1);
	map = addRoute(&map, &route2);
	printMap(&map, 1, 1);

	printf("\n");
	printf("----------------------------------------\n");
	printf("t09 distance Route 1: %lf, Route 2: %lf\n", distance1, distance2);
	printf("\n");
	return 1;
}
// Calculate distance for an invalid route
int t10()
{
	printf("t10 - Calculate distance for an invalid route\n\n");
	struct Map map = populateMap();

	struct Point pt[5] = { {0, 0}, {9,23} };
	struct Route route = { {0}, 0, BLUE };
	double distance1 = 0;
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		struct Route newRoute = finalizeRoute(shortestPath(&map, pt[i], pt[i + 1]));
		int j = 0;
		for (j = 0; j < newRoute.numPoints; j++)
		{
			addPointToRouteIfNot(&route, newRoute.points[j].row, newRoute.points->col, route);
			if (j < newRoute.numPoints - 1)
			{
				distance1 += distance(&newRoute.points[j], &newRoute.points[j + 1]);
			}
		}
	}

	map = addRoute(&map, &route);
	printMap(&map, 1, 1);

	printf("\n");
	printf("----------------------------------------\n");
	printf("t10 distance Route : %lf\n", distance1);
	printf("\n");
	return 1;
}
// Calculate distance for an empty route
int t11()
{
	printf("t11 - Calculate distance for an empty route\n\n");
	struct Map map = populateMap();

	struct Point pt[5] = { {0, 0}, {0,0} };
	struct Route route = { {0}, 0, BLUE };
	double distance1 = 0;
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		struct Route newRoute = finalizeRoute(shortestPath(&map, pt[i], pt[i + 1]));
		int j = 0;
		for (j = 0; j < newRoute.numPoints; j++)
		{
			addPointToRouteIfNot(&route, newRoute.points[j].row, newRoute.points->col, route);
			if (j < newRoute.numPoints - 1)
			{
				distance1 += distance(&newRoute.points[j], &newRoute.points[j + 1]);
			}
		}
	}

	map = addRoute(&map, &route);
	printMap(&map, 1, 1);

	printf("\n");
	printf("----------------------------------------\n");
	printf("t11 distance Route : %lf\n", distance1);
	printf("\n");
	return 1;
}
// Calculate distance with invalid parameters
int t12()
{
	printf("t12 - Calculate distance with invalid parameters\n\n");
	struct Map map = populateMap();

	struct Point pt[5] = { {0, 0}, {30, 30} };
	struct Route route = { {0}, 0, BLUE };
	double distance1 = 0;
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		struct Route newRoute = finalizeRoute(shortestPath(&map, pt[i], pt[i + 1]));
		int j = 0;
		for (j = 0; j < newRoute.numPoints; j++)
		{
			addPointToRouteIfNot(&route, newRoute.points[j].row, newRoute.points->col, route);
			if (j < newRoute.numPoints - 1)
			{
				distance1 += distance(&newRoute.points[j], &newRoute.points[j + 1]);
			}
		}
	}

	map = addRoute(&map, &route);
	printMap(&map, 1, 1);

	printf("\n");
	printf("----------------------------------------\n");
	printf("t12 distance Route : %lf\n", distance1);
	printf("\n");
	return 1;
}

// Identify possible moves and add points to the route
int t13()
{
	printf("t13 - Identify possible moves and add points to the route\n\n");
	struct Map map = populateMap();

	struct Route route = { {0}, 0, BLUE };
	struct Point pt = { 2, 2 };
	printf("Current route: empty\n");

	printf("\n");
	printf("----------------------------------------\n");
	printf("t13 Check {2, 2} exists in route? %d\n", ptExistInRt(route, pt));
	printf("\n");
	return 1;
}
// Add points to an existing route
int t14()
{
	printf("t14 - Add points to an existing route\n\n");
	struct Map map = populateMap();

	struct Route route = {
		{
			{2, 2},
			{2, 3},
			{2, 4}
		},
			3, BLUE
	};
	struct Point pt = { 2, 2 };
	printf("Current route: {2, 2},{2, 3},{ 2, 4 }\n");

	printf("\n");
	printf("----------------------------------------\n");
	printf("t14 Check {2, 2} exists in route? %d\n", ptExistInRt(route, pt));
	printf("\n");
	return 1;
}

// Check if a point exists in the route
int t15()
{
	printf("t15 - Add points to an existing route");
	struct Map map = populateMap();

	struct Route route = {
		{
			{2, 2},
			{2, 3},
			{2, 4}
		},
			3, BLUE
	};
	struct Point pt = { 3, 4 };
	printf("Current route: {2, 2},{2, 3},{ 2, 4 }\n");

	printf("\n");
	printf("----------------------------------------\n");
	printf("t15 Check {3, 4} exists in route? %d\n", ptExistInRt(route, pt));
	printf("\n");
	return 1;
}
// Add a point to the route only if it doesn't exist
int t16()
{
	printf("t16 - Add a point to the route only if it doesn't exist");
	struct Map map = populateMap();

	struct Route route = {
		{
			{2, 2},
			{2, 3},
			{2, 4}
		},
			3, BLUE
	};
	struct Point pt = { 2, 3 };
	printf("Current route: {2, 2},{2, 3},{ 2, 4 }\n");

	printf("\n");
	printf("----------------------------------------\n");
	printf("t16 Check {2, 3} exists in route? %d\n", ptExistInRt(route, pt));
	printf("\n");
	return 1;
}

int main()
{
	t01();
	t02();
	t03();
	t04();
	t05();
	t06();
	t07();
	t08();
	t09();
	t10();
	t11();
	t12();
	t13();
	t14();
	t15();
	t16();
}