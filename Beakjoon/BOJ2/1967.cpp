#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> graph[10001];
vector<int> childs;
int degree[10001]; 
bool visited[10001];
int max_cost = 0;

void dfs(int now, int cost) {

    max_cost = max(max_cost, cost);
    for(int i=0; i<graph[now].size(); i++) {
        int next = graph[now][i].first;
        int next_cost = graph[now][i].second;

        if(visited[next] == false) {
            visited[next] = true;
            dfs(next, cost + next_cost);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<10001; i++) degree[i] = 0;

    for(int i=0; i<n - 1; i++) {
        int parent, child, edge;
        cin >> parent >> child >> edge;

        degree[parent]++;
        graph[parent].push_back({ child, edge });
        graph[child].push_back({ parent, edge });
    }
    
    for(int i=1; i<=n; i++) {
        if(degree[i] == 0) childs.push_back(i);
    }   

    for(int i=0; i<childs.size(); i++) {
        for(int i=0; i<10001; i++) visited[i] = false;
        visited[childs[i]] = true;
        dfs(childs[i], 0);
    }

    cout << max_cost;
}