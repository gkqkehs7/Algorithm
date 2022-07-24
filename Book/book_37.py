import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
INF = 1e9
graph = [[INF]*(n+1) for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1, n+1):
        if i == j:
            graph[i][j] = 0
            
for i in range(m):
    a,b,c = map(int, input().split())
    
    if c < graph[a][b]:
        graph[a][b] = c

for i in range(1,n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][i]+ graph[i][b])
            
for a in range(1,n+1):
    for b in range(1,n+1):
        if graph[a][b] == INF:
            print(0, end=" ")
        else:
            print(graph[a][b], end=" ")
    print()