#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dp[1001];
vector<pair<int, int>> graph[1001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

int main() {
    int n, m, start, end;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }
    cin >> start >> end;

    for(int i=0; i<1001; i++) {
        dp[i] = 1000000000;
    }

    pq.push({ 0, start });
    dp[start] = 0;

    while(!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dp[now] < dist) continue;

        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = graph[now][i].second + dist;
            
            if(dp[next] > cost) {
                dp[next] = cost;
                pq.push({ cost, next });
            } 
        }
    }

    cout << dp[end];

}