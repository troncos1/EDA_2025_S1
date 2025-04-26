#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processor.h"
#include "validator.h"  // Added this include to fix the implicit declaration warning

CityData* read_and_process_file(const char *filename, int *total) {
    // Open the input file
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error abriendo el archivo");
        return NULL;
    }

    // Allocate memory for city data (max 1500 cities)
    CityData *cities = malloc(sizeof(CityData) * 1500);
    int count = 0;
    char line[128];
    
    // Skip header line
    fgets(line, sizeof(line), file);

    // Process each line of the CSV file
    while (fgets(line, sizeof(line), file)) {
        CityData city;
        char risk_str[20] = "";
        
        // Handle comma-separated values
        char *token = strtok(line, ",");
        if (!token) continue;  // Skip if line is empty
        
        // Get city name (first column)
        strncpy(city.city_name, token, sizeof(city.city_name) - 1);
        city.city_name[sizeof(city.city_name) - 1] = '\0';
        
        // Get seismic level (second column)
        token = strtok(NULL, ",");
        if (!token) continue;  // Skip if seismic level is missing
        city.seismic_level = atoi(token);
        
        // Get risk percent (third column, optional)
        token = strtok(NULL, ",\n");
        int fields = 2;
        if (token && *token) {
            strncpy(risk_str, token, sizeof(risk_str) - 1);
            risk_str[sizeof(risk_str) - 1] = '\0';
            fields = 3;
        }

        // Validate the city data
        if (!validate_city(fields, &city, risk_str)) continue;

        // Store the city data in the array
        city.original_index = count;
        cities[count++] = city;
    }

    fclose(file);
    *total = count;  // Update the total count of valid cities
    return cities;
}

void write_output(const char *filename, CityData *cities, int total, int n) {
    FILE *out = fopen(filename, "w");
    if (!out) {
        perror("Error abriendo archivo de salida");
        return;
    }

    fprintf(out, "city_name seismic_level risk_percent\n");
    for (int i = 0; i < n && i < total; ++i) {
        if (cities[i].has_risk_percent)
            fprintf(out, "%s %d %.1f\n", cities[i].city_name, cities[i].seismic_level, cities[i].risk_percent);
        else
            fprintf(out, "%s %d\n", cities[i].city_name, cities[i].seismic_level);
    }
    fclose(out);
}