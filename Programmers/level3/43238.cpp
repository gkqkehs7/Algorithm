#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 어떤 값을 기준으로 이분 탐색을 해야하는가?
long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    
    long long start = 1;
    long long end = (long long) times[times.size() - 1] * n;
    long long mid = 0;
    
    long long answer = 0;
    
    while(start <= end) {
        mid = (start + end) / 2;
        
        long long sum = 0;
        for (int i = 0; i < times.size(); i++) { 
            sum += mid / times[i];
        }   
        
        if(sum < n) { // 인원수를 충족하지 못한 경우
            start = mid + 1;
        } else {
            answer = mid;
            end = mid - 1;
        }
    }
    
    return answer;
}