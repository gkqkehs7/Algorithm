# 각 칸마다 상하좌우 움직여서 최대합 갱신 
# 최대 크기는 4x500 각 칸마다 4x4x4x4=256번 최대움직임
# 4x500x256 < 10,000,000 이므로 제한시간 2초내에 가능

import sys
input = sys.stdin.readline
n,m = input().split();

n = int(n);
m = int(m);

tetromino = [];
for i in range(n):
    tetromino.append(list(map(int, input().split())));


dx = [0, 1, 0, -1]
dy = [-1, 0 ,1, 0]
max = 0;

def search(x, y, idx, sum):
    if idx == 4:
        if sum > max:
            max = sum
        return;
    for z in range(4):
        nx = x + dx[x]
        ny = y + dy[y]
        sum = sum + tetromino[nx,ny]
        if(nx >= n or nx < 0 or ny >= m or ny < 0):
            continue;
        
        search(nx, ny, idx+1, sum)
        
    
for i in range(n):
    for j in range(m):
        sum = 0
        search(i,j,0,sum)      
        

    
            
        