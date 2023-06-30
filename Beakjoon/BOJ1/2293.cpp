#include <iostream>
using namespace std;

int coin[101] = { 0, };
long long dp[101] = { 0, };

int main() {
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        coin[i] = input;
    }

    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }


}