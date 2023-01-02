#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int graph[100001] = { 0, };
bool visited[100001] = { false, };
bool team[100001] = { false, };

bool circle = false;
vector<int> temp;

void dfs(int now, int start) {
    int next = graph[now];
    // cout << next << " ";
    if(next == start) {
        circle = true;
        return;
    }

    if(visited[next] == true) {
        return;
    } else {
        visited[next] = true;
        temp.push_back(next);
        dfs(next, start);
    }
   
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

        for(int i=0; i<n; i++) {
            int input;
            cin >> input;
            graph[i+1] = input;
        }

        for(int i=1; i<=n; i++) {
            int start = i;
            temp.push_back(start);
            
            if(visited[start] == false) {
                // cout << "start: " << start << " ";
                visited[start] = true;
                dfs(start, start);
                // cout << "\n";
            }
           
            if(circle) {
                for(int k=0; k<temp.size(); k++) {
                    team[temp[k]] = true;
                }
                team[start] = true;
            } else {
                for(int k=0; k<temp.size(); k++) {
                    visited[temp[k]] = false;
                }
                visited[start] = true; 
            }
            circle = false;

            temp.clear();
        }

        int count = 0;
        for(int i=1; i<=n; i++) {
            if(team[i] == false) {
                count++;
            }
            visited[i] = false;
            team[i] = false;
        }
        cout << count << "\n";
    }
}