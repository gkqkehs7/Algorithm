import sys

input = sys.stdin.readline

n, target = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(int(input()))
arr.sort()

left, right = 0, 0
min_answer = int(2e9)

while True:
    
    diff =  arr[right] - arr[left]
    if diff >= target:
        if diff < min_answer:   
            min_answer = diff
        left += 1
    else:
        if right + 1 < len(arr):
            right +=1
        else:
            left += 1
    if left==len(arr)-1:
        break
    
print(min_answer)