#include <iostream>
#include <algorithm>
using namespace std;


int temp(int start, int end) {

    int res = 0;
    for(int i = start; i < end; i++) {
        res = min(res, temp(start, i) + temp(i + 1, end));
    }
    return res;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        int arr[501];
        int dp[501][501];
       
        arr[0] = 0;
        for(int i=1; i<=n; i++) {
            int input;
            cin >> input;
            arr[i] = arr[i-1] + input;
        }

        for(int i=0; i<501; i++) {
            for(int j=0; j<501; j++) {
                dp[i][j] = 1000000000;
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=i; j<n; j++) {
                dp[i][j] = dp[i][]
            }
            
        }

        for(int i=0; i<n; i++) {
            cout << dp[i] << " ";
        }
    }
}