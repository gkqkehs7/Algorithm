#include <iostream>
using namespace std;

int n;
int visited[8][8] = {0};


void dfs(int depth) {
    for(int i=0; i<n; i++) {
        checkVisited(i);
    }
}

int main() {
    cin >> n;

    dfs(1);
}