# 우선 탐색하려는 수가 매우 크므로 이분 탐색을 염두하여햐 하는 것은 당연하다..
# 탐색 할것이 너무 많다.. -> 반으로 줄여서 탐색 할 수는 없을까?
# target을 설정할 수 있는가?
# 이진탐색은 범위를 좁혀가며 계속 target 값에 접근하는 방식이다
# 1부터20까지 다써서 길이를 확인할 수 없다 -> 10까지만 탐색해서 조건에 맞는지 탐색 가능하지 않는가?
import sys
input = sys.stdin.readline

n, m = map(int, input().split())


def get_len(number):
    temp = len(str(number))
    result = 0
    for i in range(1, temp):
        result += (10 ** i - 10 ** ( i- 1 )) * i
        
    result += (number - (10 ** (temp-1)) + 1) * temp
    return result


if get_len(n) < m:
    print(-1)
else:
    start = 0
    end = n;
    mid = 0 
    while start <= end:
        
        mid = (start + end) // 2
        
        temp = get_len(mid)
        if temp == m:
            break
        
        if temp < m: 
            start = mid + 1
            
        elif temp > m:
            end = mid - 1
            
    diff = get_len(mid) - m
    print(str(mid)[-(diff+1)])
