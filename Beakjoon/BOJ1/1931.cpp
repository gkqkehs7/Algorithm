#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({ end, start });
    }
    sort(v.begin(), v.end());

    int prev_end = v[0].first;
    int count = 0;
    
    for(int i=1; i<v.size(); i++) {
        int now_start = v[i].second;

        if(prev_end <= now_start) {
            // cout << prev_end << " " << v[i].first << "\n";
            prev_end = v[i].first;
            count++;
        }
    }

    cout << count + 1;
}