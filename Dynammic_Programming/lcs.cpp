#include <iostream>
using namespace std;

int lcs_problem(int arr[], int n) {
    int dp[n];
    dp[0] = 1;
    for(int i = 1 ; i < n; i++) {
        dp[i] = 1;
    }
    for(int i = 1; i < n; i++) {
        int current_max = dp[i];
        for(int j = 0; j < i; j++) {
            if(arr[i] >= arr[j] && dp[j]+1 > current_max)
                current_max = dp[j]+1;
        }
        dp[i] = current_max;
    }

    return dp[n-1];
}

int main() {
    int arr[] = {50, 3, 10, 7, 40, 80};
    cout << lcs_problem(arr, 6) << endl;
    return 0;
}