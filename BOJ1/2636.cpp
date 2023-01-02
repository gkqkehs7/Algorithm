#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[101][101] = { 0, };
int visited[101][101] = { false, };
int dx[4] = { 0, 1, 0 , -1};
int dy[4] = { 1, 0 ,-1, 0 };
vector<pair<int ,int>> v;
vector<int> melts;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int input;
            cin >> input;

            map[i][j] = input;
        }
    }

    int total_day = 0;

    while(1) {
        total_day++;
        int total_cheeze = 0;
        int melt = 0;
       

        for(int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                
                if(map[i][j] == 1) {    
                    total_cheeze++;
                    bool side = false;

                    queue<pair<int, int>> q;
                    q.push({i ,j});
                    visited[i][j] = true;

                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;

                        q.pop();
                        for(int k=0; k<4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            
                            if(nx >= n || nx < 0 || ny >= m || ny <0) {
                                side = true;
                                break;
                            }
                            
                            if(map[nx][ny] != 1 && visited[nx][ny] == false) {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }

                    for(int i=0; i<n; i++) {
                        for(int j=0; j<m; j++) {
                            visited[i][j] = false;
                        }
                    }

                    if(side == true) {
                       melt++;
                       v.push_back({ i, j });
                    }
                }
            }
        }

        for(int i=0; i<v.size(); i++) {
            map[v[i].first][v[i].second] = 0;
        }


        // cout << "\n-----------------------------\n";
        // for(int i=0; i<n; i++) {
        //     for (int j=0; j<m; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "-----------------------------\n";

        v.clear();
        // cout << "melt: " << melt << "\n";
        // cout << "total_cheeze: " << total_cheeze << "\n";
        melts.push_back(melt);
        if(melt == 0) {
            break;
        }
    }

    cout << total_day - 1 << " " << melts[total_day - 2];
}