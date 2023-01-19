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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start = 0;
    int count = 0;
    int idx = 0;
    bool cango = true;
    while(start + oil < total) {   
        // cout << "start: " << start << " oil: " << oil << "\n";
        int max_oil = 0;
        int max_station_loc = 0;
        int max_station_idx = 0; 
        int station_num = 0;
        while(idx < n && station[idx].first <= start + oil) {
            if(station[idx].second > max_oil) {
                max_oil = station[idx].second;
                max_station_loc = station[idx].first;
                max_station_idx = idx;
            }
            station_num++;
            idx++;
        }
        
        if(station_num == 0) {
            cango = false;
            break;
        }
        oil = oil - (max_station_loc- start) + max_oil;
        start = max_station_loc;
        idx = max_station_idx + 1;
        count++;
    }

    if(cango) {
        cout << count;
    } else {
        cout << -1;
    }
  
}