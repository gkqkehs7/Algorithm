#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
char cal[10];
int min_arr[10] = { 0, };
int max_arr[10] = { 0, };
string max_ans = "";
string min_ans = "";

int main() {
    int k;
    cin >> k;

    for(int i=0; i<k; i++) {
        char input;
        cin >> input;
        cal[i] = input;
    }

   for(int i=0; i<k + 1; i++) {
        min_arr[i] = i;
        max_arr[i] = 9 - i;
   }

   stack<int> s;
   
   // max
   for(int i=0; i<k; i++) {
    if(cal[i] == '>') {
        max_ans += max_arr[i] + '0';
        while(!s.empty()) {
            max_ans += s.top() + '0';
            s.pop();
        }
       
    } else {
        s.push(max_arr[i]);
    }

    if(i == k-1) {
        s.push(max_arr[k]);
    }
   }

    while(!s.empty()) {
        max_ans += s.top() + '0';
        s.pop();
    }

    // min
    for(int i=0; i<k; i++) {
        if(cal[i] == '<') {
            min_ans += min_arr[i] + '0';
            while(!s.empty()) {
                min_ans += s.top() + '0';
                s.pop();
            }
        
        } else {
            s.push(min_arr[i]);
        }

        if(i == k-1) {
            s.push(min_arr[k]);
        }
    }

    while(!s.empty()) {
        min_ans += s.top() + '0';
        s.pop();
    }
    cout << max_ans << "\n" << min_ans;
}