#include <iostream>
using namespace std;

int edit_distance_problem(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1];
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < m+1; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i < n+1; i++) {
        dp[i][0] = i;
    }

    for(int j = 0; j < m+1; j++) {
        dp[0][j] = j;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1 ; j < m+1; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1+min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main() {

    
    string s1 = "sunday";
    string s2 = "saturday";
    cout << edit_distance_problem(s1,s2) << endl;
    return 0;
}