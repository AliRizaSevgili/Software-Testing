#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "mapping.h"

struct Shipment
{
    /// @brief in kg
    int weight;
    /// @brief cubic meters
    double boxSize;
    /// @brief Destination
    struct Point destination;
};

#endif