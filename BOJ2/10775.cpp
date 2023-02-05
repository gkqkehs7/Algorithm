#include <iostream>

using namespace std;
int gate_num, plane_num;
int gate[100001];
int plane[100001];

int get_parent(int child) {
    if(gate[child] == child) return child;

    return gate[child] = get_parent(gate[child]);
}

// void merge(int child1, int child2) {
//     if(get_parent(child1) == get_parent(child2)) return;
//     gate[child2] = child1;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> gate_num >> plane_num;
    
    for(int i=0; i<plane_num; i++) {
       cin >> plane[i];
    }

    for(int i=0; i<100001; i++) {
        gate[i] = i;
    }

    int ans = 0;
    for(int i=0; i<plane_num; i++) {
       int parent = get_parent(plane[i]);
       if(parent == 0) break;
       ans++;
       gate[parent] = parent - 1;
    }
    cout << ans << "\n";

    // for(int i=0; i<10; i++) {
    //     cout << gate[i] << " ";
    // }
}