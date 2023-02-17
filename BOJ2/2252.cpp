#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;


int degree[32001];
vector<int> graph[32001];
queue<int> q;
stack<int> ans;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<32001; i++) degree[i] = 0;

    for(int i=0; i<m; i++) {
        int parent, child;
        cin >> parent >> child;
        graph[child].push_back(parent);
        degree[parent]++;
    }

    for(int i=1; i<=n; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }  


    while(!q.empty()) {
        int child = q.front();
        ans.push(child);
        q.pop();

        for(int i=0; i<graph[child].size(); i++) {
            int parent = graph[child][i];
            degree[parent]--;

            if(degree[parent] == 0) q.push(parent);
        }
    }   

    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
   

}