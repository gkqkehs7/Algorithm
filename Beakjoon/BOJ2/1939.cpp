#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
int n, m, start_land, desti;
vector<pair<int ,int>> graph[10001];
bool visited[10001] = { false, };

int answer = 0;
int max_wei = 0;
int min_limit = 1000000001;

bool bfs(int now, int limit) {
    queue<int> q;
    q.push(now);
    while(!q.empty()) {
        if(q.front() == desti) return true;
        q.pop();

        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].first;
            if(visited[next] == false && graph[now][i].second >= limit) {
                visited[next] = true;
                q.push(next);
            }
        }   
    }
    
    return false;
}
// void dfs(int now, int limit) {
//     if(now == desti) {
//         cango = true;
//         return;
//     }

//     for(int i=0; i<graph[now].size(); i++) {
//         int next = graph[now][i].first;
//         if(visited[next] == false && graph[now][i].second >= limit) {
//             if(graph[now][i].second < min_limit) {
//                 min_limit = graph[now][i].second;
//             }
//             visited[next] = true;
//             dfs(next, limit);
//         }
//     }
// }

void binary_search(int start, int end) {
    if(start > end) return;

    int mid = (start + end) / 2;

    // dfs(start_land, mid);
    if(bfs(start_land, mid)) {
        answer = mid;
        binary_search(mid + 1, end);
        memset(visited, false, sizeof(visited));
    } else {
        answer = mid;
        binary_search(start , mid - 1);
        memset(visited, false, sizeof(visited));
    }
    

    // if(cango) {
    //     if(min_limit > answer) answer = min_limit;
    //     min_limit = 1000000001;
    //     binary_search(mid + 1, end);
    //     cango = false;
    // } else {
    //     min_limit = 1000000001;
    //     binary_search(start , mid - 1);
    // }
}

int main() { 
    cin >> n >> m;


    for(int i=0; i<m; i++) {
        int a, b, wei;
        cin >> a >> b >> wei;
        
        if(wei > max_wei) {
            max_wei = wei;
        }
        graph[a].push_back({ b, wei });
        graph[b].push_back({ a, wei });
    }
    cin >> start_land >> desti;

    binary_search(0, max_wei);
    cout << answer;
}