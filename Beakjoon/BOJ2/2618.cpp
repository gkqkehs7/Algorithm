#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<pair<int ,int>> v;
int map[1001][1001];

int main() {
    int n, w;
    cin >> n >> w;   
    
    for(int i=0; i<w; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    int p1_x, p1_y = 1;
    int p2_x, p2_y = n;

    int ans = 0;
    for(int i=0; i<v.size(); i++) {
        int target_x = v[i].first;
        int target_y = v[i].second;

        int case1 = abs(target_x - p1_x) + abs(target_y - p1_y);
        int case2 = abs(target_x - p2_x) + abs(target_y - p2_y);

        if(case1 < case2) {
            p1_x = target_x;
            p1_y = target_y;
            ans += case1;
        } else if(case1 > case2) {
            p2_x = target_x;
            p2_y = target_y;
            ans += case2;
        } else if(case1 == case2) {
            int ntarget_x = v[i+1].first;
            int ntarget_y = v[i+1].second;
        }
    }
}