#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int n, q;
int map_size;
int map[129][129];
int visited[129][129] = { false, };
int skills[1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void rotate(int x, int y, int len) {
  int temp[len+1][len+1];

  for(int i=0; i<len; i++) {
    for(int j=0; j<len; j++) {
        temp[j][len-1-i] = map[x+i][y+j];
    }
  }

  for(int i=0; i<len; i++) {
    for(int j=0; j<len; j++) {
        map[x+i][y+j] = temp[i][j];
    }
  }
}


int check_path(int x, int y) {
    if(x >= map_size || x < 0 || y >= map_size || y < 0) {
        return false;
    }
    return true;
}

void melt() {
    vector<pair<int, int>> melts;

    for(int i=0; i<map_size; i++) {
        for(int j=0; j<map_size; j++) {
            if(map[i][j] != 0) {
                int x = i;
                int y = j;
                int count = 0;

                for(int k=0; k<4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(check_path(nx, ny) && map[nx][ny] > 0) {
                        count++;
                    }
                }

                if(count < 3) {
                    melts.push_back({ i, j });
                }
            }
        }
    }

    for(int i=0; i<melts.size(); i++) {
        map[melts[i].first][melts[i].second] -=1 ;
    }
}

int bfs(int x, int y) {
    queue<pair<int ,int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int block = 0;

    while(!q.empty()) {
        int next_x = q.front().first;
        int next_y = q.front().second;
        q.pop();
        block++;

        for(int i=0; i<4; i++) {
            int nx = next_x + dx[i];
            int ny = next_y + dy[i];

            if(check_path(nx, ny) && visited[nx][ny] == false && map[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    return block;
}

int main() {
    cin >> n >> q;

    map_size = pow(2, n);

    for(int i=0; i<map_size; i++) {
        for(int j=0; j<map_size; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<q; i++) cin >> skills[i];

    for(int i=0; i<q; i++) {
        int l = skills[i];
        l = pow(2, l);
        // rotate
        for(int p=0; p<map_size; p += l) {
            for(int k=0; k<map_size; k +=l) {
                rotate(p, k, l);
            }
        }

        melt();
    }

    int ice = 0;
    int answer = 0;

    for(int i=0; i<map_size; i++) {
        for(int j=0; j<map_size; j++) {
            ice += map[i][j];
            if(map[i][j] > 0 && visited[i][j] == false) {
                answer = max(answer, bfs(i, j));
            }
        }
    }

    cout << ice << "\n";
    cout << answer << "\n";
}