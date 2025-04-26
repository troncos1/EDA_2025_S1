#include <string.h>
#include "sorter.h"

int compare(const CityData *a, const CityData *b) {
    // First compare by seismic level (higher = higher priority)
    if (a->seismic_level != b->seismic_level)
        return b->seismic_level - a->seismic_level;

    // If both have risk percentage, compare by risk percentage
    if (a->has_risk_percent && b->has_risk_percent) {
        if (a->risk_percent != b->risk_percent)
            return (b->risk_percent > a->risk_percent) ? 1 : -1;
    } 
    // If only one has risk percentage, apply special handling
    else if (a->has_risk_percent != b->has_risk_percent) {
        int level = a->seismic_level;
        
        // Position priority based on seismic level for cities missing risk percentage
        // pos = 0: high priority (start of category)
        // pos = 1: medium priority (middle of category)
        // pos = 2: low priority (end of category)
        int pos_a = a->has_risk_percent ? 0 : (level == 3 ? 1 : (level >= 4 ? 0 : 2));
        int pos_b = b->has_risk_percent ? 0 : (level == 3 ? 1 : (level >= 4 ? 0 : 2));
        
        if (pos_a != pos_b) return pos_a - pos_b;
    }

    // If still tied, use reverse alphabetical order (Z-A)
    return -strcmp(a->city_name, b->city_name);
}

/**
 * Implements QuickSort algorithm to sort cities by priority
 * 
 * @param cities Array of city data structures
 * @param low Starting index of the subarray to sort
 * @param high Ending index of the subarray to sort
 */
void quicksort(CityData *cities, int low, int high) {
    if (low < high) {
        // Choose pivot and partition the array
        CityData pivot = cities[high];
        int i = low - 1;
        
        // Partition array around pivot
        for (int j = low; j < high; j++) {
            if (compare(&cities[j], &pivot) < 0) {
                i++;
                // Swap cities[i] and cities[j]
                CityData tmp = cities[i];
                cities[i] = cities[j];
                cities[j] = tmp;
            }
        }
        
        // Swap pivot to its final position
        CityData tmp = cities[i + 1];
        cities[i + 1] = cities[high];
        cities[high] = tmp;

        // Recursively sort the subarrays
        quicksort(cities, low, i);           // Sort left subarray
        quicksort(cities, i + 2, high);      // Sort right subarray
    }
}