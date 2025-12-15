#include <stdio.h>

int maximizeTip(int tips[], int n, int currentIndex) {
    if (currentIndex >= n)
        return 0; 

    int deliver = tips[currentIndex] + maximizeTip(tips, n, currentIndex + 2);

    int skip = maximizeTip(tips, n, currentIndex + 1);

    return (deliver > skip) ? deliver : skip;
}

int main() {
    int n;

    printf("Enter number of delivery stops: ");
    scanf("%d", &n);

    int tips[n];
    printf("Enter tip amount at each stop:\n");
    for (int i = 0; i < n; i++) {
        printf("Stop %d: ", i + 1);
        scanf("%d", &tips[i]);
    }

    int maxTip = maximizeTip(tips, n, 0);
    printf("\nMaximum total tip the rider can collect: %d\n", maxTip);

    return 0;
}

