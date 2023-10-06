#include <iostream>
#include <vector>

using namespace std;
int visited[9];
vector<int> v;
vector<int> temp;
// int n, m;
 
void dfs(int depth) {
    if(depth == 3) {
        for(int i=0; i<temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<v.size(); i++) {
        if(!visited[i]) {
            temp.push_back(v[i]);
            visited[i] = true;
            dfs(depth + 1);
            visited[i] = false;
            temp.pop_back();
        }
    }
}

int main() {
    // cin >> n >> m;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(10);
    v.push_back(9);
    v.push_back(8);
    v.push_back(4);
    v.push_back(121);

    dfs(0);
}