#include <stdio.h>
#include <math.h>

typedef struct {
    int ID;
    int initialHeight;
    float growthRate;
} Building;

int computeHeight(Building *b, int day) {
    if (day == 0)
        return b->initialHeight;

    int prevHeight = computeHeight(b, day - 1);
    int newHeight = prevHeight + (int)floor(prevHeight * b->growthRate);
    return newHeight;
}

void updateBuildingHeight(Building *b, int day) {
    b->initialHeight = computeHeight(b, day);
}

int main() {
    Building b;

    printf("Enter Building ID: ");
    scanf("%d", &b.ID);

    printf("Enter initial height (meters): ");
    scanf("%d", &b.initialHeight);

    printf("Enter daily growth rate (e.g., 0.05 for 5%%): ");
    scanf("%f", &b.growthRate);

    int day;
    printf("Enter day number to simulate: ");
    scanf("%d", &day);

    int heightOnDay = computeHeight(&b, day);
    printf("\nHeight of Building %d on day %d: %d meters\n", b.ID, day, heightOnDay);

    updateBuildingHeight(&b, day);
    printf("Updated Building initial height: %d meters\n", b.initialHeight);

    return 0;
}
