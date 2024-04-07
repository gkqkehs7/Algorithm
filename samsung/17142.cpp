#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[51][51];
vector<pair<int, int>> walls;
vector<pair<int, int>> viruses;
vector<vector<pair<int, int>>> combinations;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = {1, 0, -1, 0};
bool visited[11] = { false, };

struct Virus {
    int x;
    int y;
    int depth;
};

void get_combinations(int index, int depth) {
    if(depth == m) {
        vector<pair<int, int>> combination;
        for(int i=0; i<11; i++) {
            if(visited[i]) {
                combination.push_back(viruses[i]);
            }
        }

        combinations.push_back(combination);
        return;
    }

    for(int i= index; i<viruses.size(); i++) {
        if(visited[i] == false) {
            visited[i] = true;
            get_combinations(i, depth + 1);
            visited[i] = false;
        }
    }
}

bool check_path(int x, int y) {
    if(x >= n || x < 0 || y >= n || y < 0 || map[x][y] == 1) {
        return false;
    }

    return true;
}

int spread_virus(vector<pair<int, int>> viruses) {
    int dp[51][51];
    int answer = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = 99999;
        }
    }

    for(int i=0; i<viruses.size(); i++) {
        queue<Virus> q;

        dp[viruses[i].first][viruses[i].second] = 0;
        q.push({ viruses[i].first, viruses[i].second, 0 });

        while(!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int depth = q.front().depth;
            q.pop();

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(check_path(nx, ny)) {
                    if(dp[nx][ny] > dp[x][y] + 1) {
                        dp[nx][ny] = dp[x][y] + 1;
                        q.push({ nx, ny , depth + 1 });
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == 1) {
                dp[i][j] = -1;
            } else if(map[i][j] == 2) {
                dp[i][j] = 0;
            }
        }
    }

    // 하나라도 99999 있으면 탈락
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            answer = max(answer, dp[i][j]);
        }
    }

    return answer;
}

void draw_viruses(vector<pair<int, int>> viruses) {
    for(int i=0; i<viruses.size(); i++) {
        map[viruses[i].first][viruses[i].second] = 2;
    }
}

void erase_viruses(vector<pair<int, int>> viruses) {
    for(int i=0; i<viruses.size(); i++) {
        map[viruses[i].first][viruses[i].second] = 0;
    }
}


int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;

            if(input == 2) {
                viruses.push_back({ i , j });
            }

            map[i][j] = input;
        }
    }
    vector<pair<int, int>> v;
    get_combinations(0, 0);

    int answer = 99999;
    for(int i=0; i<combinations.size(); i++) {
        vector<pair<int, int>> viruses = combinations[i];

        erase_viruses(viruses);

        // 확산
        int time = spread_virus(viruses);
        answer = min(answer, time);

        draw_viruses(viruses);
    }


    if(answer == 99999) {
        cout << -1;
    } else {
        cout << answer;
    }

}