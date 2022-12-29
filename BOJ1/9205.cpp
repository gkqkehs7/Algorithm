#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int house_x, house_y;
        int target_x, target_y;
        vector<pair<int, int>> v;
        vector<int> graph[150];
        bool visited[150];
        queue<int> q;

        for(int i=0; i<150; i++) {
            visited[i] = false;
        }
    
        for(int i=0; i<n + 2; i++) {
            int a,b;
            cin >> a >> b;
            v.push_back({ a, b });
        }

        for(int i=0; i<v.size(); i++) {
            for(int j = i+1; j<v.size(); j++) {
                if(( abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)) <= 1000 ) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        q.push(0);
        visited[0] = true;
        bool cango = false;
        int answer = v.size() - 1;

        while(!q.empty()) {
            int now = q.front();
            q.pop();

            // cout << v[now].first << " " << v[now].second << "\n";

            if(now == answer) {
                cango = true;
                break;
            }

            for(int i=0; i<graph[now].size(); i++) {
                int next = graph[now][i];

                if(visited[next] == false) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        
        if(cango) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }

    }
}
