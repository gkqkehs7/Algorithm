#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<int> cctvs;
vector<pair<int, int>> cctvs_location;
vector<vector<int>> combinations;
int n, m;
bool visited[9];

void Init() {
    for(int i=0; i<9; i++) {
        visited[i] = false;
    }
}

void back_tracking(vector<int> combination, int depth) {

    if(depth == cctvs.size()) {
        combinations.push_back(combination);
        return;
    }

    for(int i=0; i<4; i++) {
        combination.push_back(i);
        back_tracking(combination, depth + 1);
        combination.pop_back();
    }
}

bool check_path(int nx, int ny) {
    if(nx >= n || nx < 0 || ny >= m || ny < 0 || map[nx][ny] == 6) {
        return false;
    }

    return true;
}

void print_up(vector<vector<char>>& copy_map, int nx, int ny) {
    while(check_path(nx, ny)) {
        copy_map[nx][ny] = '#';
        nx = nx - 1;
        ny = ny;
    }
}

void print_down(vector<vector<char>>& copy_map, int nx, int ny) {
    while(check_path(nx, ny)) {
        copy_map[nx][ny] = '#';
        nx = nx + 1;
        ny = ny;
    }
}


void print_right(vector<vector<char>>& copy_map, int nx, int ny) {
    while(check_path(nx, ny)) {
        copy_map[nx][ny] = '#';
        nx = nx;
        ny = ny + 1;
    }
}

void print_left(vector<vector<char>>& copy_map, int nx, int ny) {
    while(check_path(nx, ny)) {
        copy_map[nx][ny] = '#';
        nx = nx;
        ny = ny - 1;
    }
}



int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            temp.push_back(input);

            if(input > 0 && input < 6) {
                cctvs.push_back(input);
                cctvs_location.push_back({ i, j });
            }
        }
        map.push_back(temp);
    }
    
    vector<int> temp;
    back_tracking(temp, 0);
    int answer = 9999999;

    // 0 북 1 동 2 남 3 서
    for(int i=0; i<combinations.size(); i++) {

        // 여기서 복사
        vector<vector<char>> copy_map;

        for(int k=0; k<map.size(); k++) {
            vector<char> temp;
            for(int p=0; p<map[k].size(); p++) {
                temp.push_back('.');
            }
            copy_map.push_back(temp);
        }

        for(int j=0; j<combinations[i].size(); j++) {
            int cctv = cctvs[j];
            int x = cctvs_location[j].first;
            int y = cctvs_location[j].second;
            int direction = combinations[i][j];

            if(cctv == 1) {
                if(direction == 0) {
                    print_up(copy_map, x, y);
                } else if(direction == 1) {
                    print_right(copy_map, x, y);
                } else if(direction == 2) {
                    print_down(copy_map, x, y);
                } else if(direction == 3) {
                    print_left(copy_map, x, y);
                }
            } else if(cctv == 2) {
                if(direction == 0 || direction == 2) {
                    print_up(copy_map, x, y);
                    print_down(copy_map, x, y);
                } else {
                    print_right(copy_map, x, y);
                    print_left(copy_map, x, y);
                }
                
            } else if(cctv == 3) {
                if(direction == 0) {
                    print_up(copy_map, x, y);
                    print_right(copy_map, x, y);
                } else if(direction == 1) {
                    print_right(copy_map, x, y);
                    print_down(copy_map, x, y);
                } else if(direction == 2) {
                    print_down(copy_map, x, y);
                    print_left(copy_map, x, y);
                } else if(direction == 3) {
                    print_left(copy_map, x, y);
                    print_up(copy_map, x, y);
                }

            } else if(cctv == 4) {
                if(direction == 0) {
                    print_left(copy_map, x, y);
                    print_up(copy_map, x, y);
                    print_right(copy_map, x, y);
                } else if(direction == 1) {
                    print_up(copy_map, x, y);
                    print_right(copy_map, x, y); 
                    print_down(copy_map, x, y);
                } else if(direction == 2) {
                    print_right(copy_map, x, y); 
                    print_down(copy_map, x, y);
                    print_left(copy_map, x, y);
                } else if(direction == 3) {
                    print_down(copy_map, x, y);
                    print_left(copy_map, x, y);
                    print_up(copy_map, x, y);
                }

            } else if(cctv == 5) {
                print_down(copy_map, x, y);
                print_right(copy_map, x, y); 
                print_left(copy_map, x, y);
                print_up(copy_map, x, y);
            }
        }
        
        int count = 0;
        for(int k=0; k<copy_map.size(); k++) {
            for(int p=0; p<copy_map[k].size(); p++) {
                if(map[k][p] != 6 && copy_map[k][p] == '.') {
                    count++;
                }
            }
        }

        answer = min(answer, count);
    }

    cout << answer;
}