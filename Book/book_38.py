import sys
input = sys.stdin.readline

n,m = map(int, input().split())
graph = [[0]*(n+1) for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1, n+1):
        if i == j:
            graph[i][j] = 0
            
for i in range(m):
    a,b = map(int, input().split())
    graph[a][b] = 1

for i in range(1,n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            if graph[a][i] == 1 and graph[i][b] == 1:
                graph[a][b] = 1
            
            

result = 0;
for a in range(1, n+1):
    count = 0;
    for b in range(1, n+1):
        if graph[a][b] == 1 or graph[b][a] == 1:
            count += 1;
            
    if count == n-1:
        result += 1;
        
print(result)
            