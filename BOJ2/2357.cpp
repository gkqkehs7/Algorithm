#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int maxTree[400004];
int minTree[400004];

int max_segment_tree(int node, int start, int end) {
    if(start == end) return maxTree[node] = arr[start];

    int mid = ( start + end ) / 2;
    return maxTree[node] = max(max_segment_tree(node * 2, start, mid), max_segment_tree(node * 2 + 1, mid + 1, end));
}

int min_segment_tree(int node, int start, int end) {
    if(start == end) return minTree[node] = arr[start];

    int mid = ( start + end ) / 2;
    return minTree[node] = min(min_segment_tree(node * 2, start, mid), min_segment_tree(node * 2 + 1, mid + 1, end));
}

int get_max(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return 0; 
    else if(left <= start && end <= right) return maxTree[node];
    else {
        int mid = ( start + end ) / 2;
        return max(get_max(node * 2, start, mid, left, right), get_max(node * 2 + 1, mid + 1, end, left, right));
    }
}

int get_min(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return 1000000000; 
    else if(left <= start && end <= right) return minTree[node];
    else {
        int mid = ( start + end ) / 2;
        return min(get_min(node * 2, start, mid, left, right), get_min(node * 2 + 1, mid + 1, end, left, right));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> arr[i];
    max_segment_tree(1, 1, n);
    min_segment_tree(1, 1, n);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << get_min(1, 1, n, a, b) << " " << get_max(1, 1, n, a, b) << "\n";
    }
}