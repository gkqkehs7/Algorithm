#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int visited[9];
int answer = 0;

void dfs(int cost, int depth) {
    if(depth == v.size() - 1) {
        answer += 1;
    }

    for(int i=0; i<v.size(); i++) {
        if(!visited[i] && cost + v[i] >= 0) {
            visited[i] = true;
            dfs(cost + v[i], depth + 1); 
            visited[i] = false;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int wei;
        cin >> wei;
        v.push_back(wei-k);
        visited[i] = false;
    }
    
    dfs(0, 0);
    cout << answer;
}