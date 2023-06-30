#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    int *arr = new int[T];
    int dp[11] = { 0 };
    for(int i=0; i<T; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i=4; i<11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    for(int i=0; i<T; i++) {
       cout << dp[arr[i]] << "\n";
    }
}