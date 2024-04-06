    #include <iostream>

    using namespace std;

    int r, c, t;
    int map[51][51];
    int dust[51][51];
    int x1, x2 = 0;

    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    void init() {
        for(int i=0; i<51; i++) {
            for(int j=0; j<51; j++) {
                dust[i][j] = 0;
            }
        }
    }

    bool check_path(int x, int y) {
        if(x >= r || x < 0 || y >= c || y < 0 || map[x][y] == -1) {
            return false;
        }

        return true;
    }


    void calculate_dust(int x, int y) {
        int count = 0;
        int diffuse = map[x][y] / 5;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(check_path(nx, ny)) {
                dust[nx][ny] += diffuse;
                count++;
            }
        }

        dust[x][y] = dust[x][y] - diffuse * count;
    }

    void top_clean() {
        // 아래
        int temp1 = map[x1][c-1];
        for(int i=c-1; i > 1; i--) {
            map[x1][i] = map[x1][i-1];
        }

        // 오른쪽
        int temp2 = map[0][c-1];
        for(int i=0; i<x1-1; i++) {
            map[i][c-1] = map[i+1][c-1];
        }
        map[x1-1][c-1] = temp1;

        // 위쪽
        int temp3 = map[0][0];
        for(int i=0; i<c-2; i++) {
            map[0][i] = map[0][i+1];
        }
        map[0][c-2] = temp2;

        // 왼쪽
        for(int i=x1; i > 1; i--) {
            map[i][0] = map[i-1][0];
        }
        map[1][0] = temp3;

        map[x1][1] = 0;
        map[x1][0] = -1;
    }

    void bottom_clean() {
        // 위
        int temp1 = map[x2][c-1];
        for(int i=c-1; i > 1; i--) {
            map[x2][i] = map[x2][i-1];
        }

        // 오른쪽
        int temp2 = map[r-1][c-1];
        for(int i=r-1; i > x2 + 1; i--) {
            map[i][c-1] = map[i-1][c-1];
        }
        map[x2+1][c-1] = temp1;

        // 아래 
        int temp3 = map[r-1][0];
        for(int i=0; i<c-2; i++) {
            map[r-1][i] = map[r-1][i+1];
        }
        map[r-1][c-2] = temp2;

        // 왼쪽
        for(int i=x2; i<r-2; i++) {
            map[i][0] = map[i+1][0];
        }
        map[r-2][0] = temp3;

        map[x2][1] = 0;
        map[x2][0] = -1;
    }


    void diffusion() {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(map[i][j] > 0) {
                    calculate_dust(i, j);
                }
            }
        }

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                map[i][j] += dust[i][j];
            }
        }

        init();
    }

    void print_map() {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
    }

    int check_dust() {
        int count = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(map[i][j] != -1) {
                    count += map[i][j];
                }
            }
        }
        return count;
    }


    int main() { 
        init();

        cin >> r >> c >> t;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                int input;
                cin >> input;

                if(input == -1) {
                    if(x1 > 0) {
                        x2 = i;
                    } else {
                        x1 = i;
                    }
                }
                    
                map[i][j] = input;
            }
        }

        for(int i=0; i<t; i++) {
            diffusion();
            top_clean();
            bottom_clean();
        }

        cout << check_dust();
    }