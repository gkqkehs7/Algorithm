import sys

N = int(sys.stdin.readline().rstrip())

res = []
for n in range(N):
    temp = list(map(int, input().split()))
    temp.reverse()
    res.append(temp)

#reversed는 reverse와 다르게 reversed 객체를 반환하기 때문에 sort사용 불가하다
res.sort()
   

for re in res:
    print(*reversed(re), sep=' ')