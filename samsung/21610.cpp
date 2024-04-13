#include <iostream>
#include <vector>
using namespace std;

struct Storm {
    int x;
    int y;
};

int map[51][51];
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
vector<Storm> storms;
int n, m;

bool check_path(int x, int y) {
    if(x >= n || x < 0 || y >= n || y < 0) return false;

    return true;
}

void move_storms(int direction, int velocity) {
    velocity = velocity % n;
    for(int i=0; i<storms.size(); i++) {
        int x = storms[i].x;
        int y = storms[i].y;
        int nx = x;
        int ny = y;

        for(int j=0; j<velocity; j++) {
            nx = nx + dx[direction];
            ny = ny + dy[direction];

            if(nx == n) nx = 0;
            if(nx == -1) nx = n-1;
            if(ny == n) ny = 0;
            if(ny == -1) ny = n-1;
        }

        storms[i].x = nx;
        storms[i].y = ny;
    }
}

void water() {
    for(int i=0; i<storms.size(); i++) {
        int x = storms[i].x;
        int y = storms[i].y;
        map[x][y] += 1;
    }
}

void water_bug() {
    for(int i=0; i<storms.size(); i++) {
        int x = storms[i].x;
        int y = storms[i].y;

        int count = 0;
        for(int j=1; j<8; j+=2) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(check_path(nx, ny) && map[nx][ny] > 0) count++;
        }

        map[x][y] += count;
    }
}


void new_storms() {
    vector<Storm> new_storm;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] >= 2) {
                bool already = false;
                for(int k=0; k<storms.size(); k++) {
                    int x = storms[k].x;
                    int y = storms[k].y;

                    if(x == i && y == j) {
                        already = true;
                        break;
                    }
                }

                if(!already) {
                    new_storm.push_back({ i, j });
                    map[i][j] -= 2;
                }
            }
        }
    }

    storms.clear();

    for(int i=0; i<new_storm.size(); i++) {
        storms.push_back(new_storm[i]);
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


void print_storms() {
    for(int i=0; i<storms.size(); i++) {
        cout << storms[i].x << " " << storms[i].y << "\n";
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    vector<pair<int, int>> commands;

    for(int i=0; i<m; i++) {
        int d, s;
        cin >> d >> s;
        commands.push_back({ d-1, s });
    }

    storms.push_back({ n-1, 0 });
    storms.push_back({ n-1, 1 });
    storms.push_back({ n-2, 0 });
    storms.push_back({ n-2, 1 });

    for(int i=0; i<m; i++) {
        int direction = commands[i].first;
        int velocity = commands[i].second;

        move_storms(direction, velocity);
        water();
        water_bug();
        new_storms();
    }
    
    int answer = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            answer += map[i][j];
        }
    }

    cout << answer;
}