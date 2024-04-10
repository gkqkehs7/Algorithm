#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int map[21][21];
int visited[21][21] = { false, };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Group { 
    int size;
    int rainbow;
    int standard_x;
    int standard_y;
};

void init() {
    for(int i=0; i<21; i++) {
        for(int j=0; j<21; j++) {
            visited[i][j] = false; 
        }
    }
}

bool check_path(int x, int y) {
    if(x >= n || x < 0 || y >= n || y < 0 || map[x][y] == -2) {
        return false;
    }

    return true;
}

Group bfs(int x, int y) {
    init();
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int color = map[x][y];
    int rainbow = 0;
    int standard_x = x;
    int standard_y = y;
    int block = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        block++;

        if(map[x][y] == 0) rainbow++;
        
        // 기준 블록 찾기
        if(map[x][y] != 0) {
            if(x <= standard_x) {
                if(x == standard_x) {
                    if(y < standard_y) {
                        standard_x = x;
                        standard_y = y;
                    }
                } else {
                    standard_x = x;
                    standard_y = y;
                }
            }
        }
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(check_path(nx, ny) && (map[nx][ny] == color || map[nx][ny] == 0) && visited[nx][ny] == false) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    return { block, rainbow, standard_x, standard_y };
}

vector<Group> find_big_group() {
    vector<Group> groups;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // 일반 블럭만 방문
            if(map[i][j] >= 1) {
                Group group = bfs(i, j);
                if(group.size >= 2) {
                    groups.push_back(group);
                } 
            }
        }
    }
    
    if(groups.size() == 0) {
        return groups;
    }

    // 제일 큰 그룹 사이즈 찾기
    int max_group_size = 0;
    for(int i=0; i<groups.size(); i++) {
        max_group_size = max(max_group_size, groups[i].size);
    }

    vector<Group> max_groups;

    // 그 크기를 가지는 그룹들 찾기
    for(int i=0; i<groups.size(); i++) {
        if(groups[i].size == max_group_size) max_groups.push_back(groups[i]);
    }

    return max_groups;
}

bool compare(Group g1, Group g2) {
    if(g1.size == g2.size) {
        if(g1.rainbow == g2.rainbow) {
            if(g1.standard_x == g2.standard_x) {
                return g1.standard_y > g2.standard_y;
            }
            return g1.standard_x > g2.standard_x;
        }
        return g1.rainbow > g2.rainbow;
    }
    return g1.size > g2.size;
}

void erase_block(Group group) {
    init();
    int x = group.standard_x;
    int y = group.standard_y;
    int color = map[x][y];

    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
  
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
    
        map[x][y] = -2; // 블럭 지우기
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(check_path(nx, ny) && (map[nx][ny] == color || map[nx][ny] == 0) && visited[nx][ny] == false) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
}

void gravity() {
    for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == -2) {
				int x = i;
				int y = j;
				while (x > 0 && map[x][y] == -2) x--;
				if (map[x][y] == -1) continue;
				map[i][j] = map[x][y];
				map[x][y] = -2;
			}
		}
	}
}

void rotate() {
    int copy_map[21][21];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            copy_map[(n-j-1)%n][i] = map[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            map[i][j] = copy_map[i][j];
        }
    }
}

void print_map() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == -2) {
                cout << "#" << " ";
            } else { 
                cout << map[i][j] << " ";
            }
         
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;

    while(true) {
        vector<Group> groups = find_big_group();

        if(groups.size() == 0) {
            break;
        }

        sort(groups.begin(), groups.end(), compare);

        // cout << "<" << groups[0].size << " " << groups[0].rainbow << " " << groups[0].standard_x << " " << groups[0].standard_y << ">\n";

        answer += pow(groups[0].size, 2);

        erase_block(groups[0]);

        gravity();

        rotate();

        gravity();

        // print_map();
    }

    cout << answer;
   
}