#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
using namespace std;

bool visited[17];
vector<pair<int, int>> graph[17];
int ans = MAX;



void dfs(int start, int now, int depth, int cost_sum) {
    
    if (depth == 4) {
        if(graph[now][start-1].second != 0) {
            ans = min(ans, cost_sum + graph[now][start-1].second);
        }
        
        return;
    }

    for (int i = 0; i < graph[now].size(); i++) {
        
        int next = graph[now][i].first;
        int cost = graph[now][i].second;
        if (visited[next] == false && cost != 0) {
            visited[next] = true;
            dfs(start, next, depth + 1, cost_sum + cost);
            visited[next] = false;
        }

    }
}

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
            cin >> cost;

            graph[i].push_back({ j, cost });
        }
    }

    for(int j=0; j<17; j++) visited[j] = false;

    dfs(1,1,1,0);
    // for (int i = 1; i <= n; i++) {
    //     visited[i] = true;
    //     dfs(i, i, 1, 0);

    //     for(int j=0; j<17; j++) visited[j] = false;
    // }
    cout << ans;

}