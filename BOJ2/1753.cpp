    #include <iostream>
    #include <string.h>
    #include <vector>
    #include <queue>
    using namespace std;

    int dp[20001];
    vector<pair<int,int>> graph[20001];
    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    int main() {
        int v, e, start;
        cin >> v >> e >> start;
        for(int i=0; i<20001; i++) {
            dp[i] = 1000000000;
        }
        
        for(int i=0; i<e; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back({ b, w });
        }

        pq.push(make_pair( 0, start ));
        dp[start] = 0;

        while(!pq.empty()) {
            
            int dist = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if(dp[now] < dist) continue;

            for(int i=0; i<graph[now].size(); i++) {
                int next = graph[now][i].first;
                int cost = dist + graph[now][i].second;

                if(cost < dp[next]) {
                    dp[next] = cost;
                    pq.push(make_pair( cost, next ));
                }
                
            }
        }

        for(int i=1; i <= v; i++) {
            if(dp[i] == 1000000000) {
                cout << "INF" << "\n"; 
            } else {
                cout << dp[i] << "\n";
            }
        }
    }