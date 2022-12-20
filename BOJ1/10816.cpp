#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;

    int *card = new int[n];
    int *sang = new int[m];
    int *answer = new int[m];

    cin >> n;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        card[i] = input;
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        int input;
        cin >> input;
        sang[i] = input;
        answer[i] = 0;
    }

    int wall = 0;

    sort(card, card+n);
    sort(sang, sang+m);


    for(int i=0; i<m; i++) {
        
        while(wall < n) {
            if(card[wall] == sang[i]) {
                wall++;
                answer[i]++;
            } else if(sang[i] < card[wall]) {
                break;
            } else {
                wall++;
            }
        }
    }

    for(int i=0; i<m; i++) {
        cout << answer[i] << " ";
    }

}