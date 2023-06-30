#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 2100000000
long long dp[501];

vector<pair<int, int>> graph[501];

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i < 501; i++) {
        dp[i] = INF;
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }

    dp[1] = 0;
    bool cycle = false;
    for(int i=1; i <= n; i++) {
        for(int j=1; j <= n; j++) {
            int now = j;

            for(int k=0; k<graph[j].size(); k++) {
                int next = graph[j][k].first;
                int dis = graph[j][k].second;

                if(dp[now] != INF && dp[next] > dp[now] + dis) {
                    dp[next] = dp[now] + dis;
                    if(i == n) cycle = true;
                }
            }  
        }
    }

    if(cycle) cout << -1 << "\n";
    else {
        for(int i=2; i <= n; i++) {
            cout << ( dp[i] == INF ? -1 : dp[i] ) << "\n";
        }
    }

}