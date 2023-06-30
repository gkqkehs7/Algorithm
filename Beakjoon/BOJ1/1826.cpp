#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> station[10001];
int n, total, oil;
int main() {
 
    cin >> n;

    for(int i=0; i<n; i++) {
        int loc, station_oil;
        cin >> loc >> station_oil;
        station[i].first = loc;
        station[i].second = station_oil;
    }

    cin >> total >> oil;

    int left_oil = oil;
    int now = 0;
    sort(station, station + n);
    priority_queue<int> pq;
    
    int idx = 0;
    int count = 0;
    bool cango = true;
    while(oil < total) {
        while(idx < n && oil >= station[idx].first) {
            pq.push(station[idx].second);
            idx++;
        }

        if(pq.empty()) {
            cango = false;
            break;
        }

        oil += pq.top();
        pq.pop();
        count++;
    }
    
    if(cango) {
        cout << count;
    } else {
        cout << -1;
    }

}