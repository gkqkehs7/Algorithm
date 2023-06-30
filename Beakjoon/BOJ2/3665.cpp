#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int score[501];
bool adj[501][501];
int degree[501];

int main() {
    int t;
    cin >> t;
    while(t--) {
    
        vector<int> ans;
        queue<int> q;

        for(int i=0; i<501; i++) {
            for(int j=0; j<501; j++) {
                adj[i][j] = false;
            }
            degree[i] = 0;
        }
        int n;
        cin >> n;

        for(int i=0; i<n; i++) {
            cin >> score[i];
        }

        for (int i = 0; i < n; ++i){
            for (int j = i+1; j < n; ++j){
                adj[score[i]][score[j]] = true;
                degree[score[j]]++;
            }
        }

        int m;
        cin >> m;
       
        for(int i=0; i<m; i++) {

            int a, b;
            cin >> a >> b;
            if(adj[a][b]){
                adj[a][b] = false;
                adj[b][a] = true;
                degree[b]--;
                degree[a]++;
            }
            else {
                adj[b][a] = false;
                adj[a][b] = true;
                degree[a]--;
                degree[b]++;
            }

        }

        for (int i = 1; i <= n; ++i)
            if(degree[i]==0) q.push(i);

        for (int k = 0; k < n; k++) {
                if(q.empty()) break;
                
                int now = q.front();
                q.pop();
                ans.push_back(now);
                degree[now]--;
                for (int i = 1; i <= n; i++) {
                    if (adj[now][i]) degree[i]--;
                    if (degree[i] == 0) q.push(i);
                }
            }

            if(ans.size()==n){
                for (int i = 0; i < n; i++) 
                    cout << ans[i] << ' ';
                cout << '\n';
            }
    
            else
                cout << "IMPOSSIBLE" << '\n';
    }
}