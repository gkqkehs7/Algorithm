#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> arr[100001];
int main() {

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        long long start, end;
        cin >> start >> end;
        arr[i] = { end ,start };
    }

    sort( arr , arr + n );

    int prev = arr[0].first;
    for(int i=0; i<n; i++) {

    }
}