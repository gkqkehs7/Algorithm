# bisect_right를 쓰지않는 이유는
# 오른쪽 index를 반환하는데 배열의 길이는 지정되어 있어서 out of range가 발생하기 때문
from bisect import bisect_left, bisect_right

n = int(input())
array = list(map(int, input().split()))
stack = [0]

for i in array:
    if stack[-1] < i:
        stack.append(i)
    else:
        stack[bisect_left(stack, i)] = i

print(len(stack)-1)