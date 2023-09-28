#include <iostream>
#include <stack>

using namespace std;

int main() {

    int n;
    cin >> n;

    int hei[500001];
    int answer[500001];
    stack<pair<int, int>> s;

    for(int i=0; i<n; i++) cin >> hei[i];

    s.push({hei[n-1], n-1});
    answer[n-1] = 0;

    for(int i=n-2; i>=0; i--) {

        int now = hei[i];   
        int temp = 0;

        while(s.size() > 0 && s.top().first < now) {
            answer[s.top().second] = i + 1;
            s.pop();
        }
        s.push({ now, i });
    }

    for(int i=0; i<n; i++) {
        cout << answer[i] << " ";
    }

}