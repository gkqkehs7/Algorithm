#include <iostream>
#include <vector>

using namespace std;
int n, m;
int map[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int shark_x;
int shark_y;
int exploded_glasses[3] = { 0, 0, 0 };

bool check_path(int x, int y) {
    if(x >= n || x < 0 || y >= n || y < 0) return false;

    return true;
}

vector<int> rotate_map() {
    int x = shark_x;
    int y = shark_y;
    int rotate_dx[4] = { 0, 1, 0, -1 };
    int rotate_dy[4] = { -1, 0, 1, 0 }; 
    int direction = 0;
    int range = 1;

    vector<int> alive_blocks;

    while(true) {
        for(int i=0; i<2; i++) {
            for(int j=0; j<range; j++) {
                x = x + rotate_dx[direction];
                y = y + rotate_dy[direction];

                if(map[x][y] > 0) {
                    alive_blocks.push_back(map[x][y]);
                }
                
            }
            direction = (direction + 1) % 4;
        }
        range++;

        if(range == n) {
            for(int j=0; j<range-1; j++) {
                x = x + rotate_dx[direction];
                y = y + rotate_dy[direction];
                
                if(map[x][y] > 0) {
                    alive_blocks.push_back(map[x][y]);
                }
            }
            break;
        }
    } 

    return alive_blocks;
}

vector<int> explosion(vector<int> alive_blocks) {

    // for(int i=0; i<alive_blocks.size(); i++) {
    //     cout << alive_blocks[i] << " ";
    // }
    // cout << "\n";

    vector<int> rest_blocks;

    int index = 0;

    while(index < alive_blocks.size()) {
        if(index >= alive_blocks.size() || alive_blocks[index] == 0) break;

        vector<int> temp;
        temp.push_back(alive_blocks[index]);

        int same_count = 1;

        while(index+same_count < alive_blocks.size() && alive_blocks[index] == alive_blocks[index+same_count]) {
            temp.push_back(alive_blocks[index+same_count]);
            same_count++;
        }

        // cout << alive_blocks[index] << " " << temp.size() << "번 등장\n";

        if(temp.size() < 4) {
            for(int j=0; j<temp.size(); j++) {
                rest_blocks.push_back(temp[j]);
            }
        } else { // 폭발하는 경우
            exploded_glasses[alive_blocks[index]-1] += temp.size();
        }

        index += temp.size();
    }

    return rest_blocks;
}

vector<int> change(vector<int> alive_blocks) {
    vector<int> changed_blocks;

    int index = 0;

    while(index < alive_blocks.size()) {
        if(index >= alive_blocks.size() || alive_blocks[index] == 0) break;

        vector<int> temp;
        temp.push_back(alive_blocks[index]);

        int same_count = 1;

        while(index+same_count < alive_blocks.size() && alive_blocks[index] == alive_blocks[index+same_count]) {
            temp.push_back(alive_blocks[index+same_count]);
            same_count++;
        }

        changed_blocks.push_back(temp.size());
        changed_blocks.push_back(alive_blocks[index]);

        index += temp.size();
    }

    return changed_blocks;
}

void copy_map(vector<int> alive_blocks) {

    int x = shark_x;
    int y = shark_y;
    int rotate_dx[4] = { 0, 1, 0, -1 };
    int rotate_dy[4] = { -1, 0, 1, 0 }; 
    int direction = 0;
    int range = 1;
    int index = 0;

    // cout << alive_blocks.size() << "\n";
    
    while(true) {
        for(int i=0; i<2; i++) {
            for(int j=0; j<range; j++) {
                x = x + rotate_dx[direction];
                y = y + rotate_dy[direction];

                // cout << x << " " << y << "\n";
                if(index < alive_blocks.size()) {
                    map[x][y] = alive_blocks[index];
                } else {
                    map[x][y] = 0;
                }
                index++;
            }
            direction = (direction + 1) % 4;
        }
        range++;

        if(range == n) {
            for(int j=0; j<range-1; j++) {
                x = x + rotate_dx[direction];
                y = y + rotate_dy[direction];
                
                // cout << x << " " << y << "\n";
                if(index < alive_blocks.size()) {
                    map[x][y] = alive_blocks[index];
                } else {
                    map[x][y] = 0;
                }
                index++;
            }
            break;
        }
    } 
}

void blizard(int direction, int range) {
    int nx = shark_x;
    int ny = shark_y;

    for(int i=0; i<range; i++) {
        nx = nx + dx[direction];
        ny = ny + dy[direction];

        if(check_path(nx, ny)) {
            map[nx][ny] = 0;
        }
    }
}


void print_map() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    vector<pair<int, int>> commands;

    cin >> n >> m;

    shark_x = n / 2;
    shark_y = n / 2;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        int direction, speed;
        cin >> direction >> speed;
        commands.push_back({ direction - 1, speed });
    }

    for(int i=0; i<m; i++) {
        int direction = commands[i].first;
        int speed = commands[i].second;

        blizard(direction, speed);

        vector<int> alive_blocks = rotate_map();

        while(true) {
            int prev_size = alive_blocks.size();
            alive_blocks = explosion(alive_blocks);

            if(prev_size == alive_blocks.size()) break;
        }
        
        if(alive_blocks.size() > 0) {
            vector<int> changed_blocks = change(alive_blocks);
            copy_map(changed_blocks);
        } else {
            break;
        }

    }
    
    int answer = 0;
    for(int i=0; i<3; i++) {
        answer += exploded_glasses[i] * (i + 1);
    }

    cout << answer;
}