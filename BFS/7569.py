import sys
from collections import deque
input = sys.stdin.readline

m, n, h = map(int, input().split())

maps = [[] for depth in range(h)]
for i in range(h):
    for j in range(n):
        maps[i].append(list(map(int, input().split())))
        
tomatos = []
zero_count = 0
for i in range(h):
    for j in range(n):
        for k in range(m):
            if maps[i][j][k] == 1:
                tomatos.append((i,j,k))
            elif maps[i][j][k] == 0:
                zero_count += 1
           
dz = [-1,1,0,0,0,0]
dx = [0,0,-1, 1, 0, 0]
dy = [0,0,0, 0, -1, 1]
def bfs():
    q = deque()
    
    for tomato in tomatos:
        q.append((tomato[0], tomato[1], tomato[2]))
        
    while q:
        z,x,y = q.popleft()   
        
        for i in range(6):
            nz = z + dz[i]
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nz>=h or nz <0 or nx >= n or nx < 0 or ny >= m or ny < 0:
                continue   
            
            if maps[nz][nx][ny] == -1:
                continue
            
            if maps[nz][nx][ny] == 0:
                maps[nz][nx][ny] = maps[z][x][y] + 1
                q.append((nz,nx,ny))
        
if zero_count == 0:
    print(0)
else:
    bfs()
    can_ripe = True
    max = 0
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if maps[i][j][k] > max:
                    max = maps[i][j][k]
                
                if maps[i][j][k] == 0:
                    can_ripe = False
                    break;
                                
    if can_ripe == False:
        print(-1)
    else:
        print(max-1)
