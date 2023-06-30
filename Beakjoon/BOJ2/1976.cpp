#include <iostream>
using namespace std;
int n, m;

int road[201];
int destination[1001];

int get_parent(int child) {
    if(road[child] == child) return child;
    return  road[child] = get_parent(road[child]);
} 

void merge(int child1, int child2) {
    if(get_parent(child1) == get_parent(child2)) return;
    road[child2] = child1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<201; i++) {
        road[i] = i;
    }

    cin >> n;
    cin >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int input;
            cin >> input;

            if(input == 1 && i != j) {
                merge(i, j);
            }
        }
    }

    for(int i=0; i<m; i++) {
        int input;
        cin >> input;
        destination[i] = input;
    }
       
    bool cango = true;
    int root = get_parent(destination[0]);

    for(int i=1; i<m; i++) {   
        if(get_parent(destination[i]) != root) {
            cango = false;
            break;
        }
    }

    if(cango) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}