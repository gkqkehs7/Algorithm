#include <iostream>
using namespace std;

int set[1000001];

int find_parent(int child) {
    int next = set[child];

    if(next == -1) return child;
    
    int parent = find_parent(next);
    set[child] = parent;
    return parent;
    
}

void merge(int a, int b) {
    int a_parent = find_parent(a);
    int b_parent = find_parent(b);
    if(a_parent == b_parent) return;
    set[a_parent] = b_parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<1000001; i++) {
        set[i] = -1;
    }

    for(int i=0; i<m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if(cmd == 0) {
           merge(a,b);
        } else if(cmd == 1) {
            if(find_parent(a) == find_parent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';

        }
    }
}