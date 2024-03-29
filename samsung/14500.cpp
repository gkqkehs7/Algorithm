#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;

int main() {
    int n, m;
    cin >> n >> m;

    int answer = 0;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        map.push_back(temp);
    }

    // case1
    for(int i=0; i<n; i++) {
        for(int j=0; j<m-3; j++) {
            int temp = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
            answer = max(answer, temp);
        }
    }

    // case2
    for(int i=0; i<n-3; i++) {
        for(int j=0; j<m; j++) {
            int temp = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
            answer = max(answer, temp);
        }
    }


    // case3
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j] + map[i][j+1] + map[i+1][j] + map[i+1][j+1];
            answer = max(answer, temp);
        }
    }
    
    // case4
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
            answer = max(answer, temp);
        }
    }


    // case5
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-2; j++) {
            int temp = map[i][j] + map[i+1][j] + map[i][j+1] + map[i][j+2];
            answer = max(answer, temp);
        }
    }

    // case6
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+2][j];
            answer = max(answer, temp);
        }
    }

    // case6
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j+1];
            answer = max(answer, temp);
        }
    }

    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
            answer = max(answer, temp);
        }
    }

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-2; j++) {
            int temp = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
            answer = max(answer, temp);
        }
    }


    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-2; j++) {
            int temp = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+2];
            answer = max(answer, temp);
        }
    }

    // case7
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-2; j++) {
            int temp = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
            answer = max(answer, temp);
        }
    }

    // case8
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
            answer = max(answer, temp);
        }
    }

    // case9
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j+1] + map[i+1][j+1] + map[i+1][j] + map[i+2][j];
            answer = max(answer, temp);
        }
    }

    // case10
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-2; j++) {
            int temp = map[i+1][j] + map[i+1][j+1] + map[i][j+1] + map[i][j+2];
            answer = max(answer, temp);
        }
    }

    // case11
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-2; j++) {
            int temp = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
            answer = max(answer, temp);
        }
    }

    // case12
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-2; j++) {
            int temp = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
            answer = max(answer, temp);
        }
    }

    // case13
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-2; j++) {
            int temp = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+1];
            answer = max(answer, temp);
        }
    }

    // case14
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
            answer = max(answer, temp);
        }
    }

    // case15
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-1; j++) {
            int temp = map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+1][j];
            answer = max(answer, temp);
        }
    }
    cout << answer;
}