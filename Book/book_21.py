from collections import deque
from re import M, T
N, L ,R = map(int, input().split())

worlds = []
for i in range(N):
    worlds.append(list(map(int, input().split())))

def can_merge(prev, next):
    if abs(prev-next) <=R and abs(prev-next) >=L:
        return True;
    else: return False;
    
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


count = 0;
while True:
    terminate = False;
    complete = [[0]*N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            
            if complete[i][j] == 1:
                continue;
            
            to_merge=[[i,j]]       
            q = deque()
            q.append((i,j))
                    
            sum = 0;
            
            while q:
                x, y= q.popleft()
                prev_peoples = worlds[x][y]
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
    
                    # 범위초과
                    if nx < 0 or ny < 0 or nx >= N or ny >= N or complete[nx][ny] == 1:
                        continue;
            
                    #이미 오늘 병합한 나라일시
                    # if complete[nx][ny] == 1:
                    #     continue;
                    
                    if can_merge(prev_peoples, worlds[nx][ny]) == True:
                        terminate = True;
                        complete[x][y] = 1;
                        complete[nx][ny] = 1;
                        to_merge.append([nx,ny])
                        q.append((nx,ny))
                    
            
            for merge in to_merge:
                sum += worlds[merge[0]][merge[1]]
            avg = int(sum / len(to_merge))
            
            
            for merge in to_merge:
                worlds[merge[0]][merge[1]] = avg; #평균값으로 바꾸어 주고
    
            
            
    if terminate == False: #하나라도 병합을 하지 않은경우
        print(count)
        break;
    
    count += 1;

            
            
            
        
        
        
        
        