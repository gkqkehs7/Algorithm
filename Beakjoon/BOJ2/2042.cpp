#include <iostream>
#include <cmath>
using namespace std;
long long arr[1000001];
long long tree[4000004];

long long segment_tree(int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;
    return tree[node] = segment_tree(start, mid, node * 2) + segment_tree(mid + 1, end, node * 2 + 1);
}

long long sum(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return 0;  // 전혀 겹치지 않는 경우
    else if(left <= start && end <= right) return tree[node];
    else {
        int mid = (start + end) / 2;
        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid+1, end, left, right);
    }
}

void update(int change_index, long long diff, int node, int start, int end) {
    if(change_index < start || change_index > end) return;
    tree[node] += diff;

    if(start != end) {
        int mid = (start+end) / 2;
        update(change_index, diff, node*2, start, mid);
        update(change_index, diff, node*2+1, mid+1, end);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) cin >> arr[i];

    segment_tree(1, n, 1);
    
    for(int i=0; i < m + k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        if(a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            update(b, diff, 1, 1, n); 
            
        } else {
            cout << sum(1, 1, n, b, c) << "\n";
        }   
    }
}