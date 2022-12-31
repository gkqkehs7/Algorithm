#include <iostream>
#include <algorithm>
using namespace std;

int arr[301] = { 0, };
int dp[301] = { 0, };

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    for(int i=3; i<n; i++) {
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]);
    }

    cout << dp[n-1];
}