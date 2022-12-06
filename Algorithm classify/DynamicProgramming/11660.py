import sys
input = sys.stdin.readline

n, m = map(int, input().split())

maps = [[0]*(n+1)]
for _ in range(n):
    maps.append([0] + list(map(int, input().split())))
    
for i in range(n+1):
    for j in range(1,n+1):
        maps[i][j] = maps[i][j-1] + maps[i][j]

for i in range(1,n+1):
    for j in range(n+1):
        maps[i][j] = maps[i-1][j] + maps[i][j]
        
results = []
for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    
    print(maps[x2][y2] - (maps[x1-1][y2] + maps[x2][y1-1] - maps[x1-1][y1-1]))
    

