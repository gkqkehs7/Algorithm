import sys

N = int(sys.stdin.readline().rstrip())

res = []
for n in range(N):
    res.append(list(map(int, input().split())))
 
res.sort()   

for re in res:
    print(*re, sep=' ') #print에 sep인자 넣어주면 sep기준으로 출력