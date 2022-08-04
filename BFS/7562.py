import sys
from collections import deque

input = sys.stdin.readline
n = int(input())

answers = []
dx = [2, 1, -2, -1, 2, 1, -2, -1]
dy = [1, 2, 1, 2, -1, -2, -1, -2]

def bfs(night_x, night_y):
        q = deque()
        q.append((night_x, night_y))
        
        while q:
            x, y = q.popleft()
            stop = False
            
            for i in range(8):
                nx = x + dx[i]
                ny = y + dy[i]
                
                if nx >= l or nx < 0 or ny >= l or ny < 0:
                    continue
        
                if maps[nx][ny] == -1:
                    maps[nx][ny] = maps[x][y] + 1
                    stop = True
                    break
                
                if maps[nx][ny] == 0:
                    maps[nx][ny] = maps[x][y] + 1
                    q.append((nx,ny))
                    
            if stop == True:
                break

for _ in range(n):
    
    l = int(input())
    maps = [[0]* l for _ in range(l)]

    night_x, night_y = map(int, input().split())
    target_x, target_y = map(int, input().split())

    maps[night_x][night_y] = 1
    maps[target_x][target_y] = -1

    bfs(night_x, night_y)         
    answers.append(maps[target_x][target_y]-1)
    
for answer in answers:
    print(answer)