#include <iostream>
using namespace std;

int n, m;
int lights[100001];

bool check(int light_len) {
    int street[100001];

    int start = 0;
    for(int i=0; i<m; i++) {
        if(lights[i] - light_len <= start) {
            start = lights[i] + light_len;
        } else {
            return false;
        }
    }

    if(start < n) {
        return false;
    }

    return true;
}

int main() {
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> lights[i];
    }

    int start = 0;
    int end = n;
    int answer = 0;
    while(start <= end) {
        int mid = (start + end) / 2;

        if(check(mid)) {
            end = mid - 1;
            answer = mid;
        } else {
            start = mid + 1;
        }
    }

    cout << answer;
}