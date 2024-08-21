#pragma once
#ifndef WHITEBOX_H
#define WHITEBOX_H

#include <stdio.h>
#include <assert.h>
#include "truck.h"
#include "shipment.h"

// whitebox testing for findTruckForShipment
int FindTruckForShipmentTesting();
// whitebox testing for isValidVolume
int IsValidSize4TruckTesting();
// whitebox testing for isValidWeight
int IsValidWeight4TruckTesting();
// whitebox testing for isValidSize
int IsValidSizeTesting();
// whitebox testing for isTruckFull
int IsTruckFullTesting();

#endif