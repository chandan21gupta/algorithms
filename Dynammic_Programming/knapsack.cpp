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

int knapsack(int weights[], int values[], int n, int W) {
    int dp[W+1][n+1];
    
    for(int i = 0; i < W+1; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j < n+1; j++) {
        dp[0][j] = 0;
    }

    for(int i = 1; i < W+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(weights[j-1] <= i) {
                dp[i][j] = max(dp[i][j-1], dp[i-weights[j-1]][j-1]+values[j-1]);
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return dp[W][n];
}

int main() {

    
    int W = 6;
    int val[] = {10,15,40};
    int wt[] = {1,2,3};

    cout << knapsack(wt, val, 3, W) << endl;
    return 0;
}