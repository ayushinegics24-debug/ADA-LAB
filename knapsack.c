#include <stdio.h>


struct Item {
    int value, weight;
    float ratio;
};

void sort(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                struct Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter values and weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);


    sort(arr, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {

            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {

            totalValue += arr[i].ratio * W;
            break;
        }
    }

    printf("Maximum value (Fractional Knapsack) = %.2f\n", totalValue);

    return 0;
}




