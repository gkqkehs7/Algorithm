# 이진탐색의 목적은 답을 맞추는 것이 아닌 탐색 범위를 줄이는것에 있다
# 이진탐색을 하기 위해선 그 기준을 설정하는게 매우 중요하다
# 반으로 자를 것이냐 투포인터를 쓸것이냐는 그 다음이다
import sys 
input = sys.stdin.readline

r, c = map(int, input().split())

arrs = []
for _ in range(r):
    arrs.append(input().rstrip())
    
    
start = 0
end = r
max_count = 0
#코드는 짯는데 종료 조건을 모르겠다
while start <= end:
    
    mid = (start+end) // 2
    strs = []
    for j in range(c):
        str = ''
        for i in range(mid, r):
            str += arrs[i][j]
        strs.append(str)
            
    if len(strs) == len(set(strs)):

        if mid > max_count:
            max_count = mid
        start = mid + 1
        
    else:
        end = mid - 1
    

print(max_count)