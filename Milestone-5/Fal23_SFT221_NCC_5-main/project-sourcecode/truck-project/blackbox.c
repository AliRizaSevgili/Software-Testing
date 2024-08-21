#include "blackbox.h"

// blackbox testing for findTruckForShipment
int testFindTruckForShipment()
{
	int ok = 1;
	const struct Map map = populateMap();
	struct Truck trucks[3];
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		struct Point pos = { 0, 0 };
		trucks[i].size = 0;
		trucks[i].weight = 0;
	}
	trucks[0].route = getBlueRoute();
	trucks[1].route = getGreenRoute();
	trucks[2].route = getYellowRoute();

	int testCount = 0;

	// test 1, Positive test: To test if the function functions correctly with normal data
	struct Shipment shipment1 = { 500, 1, {13, 10} };
	printf("testFindTruckForShipment test %d ", ++testCount);
	if (findTruckForShipment(&map, trucks, 3, shipment1) < 0)
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");

	}

	// test 2, Negative test: To test if the function rejects excess shipment
	struct Shipment shipment2 = { 1600, 1, {13, 10} };
	printf("testFindTruckForShipment test %d ", ++testCount);
	if (findTruckForShipment(&map, trucks, 3, shipment2) > -1)
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");

	}

	// test 3, Negative test: To test if the function can find a truck with incorrect numTrucks
	struct Shipment shipment3 = { 500, 1, {13, 10} };
	printf("testFindTruckForShipment test %d ", ++testCount);
	if (findTruckForShipment(&map, trucks, 2, shipment3))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");

	}

	// test 4, Negative test: To test if the function function properly with invalid data
	struct Shipment shipment4 = { 500, 1, {13, 10} };
	printf("testFindTruckForShipment test %d ", ++testCount);
	if (findTruckForShipment(&map, NULL, 3, shipment4) > -1)
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 5, Negative test: To test if the function function properly with invalid data
	struct Shipment shipment5 = { 500, 1, {13, 10} };
	printf("testFindTruckForShipment test %d ", ++testCount);
	if (findTruckForShipment(NULL, trucks, 3, shipment5) > -1)
	{
		printf("failed\n");
	}
	else
	{
		printf("success\n");

	}

	// test 6, Edge case testing: It should work. Test if it really works.
	struct Shipment shipment6 = { 1500, 48, {13, 10} };
	printf("testFindTruckForShipment test %d ", ++testCount);
	if (findTruckForShipment(&map, trucks, 3, shipment6) < 0)
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");

	}

	return ok;
}
// blackbox testing for isValidVolume
int testIsValidSize4Truck()
{
	int ok = 1;

	struct Point pos = { 0, 0 };
	struct Truck truck;
	truck.size = 0;
	truck.weight = 0;
	truck.route = getBlueRoute();

	int testCount = 0;

	// test 1, Positive test: positive result if box size fits
	printf("testIsValidSize4Truck test %d ", ++testCount);
	if (!IsValidSize4Truck(truck, 0.5))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 2, Edge case: Box just fits the Truck size
	truck.size = 47.5;
	printf("testIsValidSize4Truck test %d ", ++testCount);
	if (!IsValidSize4Truck(truck, 0.5))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 3, Out of boundary test: boxSize doesn’t fit, negative result should be returned
	printf("testIsValidSize4Truck test %d ", ++testCount);
	if (IsValidSize4Truck(truck, TRUCK_MAX_SIZE + 1))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 4, Negative test: invalid boxSize, should return 0
	printf("testIsValidSize4Truck test %d ", ++testCount);
	if (IsValidSize4Truck(truck, -1)) 
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 5, Negative test: invalid truck data, should return 0
	truck.size = TRUCK_MAX_SIZE * 2;
	printf("testIsValidSize4Truck test %d ", ++testCount);
	if (IsValidSize4Truck(truck, 2))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}
	return ok;
}
// blackbox testing for isValidWeight
int testIsValidWeight4Truck()
{

	int ok = 1;

	struct Point pos = { 0, 0 };
	struct Truck truck;
	truck.size = 0;
	truck.weight = 0;
	truck.route = getBlueRoute();

	int testCount = 0;

	// test 1, Positive test: positive result if box weight fits
	printf("IsValidWeight4Truck test %d ", ++testCount);
	if (!IsValidWeight4Truck(truck, TRUCK_MAX_WEIGHT / 2))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 2, Edge case: Box just fits the Truck weight
	printf("IsValidWeight4Truck test %d ", ++testCount);
	if (!IsValidWeight4Truck(truck, TRUCK_MAX_WEIGHT))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 3, Out of boundary test: weight doesn’t fit, negative result should be returned
	printf("IsValidWeight4Truck test %d ", ++testCount);
	if (IsValidWeight4Truck(truck, TRUCK_MAX_WEIGHT + 1))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 4, Negative test: invalid weight, should return 0
	printf("IsValidWeight4Truck test %d ", ++testCount);
	if (IsValidWeight4Truck(truck, -1))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 5, Negative test: invalid truck data, should return 0
	truck.weight = TRUCK_MAX_WEIGHT * 2;
	printf("IsValidWeight4Truck test %d ", ++testCount);
	if (IsValidWeight4Truck(truck, 500))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	return ok;
}
// backbox testing for isValidSize
int testIsValidSize()
{
	int ok = 1;

	int testCount = 0;

	// test 1, Positive test: only 0.5, 1 or 2 are accepted
	printf("testIsValidSize test %d ", ++testCount);
	if (!IsValidSize(0.5))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 2, Positive test: only 0.5, 1 or 2 are accepted
	printf("testIsValidSize test %d ", ++testCount);
	if (!IsValidSize(1))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 3, Positive test: only 0.5, 1 or 2 are accepted
	printf("testIsValidSize test %d ", ++testCount);
	if (!IsValidSize(2))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 4, Negative test: invalid sizes, should return 0
	printf("testIsValidSize test %d ", ++testCount);
	if (IsValidSize(0))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 5, Negative test: invalid sizes, should return 0
	printf("testIsValidSize test %d ", ++testCount);
	if (IsValidSize(3))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	return ok;
}
// blackbox testing for isTruckFull
int testIsTruckFull()
{
	int ok = 1;

	struct Point pos = { 0, 0 };
	struct Truck truck;
	truck.size = TRUCK_MAX_SIZE;
	truck.weight = TRUCK_MAX_WEIGHT;
	truck.route = getBlueRoute();

	int testCount = 0;

	// test 1, Positive test: Maximum number of both attributes
	printf("IsTruckFull test %d ", ++testCount);
	if (!IsTruckFull(truck))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 2, Positive test: Maximum weight
	truck.size = 30;
	truck.weight = TRUCK_MAX_WEIGHT;
	printf("IsTruckFull test %d ", ++testCount);
	if (!IsTruckFull(truck))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 3, Positive test: Maximum Size
	truck.size = TRUCK_MAX_SIZE;
	truck.weight = 1000;
	printf("IsTruckFull test %d ", ++testCount);
	if (!IsTruckFull(truck))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 4, Positive test: not full
	truck.size = 30;
	truck.weight = 1000;
	printf("IsTruckFull test %d ", ++testCount);
	if (IsTruckFull(truck))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 5, Negative test: despite being invalid state, it should still return 0
	truck.size = -1;
	truck.weight = 1000;
	printf("IsTruckFull test %d ", ++testCount);
	if (IsTruckFull(truck))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	// test 6, Negative test: despite being invalid state, it should still return 0
	truck.size = 1;
	truck.weight = -1;
	printf("IsTruckFull test %d ", ++testCount);
	if (IsTruckFull(truck))
	{
		printf("failed\n");
		ok = 0;
	}
	else
	{
		printf("success\n");
	}

	return ok;
}

int main()
{
	int ok = 0;// ok 
	if (!testFindTruckForShipment())
	{
		ok = 1;
		printf("testFindTruckForShipment  failed\n\n");
	}
	else
	{
		printf("testFindTruckForShipment  succeed\n\n");
	}
	if (!testIsValidSize4Truck())
	{
		ok = 2;
		printf("testIsValidSize4Truck  failed\n\n");
	}
	else
	{
		printf("testIsValidSize4Truck  succeed\n\n");
	}
	if (!testIsValidWeight4Truck())
	{
		ok = 3;
		printf("testIsValidWeight4Truck  failed\n\n");
	}
	else
	{
		printf("testIsValidWeight4Truck  succeed\n\n");
	}
	if (!testIsValidSize())
	{
		ok = 4;
		printf("testIsValidSize  failed\n\n");
	}
	else
	{
		printf("testIsValidSize  succeed\n\n");
	}
	if (!testIsTruckFull())
	{
		ok = 5;
		printf("testIsTruckFull  failed\n\n");
	}
	else
	{
		printf("testIsTruckFull  succeed\n\n");
	}

	return ok;
}
