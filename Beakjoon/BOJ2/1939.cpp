#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> graph[10001];
bool visited[10001];

void Init() {
	for (int i = 1; i <= 10001; i++) {
		visited[i] = false;
	}
}

int bfs(int start, int end, int limit) {
    Init();

    queue<int> q;

    visited[start] = true;

    q.push(start);
    
    while(!q.empty()) {
        int now = q.front();

        q.pop();

        if(now == end) {
            return true;
        }

        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = graph[now][i].second;

            if(cost <= limit && visited[next] == false) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    int max_cost;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));

        max_cost = max(max_cost, c);
    }

    int start, end;
    cin >> start >> end;

    int left = 0;
    int right = max_cost;

    while(left <= right) {

        int mid = (left + right) / 2;
        
        if(bfs(start, end, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right;

    return 0;
} 