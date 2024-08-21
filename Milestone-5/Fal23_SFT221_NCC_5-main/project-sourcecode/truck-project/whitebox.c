#include "whitebox.h"

// whitebox testing for findTruckForShipment
int FindTruckForShipmentTesting()
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

	// test 1, Positive test: To test if the function functions correctly with valid truck for the shipment
	testCount++;
	struct Shipment shipment1 = { 400, 2, {13, 10} };
	trucks[0].weight = 1000;
	trucks[0].size = 40;

	if (findTruckForShipment(&map, trucks, 3, shipment1) < 0)
	{
		printf("testFindTruckForShipment test %d failed\n", testCount);
		ok = 0;
	}
	trucks[0].weight = 0;
	trucks[0].size = 0;
	// test 2, Positive test: Best truck index should be the one with the shortest distance among valid trucks
	testCount++;
	struct Shipment shipment2 = { 300, 2, {18, 14} };
	trucks[0].weight = 1000;
	trucks[0].size = 30;
	if (findTruckForShipment(&map, trucks, 3, shipment2) == -1)
	{
		printf("testFindTruckForShipment test %d failed\n", testCount);
		ok = 0;
	}
	trucks[0].weight = 0;
	trucks[0].size = 0;
	// test 3, Negative test: To test the case that no valid truck is available
	testCount++;
	struct Shipment shipment3 = { 100, 2, {18, 14} };
	trucks[0].weight = 1500;
	trucks[0].size = 48;
	trucks[1].weight = 1500;
	trucks[1].size = 48;
	if (findTruckForShipment(&map, trucks, 2, shipment3) != -1)
	{
		printf("testFindTruckForShipment test %d failed\n", testCount);
		ok = 0;
	}
	return ok;
}
// whitebox testing for isValidVolume
int IsValidSize4TruckTesting()
{	
	int ok = 1;

	struct Point pos = { 0, 0 };
	struct Truck truck;
	truck.weight = 0;
	truck.route = getBlueRoute();

	int testCount = 0;

	// test 1, Positive test: Valid size addition to the truck
	testCount++;
	truck.size = 40;
	if (!IsValidSize4Truck(truck, 2))
	{
		printf("testIsValidSize4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 2, Edge case: Size addition equal to the truck's limit
	testCount++;
	truck.size = 47;
	if (!IsValidSize4Truck(truck, 1))
	{
		printf("testIsValidSize4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 3, Out of boundary test: boxSize doesn’t fit, negative result should be returned
	testCount++;
	truck.size = 47;
	if (IsValidSize4Truck(truck, 2))
	{
		printf("testIsValidSize4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 4, Postive test: Size addition equal to the maximum limit
	testCount++;
	truck.size = 46;
	if (!IsValidSize4Truck(truck, 2))
	{
		printf("testIsValidSize4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 5, Negative test: Size addition exceeding the maximum limit
	testCount++;
	truck.size = 48;
	if (IsValidSize4Truck(truck, 2))
	{
		printf("testIsValidSize4Truck test %d failed\n", testCount);
		ok = 0;
	}
	return ok;
}
// whitebox testing for isValidWeight
int IsValidWeight4TruckTesting()
{
	int ok = 1;

	struct Point pos = { 0, 0 };
	struct Truck truck;
	truck.size = 0;
	truck.route = getBlueRoute();

	int testCount = 0;

	// test 1, Positive test: Valid weight addition to the truck
	testCount++;
	truck.weight = 1000;
	if (!IsValidWeight4Truck(truck, 200))
	{
		printf("IsValidWeight4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 2, Edge case: Weight addition equal to the truck's limit
	testCount++;
	truck.weight = 1400;
	if (!IsValidWeight4Truck(truck, 100))
	{
		printf("IsValidWeight4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 3, Negative case: Weight addition exceeding the truck's limit
	testCount++;
	truck.weight = 1400;
	if (IsValidWeight4Truck(truck, 200))
	{
		printf("IsValidWeight4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 4, Positive test: Weight addition equal to the maximum limit
	testCount++;
	truck.weight = 1499;
	if (!IsValidWeight4Truck(truck, 1))
	{
		printf("IsValidWeight4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 5, Negative test: Weight addition exceeding the maximum limit
	testCount++;
	truck.weight = 1500;
	if (IsValidWeight4Truck(truck, 100))
	{
		printf("IsValidWeight4Truck test %d failed\n", testCount);
		ok = 0;
	}

	return ok;
}
// whitebox testing for isValidSize
int IsValidSizeTesting()
{
	int ok = 1;

	int testCount = 0;

	// test 1, Positive test: Valid standard box size
	testCount++;
	if (!IsValidSize(1))
	{
		printf("IsValidWeight4Truck test %d failed\n", testCount);
		ok = 0;
	}

	// test 2, Positive test: Invalid non-standard box size
	testCount++;
	if (IsValidSize(0.75))
	{
		printf("IsValidWeight4Truck test %d failed\n", testCount);
		ok = 0;
	}

	return ok;
}
// whitebox testing for isTruckFull
int IsTruckFullTesting()
{
	int ok = 1;

	struct Point pos = { 0, 0 };
	struct Truck truck;
	truck.route = getBlueRoute();

	int testCount = 0;

	// test 1, Negative test: Truck not full
	testCount++;
	truck.weight = 1000;
	truck.size = 40;
	if (IsTruckFull(truck))
	{
		printf("IsTruckFull test %d failed\n", testCount);
		ok = 0;
	}

	// test 2, Positive test: Truck full due to weight exceeding limit
	testCount++;
	truck.weight = 1500;
	truck.size = 40;
	if (!IsTruckFull(truck))
	{
		printf("IsTruckFull test %d failed\n", testCount);
		ok = 0;
	}

	// test 3, Positive test: Truck full due to size exceeding limit
	testCount++;
	truck.weight = 1000;
	truck.size = 48;
	if (!IsTruckFull(truck))
	{
		printf("IsTruckFull test %d failed\n", testCount);
		ok = 0;
	}

	// test 4, Positive test: Truck full due to both weight and size
	testCount++;
	truck.weight = 1500;
	truck.size = 48;
	if (!IsTruckFull(truck))
	{
		printf("IsTruckFull test %d failed\n", testCount);
		ok = 0;
	}
	return ok;
}

int main()
{
	if (!FindTruckForShipmentTesting())
	{
		printf("FindTruckForShipmentTesting  failed\n");
	}
	else {
		printf("FindTruckForShipmentTesting  succeeded\n");
	}
	if (!IsValidSize4TruckTesting())
	{
		printf("IsValidSize4TruckTesting  failed\n");
	}
	else {
		printf("IsValidSize4TruckTesting  succeeded\n");
	}
	if (!IsValidWeight4TruckTesting())
	{
		printf("IsValidWeight4TruckTesting  failed\n");
	}
	else {
		printf("IsValidWeight4TruckTesting  succeeded\n");
	}
	if (!IsValidSizeTesting())
	{
		printf("IsValidSizeTesting  failed\n");
	}
	else {
		printf("IsValidSizeTesting  succeeded\n");
	}
	if (!IsTruckFullTesting())
	{
		printf("IsTruckFullTesting  failed\n");
	}
	else {
		printf("IsTruckFullTesting  succeeded\n");
	}
	return 0;
}
