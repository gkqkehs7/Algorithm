#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;

        if(input == 0) {
            if(pq.size() == 0) {
                cout << "0\n";
            } else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        } else {
            pq.push({ abs(input), input });
        }
    }
}

