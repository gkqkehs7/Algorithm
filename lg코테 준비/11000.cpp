#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>>pq;

    for(int i=0; i<n; i++) {
        int start, end;

        cin >> start >> end;

        v.push_back({ start, end });
    }

    sort(v.begin(), v.end());

    pq.push(v[0].second);

    for(int i=1; i<n; i++) {
        int next_start = v[i].first;
        int next_end = v[i].second;

        int prev_end = pq.top();

        if(next_start >= prev_end) {
            pq.pop();
            pq.push(next_end);
        } else {
            pq.push(next_end);
        }
    }

    cout << pq.size();

}