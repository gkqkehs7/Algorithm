#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    
    vector<tuple<int, int, int>> tp;

    for(int i=0; i<n; i++) {
        
        int state_num;
        cin >> state_num;

        int arr[3];
        for(int i=0; i<3; i++) {
            cin >> arr[i];
        }

        tp.push_back({arr[0], arr[1], arr[2]});
        // tp[state_num] = make_tuple(arr[0], arr[1], arr[2]);
    }    

    sort(tp.begin(), tp.end());

    for(int i=0; i<n; i++)  {
        cout << get<0>(tp[i]) << " " << get<1>(tp[i]) << " " << get<2>(tp[i]) << "\n";
    }
    
}