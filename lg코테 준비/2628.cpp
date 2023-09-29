#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int wid, hei;
int n;
vector<int> wid_v;
vector<int> hei_v;
int main() {

    cin >> wid >> hei;

    cin >> n;

    for(int i=0; i<n; i++) {
        int type, num;

        cin >> type >> num;

        if(type == 1) {
            wid_v.push_back(num);
        } else {
            hei_v.push_back(num);
        }
    }

    sort(wid_v.begin(), wid_v.end());
    sort(hei_v.begin(), hei_v.end());


    int wid_start = 0;
    int max_wid = 0;
    for(int i=0; i<wid_v.size(); i++) {
        max_wid = max(max_wid, wid_v[i] - wid_start);
        wid_start = wid_v[i];
    }
    max_wid = max(max_wid, wid - wid_start);

    int hei_start = 0;
    int max_hei = 0;
    for(int i=0; i<hei_v.size(); i++) {
        max_hei = max(max_hei, hei_v[i] - hei_start);
        hei_start = hei_v[i];
    }
    max_hei = max(max_hei, hei - hei_start);

    cout << max_wid * max_hei;
}