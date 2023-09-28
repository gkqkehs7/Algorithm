#include <iostream>
#include <stack>

using namespace std;

int main() {

    int n;
    cin >> n;

    int hei[80001];
    long long see[80001];
    stack<pair<int, int>> s;

    for(int i=0; i<n; i++) cin >> hei[i];

    s.push({hei[n-1], n-1});
    see[n-1] = 0;

    for(int i=n-2; i>=0; i--) {

        int now = hei[i];   
        int temp = 0;

        while(s.size() > 0 && s.top().first < now) {

            // cout << now << " " << s.top().first << " " << see[s.top().second] << "\n";

            temp += see[s.top().second] + 1;

            s.pop();
        }

        see[i] = temp;

        s.push({ now, i });
    }

    long long answer = 0;

    for(int i=0; i<n; i++) answer += see[i];

    cout << answer;


}