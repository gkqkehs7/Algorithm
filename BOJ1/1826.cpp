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

    sort(station, station + n);
    priority_queue<pair<int, int>> pq;

    int start = 0;
    int idx = 0;
    bool cango = true;
    while(start + oil < total) {

        while(idx < n && station[idx].first <= start + oil) {
            pq.push({ station[idx].second, station[idx].first });
            idx++;
        }

        oil = oil - ( pq.top().second - start ) + pq.top().first;
        start = pq.top().second;
        pq.pop();
        
        cout << "start: " << start << " oil: " << oil << " 다음 주유소: " << station[idx].first << "\n";
        while(!pq.empty() && idx < n && start + oil < station[idx].first) {
            cout << "한번에 못가므로 이전 주유소를 들립니다 " << pq.top().first << " oil추가\n";
            oil += pq.top().first;
            pq.pop();
        }
        
        if(start + oil < station[idx].first) {
            cango = false;
        }
    }

    cout << cango;
  
}