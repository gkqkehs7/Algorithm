#include <iostream>

using namespace std;
const int MAX = 100001;
int graph[MAX] = { 0, };
bool visited[MAX] = { false, };
bool done[MAX] = { false, };
int cnt = 0;

void dfs(int now) {
    int next = graph[now];

    if(visited[next] == false) {
        visited[next] = true;
        dfs(next);
    } else if(done[next] == false) {
        for(int i = next; i != now; i = graph[i]) {
            cnt++;
        }
        cnt++;
    }

    done[now] = true;
   
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i=1; i<=n; i++) {
            int input;
            cin >> input;
            graph[i] = input;
        }

        
        cnt = 0;
        for(int i=1; i<=n; i++) {
            if(visited[i] == false) {
                visited[i] = true;
                dfs(i);
            }
        }
      
        cout << n - cnt << "\n";


        for(int i=0; i<MAX; i++) {
            visited[i] = false;
            done[i] = false;
        }
    }
}