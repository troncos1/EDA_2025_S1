#ifndef PROCESSOR_H
#define PROCESSOR_H

typedef struct {
    char city_name[1000];     // Name of the city
    int seismic_level;      // Seismic level (1-5)
    float risk_percent;     // Risk percentage (if available)
    int original_index;     // Original position in the input file
    int has_risk_percent;   // Flag indicating if risk_percent is available
} CityData;

CityData* read_and_process_file(const char *filename, int *total);
void write_output(const char *filename, CityData *cities, int total, int n);

#endif