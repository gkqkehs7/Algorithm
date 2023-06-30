#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;

    for(int i=1; i<=n; i++) {
        dq.push_back(i);
    }

    while(dq.size() > 1) {
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }

    cout << dq.front();
}