#include <iostream>
using namespace std;

long long dp[1010][10] = { 0, };
int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<10; i++) {
        dp[1][i] = 1;
    }


    // 0 _ _  -> 두자리에서 0 _ ~ 9 _ 의 개수와 같다
    // 1 _ _  -> 두자리에서 1 _ ~ 9 _ 의 개수와 같다

    //         | 0 1 2 3 4 5 6 7 8 9
    // ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    // 자리수 1  | 1 1 1 1 1 1 1 1 1 1
    // 자리수 2  | 10 9 8 7 6 5 4 3 2 1
    // 자리수 3  | 55 46 38 ....
    // 자리수 4  |
    for(int i=2; i<1010; i++) {
        for(int j=0; j < 10; j++) {
            long long sum = 0;
            for(int k=j; k < 10; k++) {
                sum += dp[i-1][k];
            }
            dp[i][j] = sum % 10007;
        }
    }

    cout << dp[n+1][0];
}