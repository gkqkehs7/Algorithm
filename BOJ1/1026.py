import sys

N = int(sys.stdin.readline().rstrip())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort(reverse=True)

result = 0 
for n in range(N):
    result = result + A[n]*B[n]

print(result)