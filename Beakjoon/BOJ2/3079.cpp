#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(unsigned long long time, vector<unsigned long long> gates, unsigned long long person_num) {

    unsigned long long total_num = 0;

    for(int i=0; i<gates.size(); i++) {
        unsigned long long gate = gates[i];

        unsigned long long person_num = time / gate;

        total_num += person_num;
    }

    if(total_num < person_num) {
        return false;
    }

    return true;
}

unsigned long long binary_search(unsigned long long left, unsigned long long right, vector<unsigned long long> gates, unsigned long long person_num) {
    
    unsigned long long min_value = right;
    
    while(left <= right) {
        unsigned long long mid = (left + right) / 2;

        if(check(mid, gates, person_num)) {
            right = mid - 1;
            min_value = min(min_value, mid);
        } else {
            left = mid + 1;
        }
    }

    return min_value;
}

int main() {
    unsigned long long n, m;
    cin >> n >> m;

    vector<unsigned long long> gates;

    for(int i=0; i<n; i++) {
        unsigned long long input;
        cin >> input;
        gates.push_back(input);
    }

    sort(gates.begin(), gates.end());

    // auto min_time_gate = min_element(gates.begin(), gates.end());

    unsigned long long left = 0;
    unsigned long long right = gates[0] * m;

    cout << binary_search(left, right, gates, m);
}