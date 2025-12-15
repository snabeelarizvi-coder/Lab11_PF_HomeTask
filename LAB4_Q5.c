#include <stdio.h>

int main() {
    int members;
    float usage;

    // Input
    printf("Enter number of family members: ");
    scanf("%d", &members);

    printf("Enter monthly water usage (litres): ");
    scanf("%f", &usage);

    if (usage > 3000) {
        if (members > 6) {
            printf("Allowed: Large Family Exception\n");
        } else {
            printf("Fine Applied\n");
        }
    } else {
        printf("Usage within limit. No Fine\n");
    }

    return 0;
}
