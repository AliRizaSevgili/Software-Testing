#ifndef BLACKBOX_H
#define BLACKBOX_H

#include <stdio.h>
#include <assert.h>
#include "truck.h"
#include "shipment.h"

// blackbox testing for findTruckForShipment
int testFindTruckForShipment();
// blackbox testing for isValidVolume
int testIsValidSize4Truck();
// blackbox testing for isValidWeight
int testIsValidWeight4Truck();
// backbox testing for isValidSize
int testIsValidSize();
// blackbox testing for isTruckFull
int testIsTruckFull();

#endif