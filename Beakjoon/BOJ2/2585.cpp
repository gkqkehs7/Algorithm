#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> stations;
int visited[1001];
int n, k;

struct Station {
    int x;
    int y;
    int cur;
};

void Init() {
    for(int i=0; i<1001; i++) visited[i] = false;
}

// 거리에 비례한 연료 구하기
double get_fuel(int x1, int y1, int x2, int y2) {
    double distance = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    
    if(distance < 10) {
        return 1;
    }

    double remainder = fmod(distance, 10);

    if(remainder == 0) {
        return distance / 10;
    }

    return int(distance / 10) + 1;
}

bool bfs(int fuel) {

    Init();

    queue<Station> q;

    q.push({ 0, 0 });

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cur = q.front().cur;

        q.pop();

        if(fuel >= get_fuel(x, y, 10000, 10000)) {
            return true;
        }

        if (cur == k + 1) {
            continue;
        }
			
        for(int i=0; i<stations.size(); i++) {
            int nx = stations[i].first;
            int ny = stations[i].second;

            if(get_fuel(x, y, nx, ny) <= fuel && visited[i] == false) {
                visited[i] = true;
                q.push({ nx, ny, cur + 1 });
            }
        }
    }

    return false;
}

int binary_serach() {

    int start = 0;
    int end = 1500;
    int ans = 1500;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(bfs(mid)) {
            end = mid - 1;
            ans = min(mid, ans);
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
   
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        stations.push_back(make_pair(x, y));
    }


    cout << binary_serach();
}