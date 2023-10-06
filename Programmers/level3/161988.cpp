#include <iostream>
#include <string>
#include <vector>

long long dp_a[500001];
long long dp_b[500001];
using namespace std;

long long solution(vector<int> sequence) {
    
    vector<long long> perse_a;
    vector<long long> perse_b;
    
    for(int i=0; i<sequence.size(); i++) {
        if(i % 2 == 0) {
            perse_a.push_back((long long)sequence[i]);
            perse_b.push_back((long long)-sequence[i]);
        } else {
            perse_a.push_back((long long)-sequence[i]);
            perse_b.push_back((long long)sequence[i]);
        }
    }
    // 2 3
    dp_a[0] = perse_a[0];
    dp_b[0] = perse_b[0];
    long long a_max = perse_a[0];
    long long b_max = perse_b[0];
    for(int i=1; i<sequence.size(); i++) {
        dp_a[i] = max(perse_a[i], dp_a[i-1] + perse_a[i]);
        dp_b[i] = max(perse_b[i], dp_b[i-1] + perse_b[i]);
        a_max = max(a_max, dp_a[i]);
        b_max = max(b_max, dp_b[i]);
    }
   
    long long answer = max(a_max, b_max);
    return answer;
}