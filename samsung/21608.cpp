#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int students[401][4];
int map[21][21] = { 0, };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Sit { 
    int x;
    int y;
    int like;
    int empty;
};

bool check_path(int x, int y) {
    if(x >= n || x < 0 || y >= n || y < 0) {
        return false;
    }

    return true;
}

void print_map(vector<Sit> sits) {
    cout << "총 " << sits.size() << " 개\n";
    for(int i=0; i<sits.size(); i++) {
        cout << sits[i].x << " " << sits[i].y << " 좋아요" << sits[i].like << "개" << " 빈칸" <<sits[i].empty << "개\n";
    }
    cout << "\n";
}

vector<Sit> first_condition(int student) {
    vector<Sit> temp;

    // 비어있는 칸 중에서
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == 0) {
                temp.push_back({ i, j, 0, 0 });
            }
        }
    }

    // 자리 하나면 그냥 앉히고 끝내
    // if(temp.size() == 1) {
    //     map[temp[0].x][temp[0].y] = student;
    //     temp.pop_back();
    //     return temp;
    // }

    // print_map(temp);
        
    int max_like = 0;

    for(int i=0; i<temp.size(); i++) {
        int x = temp[i].x;
        int y = temp[i].y;
        int student_number = map[x][y];

        int empty = 0;
        int like = 0; 

        // 인접한 칸들
        for(int j=0; j<4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(check_path(nx, ny)) {
                
                // 좋아하는
                for(int k=0; k<4; k++) {

                    if(map[nx][ny] == students[student][k]) {
                        like++;
                    }
                }

                // 빈좌석
                if(map[nx][ny] == 0) {
                    empty++;
                }
            }
        }

        temp[i].empty = empty;
        temp[i].like = like;    
        max_like = max(max_like, like);
    }

    vector<Sit> temp2;

    for(int i=0; i<temp.size(); i++) {
        if(temp[i].like == max_like) {
            temp2.push_back(temp[i]);
        }
    }

    // print_map(temp2);

    return temp2;
}

vector<Sit> second_condition(vector<Sit> sits) {
    int max_empty = 0;
    
    for(int i=0; i<sits.size(); i++) {
        max_empty = max(max_empty, sits[i].empty);
    }

    vector<Sit> temp;

    for(int i=0; i<sits.size(); i++) {
        if(sits[i].empty == max_empty) {
            temp.push_back(sits[i]);
        }
    }

    // print_map(temp);

    return temp;
}

bool compare(Sit s1, Sit s2) {
    if(s1.x == s2.x) {
        return s1.y < s2.y;
    }

    return s1.x < s2.x;
}

void sit(int student) {
    // cout << student << "가 앉을 차례\n";

    vector<Sit> first = first_condition(student);

    // if(first.size() == 0) {
    //     return;
    // }

    if(first.size() == 1) {
        int x = first[0].x;
        int y = first[0].y;
        map[x][y] = student;
        return;
    }

    vector<Sit> second = second_condition(first);

    if(second.size() == 1) {
        int x = second[0].x;
        int y = second[0].y;
        map[x][y] = student;
        return;
    }

    sort(second.begin(), second.end(), compare);

    int x = second[0].x;
    int y = second[0].y;
    map[x][y] = student;
}

void calculate_score() {
    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int student = map[i][j];
            int like = 0;

            for(int k=0; k<4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(check_path(nx, ny)) {
                    // 좋아하는
                    for(int p=0; p<4; p++) {
                        if(map[nx][ny] == students[student][p]) {
                            like++;
                        }
                    }
                }
            }

            if(like == 0) {
                answer += 0;
            } else if(like == 1) {
                answer += 1;
            } else if(like == 2) {
                answer += 10;
            } else if(like == 3) {
                answer += 100;
            } else {
                answer += 1000;
            }
        }
    }
    
    cout << answer;
}

void print_all() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cin >> n;

    int order[401] = { 0, };

    for(int i=0; i<n * n; i++) {
        int number;
        cin >> number;

        order[i] = number;

        for(int j=0; j<4; j++) {
            int input;
            cin >> input;

            students[number][j] = input;
        }
    }

    for(int i=0; i<n * n; i++) {
        sit(order[i]);

        // print_all();
    }

    calculate_score();

}