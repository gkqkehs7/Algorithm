#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int degree[32001] = { 0, };
vector<int> graph[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n, m;
    cin >> n >> m;


    for(int i=0; i<m; i++) {
        int first, second;
        cin >> first >> second;
        degree[second]++;
        graph[first].push_back(second);
    }

    for(int i=1; i<=n; i++) {
        if(degree[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int child = pq.top();
        cout << child << " ";
        pq.pop();

        for(int i=0; i<graph[child].size(); i++) {
            int parent = graph[child][i];
            degree[parent]--;

            if(degree[parent] == 0) {
                pq.push(parent);
            }
        }
    }
}