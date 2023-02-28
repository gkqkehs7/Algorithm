#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int dp[41];
int main() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<41; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    if(m == 0) {
        cout << dp[n];
    } else {
        for(int i=0; i<m; i++) {
            int input;
            cin >> input;
            v.push_back(input);
        }

        if(v[v.size() - 1] != n) v.push_back(n + 1);
        


        int prev = 0;
        int ans = 1;
        for(int i=0; i < v.size(); i++) {

            ans = ans * dp[v[i] - prev - 1];
            prev = v[i];
        }

        cout << ans;
    }
    
}