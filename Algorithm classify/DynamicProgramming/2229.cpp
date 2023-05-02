#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<1001; i++) dp[i] = 0;

    for(int i=1; i<=n; i++) {
        
       for(int j=1; j<=i; j++) {
            int max_value = 0;
            int min_value = 100001;

            for(int k = 0; k < j; k++) {
                int temp = arr[i - k];
                max_value = max(max_value, temp);
                min_value = min(min_value, temp);
            }

            dp[i] = max(dp[i], dp[i-j] + (max_value - min_value));
       }
    }
    

    cout << dp[n];
}