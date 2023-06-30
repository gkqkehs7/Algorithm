#include <iostream>
#include <set>
using namespace std;

int arr[100001] = { 0, };
int main() {

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }

    multiset<int> s;
    multiset<int>::iterator iter;
    
    s.insert(arr[0]);
    iter = s.begin();
    int size = 1;
    cout << *iter << "\n";
    
    for(int i=1; i<n; i++) {
        int input = arr[i];

        s.insert(input);
        if(size % 2 == 0) { // 지금 개수가 짝수인 경우
            if(input >= *iter) {
                iter++;
            }
        } else { // 지금 개수가 홀수인 경우
            if(input < *iter) {
                iter--;
            }
        }

        cout << *iter << "\n";
        size++;
    }

}