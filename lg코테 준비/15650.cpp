#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int visited[9];

void dfs(int idx, int cnt) {
    
    if(cnt == m) {
        for(int i=0; i<v.size(); i++) {
            if(visited[i] == true) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
        return;
    } 
    
    for(int i = idx; i<v.size(); i++) {
        if(visited[i] == true) continue;

        visited[i] = true;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<9; i++) {
        visited[i] = false;
    }

    for(int i=1; i<=n; i++) {
        v.push_back(i);
    }

    dfs(0, 0);
}