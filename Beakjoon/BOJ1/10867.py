import sys

N = int(sys.stdin.readline().rstrip())

res = list(map(int, input().split()))  

res = list(set(res))
res.sort()

print(*(res), sep=' ')