from collections import deque

n, k = map(int,input().split())

container = []
viruses = []

for i in range(n):
    container.append(list(map(int, input().split())))
    for j in range(n):
        # 해당 위치에 바이러스가 존재하는 경우
        if container[i][j] != 0:
            # (바이러스 종류, 시간, 위치 X, 위치 Y) 삽입
            viruses.append((container[i][j], 0, i, j))

#번호가 낮은 바이러스가 앞에 올 수 있게 sort
viruses.sort()
q = deque(viruses)


target_s, target_x, target_y = map(int,input().split())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0 , -1]

while q:
    virus, s, x, y = q.popleft()
    
    if s == target_s:
        break;
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if(nx <0 or ny <0 or nx>= n or ny>=n):
            continue;
        
        if(container[nx][ny] == 0):
            container[nx][ny] = virus;
            q.append((virus, s+1, nx, ny))
            

print(container[target_x - 1][target_y - 1])

   
