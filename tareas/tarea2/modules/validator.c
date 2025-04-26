#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validator.h"
#include "processor.h"

bool validate_city(int fields, CityData *city, const char *risk_str) {
    // Validate basic requirements
    // - At least city name and seismic level must be present
    // - Seismic level must be between 1 and 5
    if (fields < 2 || city->seismic_level < 1 || city->seismic_level > 5) return false;

    // Handle risk percentage
    if (fields == 3 && strlen(risk_str) > 0) {
        // Risk percentage is present
        city->risk_percent = atof(risk_str);
        city->has_risk_percent = 1;
    } else {
        // Risk percentage is missing
        city->risk_percent = -1.0f;  // Set to invalid value
        city->has_risk_percent = 0;  // Mark as not having risk percentage
    }
    
    return true;
}