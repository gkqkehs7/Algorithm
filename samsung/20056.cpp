#include <iostream>
#include <vector>
using namespace std;

struct Fireball {
    int x;
    int y;
    int weight;
    int velocity;
    int direction;
};

int n, m, k;
vector<Fireball> fireballs[51][51];

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void move_fireball() {

    vector<Fireball> temp[51][51];

    // 이동
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(fireballs[i][j].size() > 0) {
                for(int k=0; k<fireballs[i][j].size(); k++) {
                    int x = fireballs[i][j][k].x;
                    int y = fireballs[i][j][k].y;
                    int weight = fireballs[i][j][k].weight;
                    int velocity = fireballs[i][j][k].velocity;
                    int direction = fireballs[i][j][k].direction;
                    
                    velocity = velocity % n;
                    int nx = x;
                    int ny = y;

                    for(int p=0; p<velocity; p++) {
                        nx = nx + dx[direction];
                        ny = ny + dy[direction];

                        if(nx < 0) nx = n - 1;
                        if(nx == n) nx = 0;
                        if(ny < 0) ny = n - 1;
                        if(ny == n) ny = 0;
                    }
                    
                    fireballs[i][j][k].x = nx;
                    fireballs[i][j][k].y = ny;

               
                    temp[nx][ny].push_back(fireballs[i][j][k]);
                } 
            }
            fireballs[i][j].clear();
        }
    }


    // 융합
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int count = temp[i][j].size();
            int velocity = 0;
            int weight = 0;
            int odd = 0;
            int even = 0;
            
            if(temp[i][j].size() >= 2) {
                for(int k=0; k<temp[i][j].size(); k++) {
                    weight += temp[i][j][k].weight;
                    velocity += temp[i][j][k].velocity;
                    if(temp[i][j][k].direction % 2 == 0) {
                        even += 1;
                    } else {
                        odd += 1;
                    }
                }

                weight = weight / 5;

                temp[i][j].clear();
                if(weight != 0) {
                    velocity = velocity / count;

                    if((odd == count) || (even == count)) {
                        Fireball fireball1 = { i, j, weight, velocity, 0};
                        Fireball fireball2 = { i, j, weight, velocity, 2};
                        Fireball fireball3 = { i, j, weight, velocity, 4};
                        Fireball fireball4 = { i, j, weight, velocity, 6};
                        temp[i][j].push_back(fireball1);
                        temp[i][j].push_back(fireball2);
                        temp[i][j].push_back(fireball3);
                        temp[i][j].push_back(fireball4);
                    } else {
                        Fireball fireball1 = { i, j, weight, velocity, 1};
                        Fireball fireball2 = { i, j, weight, velocity, 3};
                        Fireball fireball3 = { i, j, weight, velocity, 5};
                        Fireball fireball4 = { i, j, weight, velocity, 7};
                        temp[i][j].push_back(fireball1);
                        temp[i][j].push_back(fireball2);
                        temp[i][j].push_back(fireball3);
                        temp[i][j].push_back(fireball4);
                    }
                }
            }
        }
    }

    // 복사
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(temp[i][j].size() > 0) {
                for(int k=0; k<temp[i][j].size(); k++) {
                    fireballs[i][j].push_back(temp[i][j][k]);
                }
            }
        }
    }

}

int main() {
    cin >> n >> m >> k;

    for(int i=0; i<m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fireballs[r-1][c-1].push_back({ r - 1, c - 1, m, s, d });
    }

    for(int i=0; i<k; i++) move_fireball();

    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
             if(fireballs[i][j].size() > 0) {
                for(int k=0; k<fireballs[i][j].size(); k++) {
                    answer += fireballs[i][j][k].weight;
                }
            }
        }
    }

    cout << answer;
}