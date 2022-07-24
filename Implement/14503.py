import sys

input = sys.stdin.readline

n,m = input().split()

x,y,direction = input().split()

room = []
for _ in range(n):
    room.append(list(map(int, input().split())))
    
visited = [[0] * m for _ in range(n)]

dx = [-1,0,1,0]
dy = [0,1,0,-1]

def turn_left():
    global direction
    direction -= 1
    
    if direction == -1:
        direction = 3
   
clear = 0
while True:     
    flag = False
    visited[x][y] = 1
    turn_left()

    nx = x + dx[direction]
    ny = y + dy[direction]

    if(0 <= nx <n and 0 <= ny <m and room[nx][ny] != 1):
        x = nx
        y = ny
        visited[x][y] = 1
        clear += 1
        
    if flag == False:
        x = x - dx[direction]
        y = y - dy[direction]
        
        if(nx >= n or nx < 0 or ny >=m or ny <0 or room[nx][ny] == 1):
            print(clear)
            break;