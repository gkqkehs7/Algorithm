#include <iostream>
#include <cmath>
#include <set>

using namespace std;
pair<int, int> map[100001];
set<pair<int, int>> s;
int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert({ x, y });
        map[i].first = x;
        map[i].second = y;
    }

    long long ans = 1000000000;
    for(int i=0; i < n; i++) {
        for(int j=i+1; j<n; j++) {
            int x_dis = abs(map[j].first - map[i].first);
            int y_dis = abs(map[j].second - map[i].second);

            if(pow(x_dis,2) + pow(y_dis,2) < ans) {
                ans = pow(x_dis,2) + pow(y_dis,2);
            }
        }
    }

    cout << ans;
}