#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, score, p;  
    cin >> n >> score >> p;  

    int arr[52];
    int ranks[52];

    for(int i=0; i<n; i++) cin >> arr[i];

    int place = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] >= score) {
            place++;
        }
    }

    if(place + 1 > p) {
        cout << -1;
    } else {
         for(int i=n; i >= place; i--) {
        arr[i] = arr[i-1];
        }
        arr[place] = score;

        int rank = 1;
        int dup = 0;
        int prev = arr[0];
        ranks[0] = 1;

        for(int i=1; i<=n; i++) {
            if(prev == arr[i]) {
                ranks[i] = rank;
                dup++;
            } else {
                rank = rank + dup + 1;
                ranks[i] = rank;
                dup = 0;
            }   
            prev = arr[i];   
        }
        
        // for(int i=0; i<=n; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << "\n";

        // for(int i=0; i<=n; i++) {
        //     cout << ranks[i] << " ";
        // }
        // cout << "\n";
        
        cout << ranks[place];
    }

   
}   