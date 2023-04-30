#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool visited[51];
int ans[51];
bool find123 = false;


void dfs(int depth, string now, int max_value) {

    cout << now << " ";
    if(find123) return;

    if(now.length() == 0) {
        bool can = true;

        for(int i=1; i<=max_value; i++) {
            if(visited[i] == false) {
                can = false;
                break;
            }
        }

        if(can) {
            find123 = true;
            for(int i=0; i<max_value; i++) {
                cout << ans[i] << " ";
            }
        } else {
            max_value = 0;
        }

        return;
    }

    
    int next;
    string next_str;

    next = stoi(now.substr(0, 1));    
    next_str = now.substr(1, now.length()); 
    
    if(next)

    if(!visited[next]){
        visited[next] = true;
        ans[depth] = next;

        dfs(depth + 1, next_str, max(next, max_value));
    }

    visited[next] = false;

    if(now.length() >= 2) {
        next = stoi(now.substr(0, 2));
        next_str = now.substr(2, now.length());

        if(!visited[next]){
            visited[next] = true;
            dfs(depth+ 1, next_str, max(next, max_value));
        }
    }
    
}

int main() {

    string s;
    cin >> s;

    for(int i=0; i<51; i++) {
        visited[i] = false;
    }

    dfs(0, s, -1);
    
}