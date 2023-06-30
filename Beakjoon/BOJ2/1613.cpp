#include <iostream>
#include <vector>
using namespace std;
int dp[401][401];
vector<pair<int, int>> ans;

int main() {
    int n,k,s;
    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = -1;
        }
    }

    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 1;
        dp[b][a] = 2;
    }

    cin >> s;
    for(int i=0; i<s; i++) {
        int a, b;
        cin >> a >> b;
        ans.push_back({ a, b });
    }


    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dp[i][k] == 1 && dp[k][j] == 1) {
                    dp[i][j] = 1;
                }

                if(dp[i][k] == 2 && dp[k][j] == 2) {
                    dp[i][j] = 2;
                }
            }
        }
    }

    for(int i=0; i<ans.size(); i++) {
        int target1 = ans[i].first;
        int target2 = ans[i].second;

        if(dp[target1][target2] == 1) {
           cout << -1 << "\n";
        } else if(dp[target1][target2] == 2) {
            cout << 1 << "\n";    
        } else if(dp[target1][target2] == -1) {
            cout << 0 << "\n"; 
        }
    }

}