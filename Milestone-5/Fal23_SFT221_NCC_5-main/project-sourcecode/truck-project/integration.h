#ifndef INTEGRATION_H
#define INTEGRATION_H

#include "shipment.h"
#include "truck.h"
#include "mapping.h"
// Add blue truck route to base map
int t01();
// Add green truck route to base map
int t02();
// Add yellow truck route to base map
int t03();
// Add all the three truck routes to base map
int t04();
// Calculate distance for the shortest path
int t05();
// Calculate distance for an invalid path
int t06();
// Calculate distance for an empty path
int t07();
// Calculate distance with invalid parameters
int t08();
// Calculate distance for the closest route
int t09();
// Calculate distance for an invalid route
int t10();
// Calculate distance for an empty route
int t11();
// Calculate distance with invalid parameters
int t12();
// Identify possible moves and add points to the route
int t13();
// Add points to an existing route
int t14();
// Check if a point exists in the route
int t15();
// Add a point to the route only if it doesn't exist
int t16();

#endif