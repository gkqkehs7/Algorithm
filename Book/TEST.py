from collections import deque
from itertools import combinations
import copy

n,m = map(int,input().split())

container = [[0]*m for _ in range(n)]

for i in range(n):
    container[i] = list(map(int, input().split()))
    
origin_contaier = copy.deepcopy(container);
    
zero_index = []
virus = []
#연구실과, 바이러스 위치 기록
for i in range(n):
    for j in range(m):
        if container[i][j] == 0:
            zero_index.append([i,j])
        elif container[i][j] == 2:
            virus.append([i,j])

#벽을세울 3곳위치 선정            
wall_places = list(combinations(zero_index, 3))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

safe_areas = []
#벽의 후보들을 for문으로 돌아서 안전영역 크기 구하기
for wall_place in wall_places:
        
    #벽 세우기
    for item in wall_place:
        container[item[0]][item[1]] = 1;
    
    for viru in virus:
        q = deque([])
        q.append(viru)
   
        while q:
            now = q.popleft()        
            x = now[0]
            y = now[1]
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                
                # 범위 밖인 경우
                if nx<0 or ny <0 or nx >= n or ny >= m:
                    continue;
                
                # 바이러스인 경우
                if container[nx][ny] == 2: 
                    continue;
                
                # 벽인경우
                if container[nx][ny] == 1:
                    continue;
                
                # 감염시킬 수 있는 경우
                if container[nx][ny] == 0:
                    container[nx][ny] = 2;
                    q.appendleft([nx,ny])
    
    safe_area = 0
    for i in range(n):
        for j in range(m):
            if(container[i][j] == 0):
                safe_area += 1;
    
    safe_areas.append(safe_area)
    

    container = origin_contaier
    
    
    
print(max(safe_areas))

