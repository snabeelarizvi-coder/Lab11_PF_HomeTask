#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char cityName[50];
    float baseTemp;
    float coolingFactor;
} WeatherData;

void simulateTemperature(WeatherData *w, int currentDay, int totalDays, float prevTemp) {
    if (currentDay > totalDays)
        return;

    float variation = ((rand() % 401) - 200) / 100.0; // -2.00 to +2.00

    float newTemp = prevTemp + variation - w->coolingFactor;

    printf("Day %d: Temperature = %.2f°C\n", currentDay, newTemp);

    simulateTemperature(w, currentDay + 1, totalDays, newTemp);
}

int main() {
    srand(time(0)); 

    WeatherData w;
    int nDays;

    printf("Enter city name: ");
    scanf(" %[^\n]", w.cityName);

    printf("Enter base temperature (°C): ");
    scanf("%f", &w.baseTemp);

    printf("Enter cooling factor (°C/day): ");
    scanf("%f", &w.coolingFactor);

    printf("Enter number of days to simulate: ");
    scanf("%d", &nDays);

    printf("\n--- Weather Forecast for %s ---\n", w.cityName);
    simulateTemperature(&w, 1, nDays, w.baseTemp);

    return 0;
}

