#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
    if(a.first.second > b.first.second) { // 금 
        return true;
    } else if(a.first.second == b.first.second) { // 은 
         if (a.second.first > b.second.first) {
            return true;
         } else if(a.second.first == b.second.first) { // 동
            if(a.second.second > b.second.second) {
                return true;
            } else if(a.second.second == b.second.second) { // 금 은 동 개수가 모두 같다면 알고 싶은 나라 k가 가장 앞으로 오게한다
                return a.first.first == k; 
            }
         }
    }
    return false;
}


int main() {
   
    cin >> n >> k;

    pair<pair<int, int>, pair<int, int>> medal[1001];

    for(int i=0; i<n; i++) {
        // 나라번호 / 금 / 은 / 동 
        cin >> medal[i].first.first >> medal[i].first.second >> medal[i].second.first >> medal[i].second.second;
    }    

    sort(medal, medal + n, compare);

    for (int i = 0; i < n; i++) {
        if(medal[i].first.first == k) {
            cout << i + 1 << "\n";
            break;
        }
    }
    
}