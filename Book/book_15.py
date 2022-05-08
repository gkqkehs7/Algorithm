from collections import deque

pin = list(map(int, input().split()))

city = pin[0]
road = pin[1]
distance = pin[2]
start_city = pin[3]

graph = [[] for _ in range(city+1)]

for i in range(road):
    start, end = int(input().split())
    graph[start] = end

container = [-1] * (city+1)
q = deque([start_city])

while q:
    now = q.popleft()
    
    for next_node in graph[now]:
        
        if(container[next_node] == -1):
            container[next_node] = container[now] + 1;
            q.append(next_node)