#include <iostream>
using namespace std;

int knapsack_repetition(int weights[], int values[], int n, int W) {
    int dp[W+1];
    for(int i = 0; i < W+1; i++) {
        dp[i] = 0;
    }
    for(int i = 1; i < W+1; i++) {
        for(int j = 0; j < n; j++) {
            if(weights[j] <= i)
                dp[i] = max(values[j]+dp[i-weights[j]], dp[i]);
        }
    }

    return dp[W];
}

int main() {

    
    int W = 50;
    int val[] = {60,100,120};
    int wt[] = {10,20,30};

    cout << knapsack(wt, val, 3, W) << endl;
    return 0;
}