#include <stdio.h>
#include <stdlib.h>

// Function to calculate maximum profit
int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0]; //initialise to first element
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i]; //update minimum price
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice; //update max profit by checking each time (if this element - min price gives greater profit)
        }
    }

    return maxProfit; 
}

int main() {
    int pricesSize;
    printf("Enter number of days: ");
    scanf("%d", &pricesSize);

    int* prices = (int*)malloc(pricesSize * sizeof(int));
    if (prices == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter prices for each day:\n");
    for (int i = 0; i < pricesSize; i++) {
        scanf("%d", &prices[i]);
    }

    int profit = maxProfit(prices, pricesSize);
    printf("Maximum Profit: %d\n", profit);

    free(prices);
    return 0;
}
