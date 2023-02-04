#include <iostream>
#include <vector>
using namespace std;
int n, m;

bool visited[201] = { false };
int  destination[201] = { 0 };
vector<int> graph[201];

bool dfs(int now, int target) {
    if(now == target) {
        return true;
    }

    for(int i=0; i<graph[now].size(); i++ ){
        int next = graph[now][i];
        
        visited[next] = true;
        dfs(next, target);
        visited[next] = false;
    }

    return false;
}

int main() {
    
    cin >> n >> m;
    
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int input;
            cin >> input;
            if(input == 1) {
                graph[i].push_back(j);
            } 
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<graph[i].size(); i++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    
    // for(int i=0; i<m; i++) {
    //     int input;
    //     cin >> input;
    //     destination[i] = input;
    // }

    // bool cango = true;
    // for(int i=0; i<m-1; i++) {
    //     if(!dfs(destination[i], destination[i+1])) {
    //         cango = false;
    //         break;
    //     }
    // }

    // if(cango) {
    //     cout << "YES";
    // } else {
    //     cout << "NO";
    // }
 
}