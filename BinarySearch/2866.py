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
while 0 <= start < end:
    
    strs = []
    for j in range(c):
        str = ''
        for i in range(start, end):
            str += arrs[i][j]
        strs.append(str)
            
    if len(strs) == len(set(strs)):
        if start > max_count:
            max_count = start
        start = (start + end) // 2 + 1
        
    else:
        start = start // 2
        if start == 0:
            break
    
print(max_count)