#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000001];
    int answer[1000001];
    stack<pair<int, int>> s;

    for(int i=0; i<1000001; i++) answer[i] = -1;
    for(int i=0; i<n; i++) cin >> arr[i];

    s.push({ arr[0], 0 });

    for(int i=1; i<n; i++) {
        int now = arr[i];

        while(s.size() > 0 && s.top().first < now) {
            answer[s.top().second] = now;
            s.pop();
        }

        s.push({ now, i });
    }

    for(int i=0; i<n; i++) cout << answer[i] << " ";
}