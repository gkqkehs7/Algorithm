#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int bag[300001] = { 0, };
multimap<int, int> mm;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int m, v;
        cin >> m >> v;
        mm.insert({ m, v });
    }

    for(int i=0; i<k; i++){
        int c;
        cin >> c;
        bag[i] = c;
    }
    sort(bag, bag+k);

    long long sum = 0;
    for(int i=0; i<k; i++) {
        int bag_wei = bag[i];
        int max_value = -1;
        bool find = false;

        if(!mm.empty()) {
            multimap<int, int>::iterator iter = mm.begin();
            // cout << iter->first << " " << iter->second << "\n";
            multimap<int, int>::iterator to_erase;

            while(iter != mm.end() && iter->first <= bag_wei) {
                if(iter->second > max_value) {
                    max_value = iter->second;
                    to_erase = iter;
                }
                iter++;
            }

            if(max_value != -1) {
                // cout << to_erase ->first << " " << to_erase->second <<"\n";
                sum += to_erase -> second;  
                mm.erase(to_erase);
            }
            
        }
       
    }
    cout << sum;
}