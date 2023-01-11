#include <iostream>
#include <algorithm>
using namespace std;

int trees[1000001] = { 0, };
int n, m;
long long answer = 0;
void binary_search(int start, int end, int target) {

    // cout << "start: " << start << " end:" << end << "\n";

    if(start > end) return;

    int mid = (start+end) / 2;
    long long temp = 0;

    for(int i=0; i<n; i++) {
        if(mid < trees[i]) {
            temp += trees[i]- mid;
        }
    }
    // cout << "temp: " << temp << "\n";

    if(temp >= target) {
        if(mid > answer) {
            answer = mid;
        }
        
        // cout << "mid: " << mid;
        binary_search(mid + 1, end, m); 
    } else {
        binary_search(start, mid - 1, m);
    }


}

int main() {
    
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        trees[i] = input;
    }
    sort(trees, trees +n);

    binary_search(0, trees[n-1], m);

    cout << answer;
}