#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <stdbool.h>
#include "processor.h"

bool validate_city(int fields, CityData *city, const char *risk_str);

#endif