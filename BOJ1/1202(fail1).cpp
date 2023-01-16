#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int bag[300001] = { 0, };
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_m;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int m, v;
        cin >> m >> v;
        pq_m.push({ m, v });
    }

    for(int i=0; i<k; i++){
        int c;
        cin >> c;
        bag[i] = c;
    }
    sort(bag, bag+k);

    long long sum = 0;
    for(int i=0; i<k; i++) {
        int max_wei = bag[i];

        priority_queue<pair<int, int>> pq_v;

        while(!pq_m.empty() && pq_m.top().first <= max_wei) {
            pq_v.push({ pq_m.top().second, pq_m.top().first });
            pq_m.pop();
        }
        
        if(!pq_v.empty()){ 
            sum += pq_v.top().first;
            pq_v.pop();
        }

        while(!pq_v.empty()) {
            pq_m.push({ pq_v.top().second, pq_v.top().first });
            pq_v.pop();
        }
    }
    cout << sum;
}