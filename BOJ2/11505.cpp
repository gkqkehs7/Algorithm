#include <iostream>
using namespace std;

int arr[1000001];
long long tree[4000004];

long long segment_tree(int node, int start, int end) {
    if(start == end) return tree[node] = arr[start];
    int mid = ( start + end ) / 2;
    return tree[node] = segment_tree(node * 2, start, mid) * segment_tree(node * 2 + 1, mid + 1, end) % 1000000007;
}

long long get_multi(int node, int start, int end, int target_start, int target_end) {
    if(start > target_end || end < target_start) return 1;
    else if(target_start <= start && target_end >= end) return tree[node];
    else {
        int mid = ( start + end ) / 2;
        return get_multi(node * 2, start, mid, target_start, target_end) * get_multi(node * 2 + 1, mid + 1, end, target_start, target_end) % 1000000007;
    }
}

long long update(int node, int start, int end, int target_index, int diff) {
   if(start > target_index || end < target_index) return 1;
   if(start == end) return tree[node] = diff;
   if(start != end) {
    int mid = (start+end) / 2;
    return tree[node] = update(node * 2, start, mid, target_index, diff) * update(node * 2 + 1, mid + 1, end, target_index, diff) % 1000000007;
   }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m ,k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) cin >> arr[i];
    segment_tree(1, 1, n);
 
    for(int i=0; i < m+k; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1) {
            update(1, 1, n, b, c);
        } else {
            cout << get_multi(1, 1, n, b, c) << "\n";
        }

    }
    
}