# 왜 날짜를 세주지 않는지 고민하라

import sys
from collections import deque
input = sys.stdin.readline

m, n = map(int, input().split())
maps = []

for _ in range(n):
    maps.append(list(map(int, input().split())))
    
tomatos = []
ripe = 0
for i in range(n):
    for j in range(m):
        if maps[i][j] == 1:
            tomatos.append((i,j))
        elif maps[i][j] == 0:
            ripe += 1
            
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs():
    q = deque()
    
    for tomato in tomatos:
        q.append((tomato[0],tomato[1]))
    
    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx >= n or nx < 0 or ny >= m or ny < 0:
                continue
            
            if maps[nx][ny] == -1:
                continue
            
            if maps[nx][ny] == 0:
                maps[nx][ny] = maps[x][y] + 1
                q.append((nx,ny))
            
if ripe == 0:
    print(0)
else:
    bfs()
    can_ripe = True
    max = 0
    for i in range(n):
        for j in range(m):
            if maps[i][j] > max:
                max = maps[i][j]
                
            if maps[i][j] == 0:
                can_ripe = False
                break;
    
    if can_ripe == False:
        print(-1)
    else:
        print(max-1)