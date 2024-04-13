    #include <iostream>
    #include <queue>
    using namespace std;

    int n, m, k;
    int map[21][21];
    int dice[6] = { 2, 1, 5, 6, 4, 3 };
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    int x = 0;
    int y = 0;
    int direction = 0; // 동 남 서 북
    int score = 0;

    void roll_dice(int d) {
        if(d == 0) {
            int temp = dice[5];
            dice[5] = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[3];
            dice[3] = temp;
        } else if(d == 1) {
            int temp = dice[3];
            dice[3] = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[0];
            dice[0] = temp;
        } else if(d == 2) {
            int temp = dice[5];
            dice[5] = dice[3];
            dice[3] = dice[4];
            dice[4] = dice[1];
            dice[1] = temp;
        } else if(d == 3) {
            int temp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[3];
            dice[3] = temp;
        }
    }

    int change_direction(int d) {
        if(d == 0) return 2;
        if(d == 1) return 3;
        if(d == 2) return 0;
        if(d == 3) return 2;
    }

    int rotate_direction(int d, int nx, int ny) {
        cout << dice[1] << " " << map[nx][ny] << "\n";
        if(dice[1] > map[nx][ny]) {
            d = (d + 1) % 4;
        } else if(dice[1] < map[nx][ny]) {
            d = (d + 3) % 4;
        }
        return d;
    }

    int check_path(int nx, int ny) {
        if(nx >= n || nx < 0 || ny >= m || ny < 0 ) {
            return false;
        }

        return true;
    }

    int bfs(int x, int y) {
        
        int visited[21][21] = { false, };
        int b = map[x][y];
        queue<pair<int, int>> q;
        q.push({ x, y });
        visited[x][y] = true;
        int count = 0;

        while(!q.empty()) {
            int now_x = q.front().first;
            int now_y = q.front().second;
            q.pop();

            count++;
         
            for(int i=0; i<4; i++) {
                int next_x = now_x + dx[i];
                int next_y = now_y + dy[i]; 
                
                if(check_path(next_x, next_y) && map[next_x][next_y] == b && visited[next_x][next_y] == false) {
                    visited[next_x][next_y] = true;
                    q.push({ next_x, next_y });
                }
            }
        }

        return count;
    }


    int main() {
        cin >> n >> m >> k;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> map[i][j];
            }
        }

        for(int i=0; i<k; i++) {    
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            // 1. 이동방향 대로 굴러간다  
            if(check_path(nx, ny)) {
                x = nx;
                y = ny;
            } else {
                direction = change_direction(direction);
                x = x + dx[direction];
                y = y + dy[direction];
            }

            // 2. 굴러가는대로 주사위 회전
            roll_dice(direction);

            cout << x << " " << y << " " << direction << "\n";

            // for(int j=0; j<6; j++) {
            //     cout << dice[j] << " ";
            // }
            // cout << "\n";

            // 3. 점수 획득
            score += map[x][y] * bfs(x, y);

            // 4. 아래칸과 점수 비교
            direction = rotate_direction(x, y, direction);
        }

        cout << score;
    }