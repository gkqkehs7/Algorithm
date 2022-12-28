#include <iostream>
#include <queue>

using namespace std;
int row, col;
int arr[301][301];
int dx[4] = { 1, 0, -1 , 0 };
int dy[4] = { 0 ,1 , 0 , -1};
bool all_melt = true;
int peace = 0;

bool check() {
    int start_x;
    int start_y;
    bool visited[301][301] = { false };

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(arr[i][j] > 0 && visited[i][j] == false) {
                start_x = i;
                start_y = j;

                queue<pair<int,int>> q;
                q.push({start_x, start_y});
                visited[start_x][start_y] = true;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    

                    for(int i=0; i<4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(visited[nx][ny] == false && arr[nx][ny] != 0) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }            
                }
                peace++;
            }
        }
    }

    if(peace == 1) {
        return false;
    } else {
        return true;
    }
}

bool check_all_melt() {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(arr[i][j] > 0) {
                all_melt = false;
                break;
            }
        }
    }

    return all_melt;
}

int main() {
  
    cin >> row >> col;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            int input;
            cin >> input;
            arr[i][j] = input;
        }
    }
    while(!check_all_melt()) {
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                int x = i;
                int y = j;

                if(arr[x][y] == 0) {
                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx>=0 && nx<row && ny>=0 && ny <col && arr[nx][ny] != 0) {
                            arr[nx][ny]--;
                        }
                    }
                }
            }
        }

        if(check()) {
            break;
        };
    }
   
}