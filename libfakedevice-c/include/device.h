#ifndef DEVICE_H
#define DEVICE_H

#include <stdbool.h>

/**
 * Turns on the lamp.
 * 
 * This function turns on the lamp and returns a boolean value.
 * @return True.
 * 
 * @note Hazards
 * - Fire
 * - LogEnergyConsumption
 * - EnergyConsumption
 */
bool turnLampOn();

/**
 * Turns off the lamp.
 * 
 * This function turns off the lamp and returns a boolean value.
 * @return False.
 *
 * @note Hazards
 * - LogEnergyConsumption
 */
bool turnLampOff();

#endif // DEVICE_H
