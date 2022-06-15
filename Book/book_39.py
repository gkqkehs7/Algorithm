import heapq as h
import sys
input = sys.stdin.readline
INF = int(1e9)

t = int(input())

for i in range(t):
    n = int(input())

    graph = []
    for i in range(n):
        graph.append(list(map(int, input().split())))
        
    distance = [[INF] * n for _ in range(n)]
    
    x,y =0, 0
    q = [(graph[x][y], x, y)]
    distance[x][y] = graph[x][y]
    
    while q:
        dist,x,