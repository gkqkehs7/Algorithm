# deque는 양 끝 엘리먼트의 append와 pop이 압도적으로 빠르다.
# 컨테이너(container)의 양끝 엘리먼트(element)에 접근하여 
# 삽입 또는 제거를 할 경우, 일반적인 리스트(list)가 
# 이러한 연산에 O(n)이 소요되는 데 반해, 데크(deque)는 O(1)로 접근 가능하다.
# 양끝 연산을 수행해줄 떄는 deque를 사용해보자

import sys
from collections import deque

N = int(sys.stdin.readline().rstrip())

def important():
    number, target_cursor = input().split()
    number = int(number);
    target_cursor = int(target_cursor)
    arr = deque(map(int, input().split()));

    print_num = 0;
    while True:
        if(target_cursor == 0):
            if(arr[0] == max(arr)):
                print(print_num + 1)
                break;
            else:
                arr.append(arr.popleft())
                target_cursor = target_cursor + len(arr) - 1;
        
        if(arr[0] != max(arr)):
            arr.append(arr.popleft())
            target_cursor = target_cursor - 1;
        else:
            arr.popleft()
            print_num = print_num + 1;
            target_cursor = target_cursor - 1;
      
for n in range(N):
    important()