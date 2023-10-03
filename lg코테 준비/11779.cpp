#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dp[1001];
int city[1001];
vector<pair<int, int>> graph[1001];
priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> route_v;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
    }

    for(int i=0; i<=n; i++) {
        dp[i] = 999999999;
    }

    int target_start, target_end;
    cin >> target_start >> target_end;

    dp[target_start] = 0;
    pq.push({ 0, target_start });

    while(!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dp[now] < dist) continue;

        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = graph[now][i].second;

            if(dist + cost < dp[next]) {
                dp[next] = dist + cost;
                city[next] = now;
                pq.push(make_pair( dist + cost, next ));
            }
        }
    }

    int temp = target_end;

    while(temp) {
        route_v.push_back(temp);
        temp = city[temp];
    }

    cout << dp[target_end] << "\n";

    cout << route_v.size() << "\n";

    for(int i=route_v.size() - 1; i>=0; i--) {
        cout << route_v[i] << " ";
    }



}