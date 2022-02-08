import sys

N = int(sys.stdin.readline().rstrip())

res = []
for n in range(N):
    res.append(sys.stdin.readline().rstrip())

res = list(set(res)) #중복 정렬

res.sort()
res.sort(key = lambda x:len(x))

for res in res:
    print(res)
