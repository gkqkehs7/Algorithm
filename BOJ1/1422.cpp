#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
pair<string,int> arr[51];
vector<pair<string,int>> v;

bool compare(pair<string,int> a, pair<string,int> b) {
    if(stoi(a.first) % 10 == 0 && stoi(b.first) % 10 == 0)
    return a.first > b.first;
}
int main() {
    int k, n;
    cin >> k >> n;

    int max_len = 1;
    string max_str = "";
    for(int i=0; i<k; i++) {
        string input;
        cin >> input;
        arr[i].first = input;
        arr[i].second = input.length();

        if(input.length() > max_len) {
            max_len = input.length();            
        }
    }
    sort(arr, arr + k, compare);

    for(int i=0; i<k; i++) {
       if(arr[i].second == max_len) {
            v.push_back({ arr[i].first, i });
       }
    }
    sort(v.begin(), v.end(), greater<pair<string, int>>());
    int max_idx = v[0].second;

    string ans = "";
    for(int i=0; i<k; i++) {
        if(i == max_idx) {
            for(int j=0; j<n - k + 1; j++) {
                ans += arr[i].first;
            }
        } else {
            ans += arr[i].first;
        }
    }
    
    cout << ans;
}