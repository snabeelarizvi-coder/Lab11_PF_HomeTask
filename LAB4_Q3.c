#include <stdio.h>

int main() {
    float usage;

    // Input
    printf("Enter your monthly water usage (litres): ");
    scanf("%f", &usage);

    if (usage <= 3000) {
        printf("No Fine\n");
    } 
    else if (usage <= 5000) {
        printf("Fine = 200 PKR\n");
    } 
    else if (usage <= 7000) {
        printf("Fine = 500 PKR\n");
    } 
    else {
        printf("Fine = 1000 PKR + Water Supply Restricted\n");
    }

    return 0;
}
