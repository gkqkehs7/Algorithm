#include <iostream>
#include <algorithm>
using namespace std;
int card[1001] = { 0, };
int dp[1001][1001] = { 0, };


int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        int input;
        cin >> input;
        card[i] = input;
    }


    for(int i=1; i<n; i++) {
        dp[1][i] = card[1] * i;
    }

    for(int i=2; i<=n; i++) {
        for(int j=i; j<n; i++) {
            dp[i][j] = max(dp[i-1][j] + card[i-1], dp[i][j]);
        }
    }
}