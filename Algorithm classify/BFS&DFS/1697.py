# 이걸 생각한건 당연한것인가..?
# bfs는 몇번쨰 깊이인지를 아는게 가장 중요하나?
# 좌표에서는 몇일째인지 쎌수없엇는데 (벽에 막히면 2번탐색한 3번탐색한 경우도 있으니)
# 여기는 항상 3의 제곱순으로 늘어나니까 확인을 할 수있다

# dfs /bfs 에서 가장 중요한것은 내가 갔으니 가지말라는것이다

# bfs에서 범위 제약
import sys
from collections import deque
input = sys.stdin.readline
MAX = 100001
x, target = map(int, input().split())
visited = [0] * MAX

def bfs(subin):
    q = deque()
    q.append(subin)
    
    while q:
        temp = q.popleft()
        
        if temp == target:
            break
        
        if temp == 0:
            if visited[temp+1] == 0:
                visited[temp+1] = visited[temp] + 1
                q.append(temp+1)
        else:
            if temp + 1 < MAX:
                if visited[temp+1] == 0:
                    visited[temp+1] = visited[temp] + 1
                    q.append(temp+1)
                
            if visited[temp-1] == 0:
                visited[temp-1] = visited[temp] + 1
                q.append(temp-1)
                            
            if temp * 2 < MAX:
                if visited[temp*2] == 0:
                    visited[temp*2] = visited[temp] + 1
                    q.append(temp*2)
        
if x == target:
    print(0)
else: 
    bfs(x)
    print(visited[target])
  
    
# 아 queue에 들어간 값이 같을수가 있껫구나 / 1000000번쨰에는 엄청난 값들이 queue에추가되엇겟구나