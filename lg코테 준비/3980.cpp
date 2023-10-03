#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int test;
    cin >> test;

    while(test--) {

        vector<pair<int, int>> graph[11];
        int score[11][11];
        int visited[11];
        for(int i=0; i<11; i++) {
            for(int j=0; j<11; j++) {
                cin >> score[i][j];

                if(score[i][j] != 0) {
                    graph[i].push_back({ j, score[i][j] });
                }
            }

            visited[i] = false;
        }

        queue<int> q;
    }



}