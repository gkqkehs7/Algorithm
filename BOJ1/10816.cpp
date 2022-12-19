#include <iostream>
using namespace std;

int main() {
    int n,m;

    int dp[20000002] = {0};
    int *toknow = new int[m];

    cin >> n;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;

        dp[input + 10000000]++;
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        int input;
        cin >> input;
        toknow[i] = input;
    }

    for(int i=0; i<m; i++) {
        int input;
        cin >> input;
        cout << dp[toknow[input] + 10000000] << " ";
    }
}