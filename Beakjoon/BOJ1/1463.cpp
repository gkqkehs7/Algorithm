#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int branch(int n) {
    if(n == 1) {
        return 0;
    }
    if(dp[n] != -1) return dp[n];

    dp[n] = branch(n-1) + 1;
    if(n % 3 == 0) {
        int temp = branch(n/3) + 1;
        if(dp[n] > temp) dp[n] = temp;
    } 
    if(n % 2 == 0) {
        int temp = branch(n/2) + 1;
        if(dp[n] > temp) dp[n] = temp;
    }

    return dp[n];
} 

int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<1000001; i++) {
        dp[i] = -1;
    }
    
    cout << branch(n);

}       