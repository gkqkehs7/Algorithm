#include <iostream>
#include <vector>
using namespace std;

vector <int> v[101];
int dist[101] = { 0 };
bool visited[101] = {false};
int cnt = 0;

void dfs(int start) {
    cnt++;    
    for(int i=0; i<v[start].size(); i++) {
        int next = v[start][i];

        if(visited[next] == false) {
            dist[next] = dist[start] + 1;
            visited[next] = true;
            dfs(next);
        } 
    }
}

int main() {
    int n;
    int t1, t2;
    int m;

    cin >> n;
    cin >> t1 >> t2;
    cin >> m;

    for(int i=0; i<m; i++) {
        int c, p;
        cin >> p >> c;
        v[p].push_back(c);
        v[c].push_back(p);
    }

    visited[t1] = true;
    dfs(t1);

    if(dist[t2] == 0) {
        cout << -1;
    } else {
        cout << dist[t2];
    }

}