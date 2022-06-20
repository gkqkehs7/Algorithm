import sys

input = sys.stdin.readline
n = int(input())


arr = []
for i in range(n):
    a,b = map(int,input().split())
    arr.append((a,b))
    

arr.sort(key = lambda x: x[0])
arr.sort(key = lambda x: x[1])

start = arr[0]
count = 1
for i in range(1, len(arr)):
    if arr[i][0] >= start[1]:
        start = arr[i]
        count += 1;

print(count)