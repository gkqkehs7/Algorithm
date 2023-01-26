#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, start, target;
vector<pair<int ,int>> graph[10001];
int dp[10001][10001] = { 0, };
bool visited[10001] = { false, };

int answer = 0;
void dfs(int now, int wei) {
    cout << now << " " << wei << "\n";
    if(now == target) {
        if(wei > answer) {
            answer = wei;
        }
        return;
    }

    for(int i=0; i<graph[now].size(); i++) {
        int next = graph[now][i].first;
        if(dp[now][next] == graph[now][i].second) {
            if(graph[now][i].second < wei) {
                visited[next] = true;
                dfs(next, graph[now][i].second);
                visited[next] = false;
            } else {
                visited[next] = true;
                dfs(next, wei);
                visited[next] = false;
            }
        }
        
    } 
}

int main() {
    cin >> n >> m;


    for(int i=0; i<m; i++) {
        int a, b, wei;
        cin >> a >> b >> wei;
        
        if(wei > dp[a][b]) {
            dp[a][b] = wei;
            dp[b][a] = wei;
        }
        graph[a].push_back({ b, wei });
        graph[b].push_back({ a, wei });
    }


    cin >> start >> target;

    visited[start] = true;
    dfs(start, 1000000001);

    cout << answer;
}