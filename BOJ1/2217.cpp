#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }

    int max = 0;
    while(!pq.empty()) {
        int now = pq.top();
        int pq_size = pq.size();

        if(now * pq_size > max) {
            max = now * pq_size;
        }
        pq.pop();
    }

    cout << max;
}

