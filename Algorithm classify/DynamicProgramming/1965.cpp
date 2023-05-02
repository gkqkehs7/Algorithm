#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
    int n;
    cin >> n;

    for(int i=0; i<1001; i++) dp[i] = 1;

    for(int i=0; i<n; i++) cin >> arr[i];

    int max_ans = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
           if(arr[i] > arr[j]) {
                
                dp[i] = max(dp[i], dp[j] + 1);
           }
        }
    }

    for(int i=0; i<n; i++) {
        max_ans = max(max_ans, dp[i]);
    }
    cout << max_ans;

}

 