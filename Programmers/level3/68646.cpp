
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {

    int right_arr[a.size()];
    int left_arr[a.size()];

    int left_min_value = 1000000000;
    int right_min_value = 1000000000;

    for(int i=0; i<a.size(); i++) {
        if(a[i] < left_min_value) {
            left_min_value = a[i];
        }
        left_arr[i] = left_min_value;
    }

    for(int i=a.size() - 1; i >= 0; i--) {
        if(a[i] < right_min_value) {
            right_min_value = a[i];
        }
        right_arr[i] = right_min_value;
    }

    int answer = 0;

    for(int i=1; i<a.size() - 1; i++) {
        vector<int> temp;
        int left_min = left_arr[i-1];
        int right_min = right_arr[i+1];

        temp.push_back(left_min);
        temp.push_back(right_min);
        temp.push_back(a[i]);

        sort(temp.begin(), temp.end());

        if(temp[0] == a[i] || temp[1] == a[i]) {
            answer++;
        }
    }

    if(a.size() < 3) {
        answer = a.size();
    } else {
        answer += 2;
    }
    cout << answer;
    return answer;
}

int main() {
    vector<int> v = { -16,27,65,-2,58,-92,-71,-68,-61,-33 };
    solution(v);
}