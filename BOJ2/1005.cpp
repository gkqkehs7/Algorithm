#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cost[1001];
int degree[1001];
long long dp[1001];
bool visited[1001];
bool to_build[1001];
vector<int> graph[1001];
vector<int> childs[1001];

void find_to_build(int target) {
    to_build[target] = true;
    for(int i=0; i<childs[target].size(); i++) {
        int next = childs[target][i];
        if(!visited[next]) {
            visited[next] = true;
            find_to_build(next);
        }
        
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
    
        for(int i=0; i<1001; i++) {
            cost[i] = 0;
            degree[i] = 0;
            dp[i] = 0;
            visited[i] = false;
            to_build[i] = false;
            graph[i].clear();
            childs[i].clear();
        }

        int n, k, target;
        cin >> n >> k;

        for(int i=1; i<=n; i++) {
            int input;
            cin >> input;
            cost[i] = input;
        }

        for(int i=0; i<k; i++) {
            int first, second;
            cin >> first >> second;
            graph[first].push_back(second);
            childs[second].push_back(first);
            degree[second]++;
        }
        
        cin >> target;
        find_to_build(target);
        queue<int> q;

        for(int i=1; i<=n; i++) {
            if(degree[i] == 0) {
                dp[i] = cost[i];
                q.push(i);
            }
        }
        

        while(!q.empty()) {
            
            int child = q.front();
            q.pop();
       
            for(int i=0; i<graph[child].size(); i++) {
                int parent = graph[child][i];

                if(to_build[parent]) {
                    if(dp[parent] < dp[child] + cost[parent]) {
                        dp[parent] = dp[child] + cost[parent];
                        q.push(parent);
                    }
                    // dp[parent] = max(dp[parent], dp[child] + cost[parent]);
                    // q.push(parent);
                }
            }
        }

        cout << dp[target] << "\n";
    
    }
}