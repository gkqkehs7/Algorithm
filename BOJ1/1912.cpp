#include <iostream>
#include <algorithm>
using namespace std;



int arr[100001] = { 0, };
int dp[100001] = { 0, }; // 나 자신까지 더했을때의 최댓값?

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }

   
    dp[0] = arr[0];
    int ans = arr[0];

    for(int i=1; i<n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]); // 지금 pointer가 가리키는 값이 더 크다면, 이전의 값들은 모두 사라진다.

        if(ans < dp[i]) {
            ans = dp[i];
        }   
    }

    cout << ans;
}   