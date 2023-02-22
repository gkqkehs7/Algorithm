#include <iostream>
using namespace std;

int arr1[500001];
int arr2[1000001];
int tree[500001*4];

long long get_sum(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return 0;
    else if(start >= left && end <= right) return tree[node];
    else {
        int mid = (start + end) / 2;
        return get_sum(node * 2, start, mid, left, right) + get_sum(node * 2 + 1, mid + 1, end, left, right);
    }
}

void update(int node, int start, int end, int target_idx) {
    if(start > target_idx || end < target_idx) return;

    if(start == end) {
        tree[node] = 1;
        return;
    }
  
    int mid = (start + end) / 2;
    update(node * 2, start, mid, target_idx);
	update(node * 2 + 1, mid + 1, end, target_idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
       cin >> arr1[i];
    }

    for(int i=1; i<=n; i++) {
        int input;
        cin >> input;
        arr2[input] = i;
    }

    long long ans = 0;
    for(int i=1; i<=n; i++) {
        ans += get_sum(1, 1, n, arr2[arr1[i]] + 1, n);
        update(1, 1, n, arr2[arr1[i]]);
    }

    cout << ans;
}