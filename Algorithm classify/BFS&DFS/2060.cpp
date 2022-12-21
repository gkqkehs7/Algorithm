#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> graph[101];
bool visited[101] = { false };
queue<int> q;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    q.push(1);
    visited[1] = true;
    int count = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i];

            if(visited[next] == false) {
                count++;
                q.push(next);
                visited[next] = true;
            }
        }
    }

    cout << count;
}