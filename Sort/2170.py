import sys
from collections import deque
input = sys.stdin.readline

n = int(input())

q = []
for _ in range(n):
    x, y = map(int, input().split())
    q.append((x,y))
    
q = sorted(q, key = lambda x : (x[0], x[1]))
q = deque(q)

result = 0
start, end = q.popleft()

while q:
    x1, x2 = q.popleft()
    
    if end >= x1:
        if end < x2:
            end = x2
    else:
        result += end-start
        start = x1
        end = x2
        
print(result + end - start)