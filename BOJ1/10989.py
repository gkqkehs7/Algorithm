import sys

N = int(sys.stdin.readline().rstrip())

arr = [0]*10001;

for n in range(N):
    temp = int(sys.stdin.readline().rstrip())
    arr[temp] = arr[temp]+1


for n in range(10001):
    if(arr[n] != 0):
        for j in range(arr[n]):
            print(n)