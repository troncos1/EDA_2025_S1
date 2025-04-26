#include <stdio.h>
#include <stdlib.h>
#include "modules/processor.h"
#include "modules/sorter.h"

/**
 * Main function - Entry point of the program
 * 
 * This program processes seismic data of cities from a CSV file,
 * sorts them based on seismic risk priority criteria and outputs
 * the top N cities to an output file.
 * 
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return 0 on success, 1 on failure
 */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <input.csv> <N_Cities> <output.txt>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    int N = atoi(argv[2]);
    const char *output_file = argv[3];

    int total_cities = 0;
    CityData *cities = read_and_process_file(input_file, &total_cities);
    if (!cities) return 1;

    quicksort(cities, 0, total_cities - 1);
    write_output(output_file, cities, total_cities, N);

    free(cities);
    return 0;
}