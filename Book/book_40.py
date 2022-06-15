import heapq as h
import sys
input = sys.stdin.readline
INF = int(1e9)

n,m = map(int, input().split())

start = 1
graph = [[] for i in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):
    a,b = map(int, input().split())
    graph[a].append((b,1))
    graph[b].append((a,1))
    
def dijkstra(start):
    q = []
    h.heappush(q, (0,start))
    distance[start] = 0
    
    while q:
        dist, now = h.heappop(q)
        
        if distance[now] < dist:
            continue
        
        for i in graph[now]:
            cost = dist + i[1]
            
            if cost< distance[i[0]]:
                distance[i[0]] = cost
                h.heappush(q, (cost, i[0]))
                
dijkstra(start)

for i in range(1, n+1):
    if distance[i] == INF:
        print('no')
    else:
        print(distance[i])