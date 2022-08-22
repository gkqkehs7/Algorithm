# dp가 dfs/bfs와 다른점은? 탐색곳은 또 탐색하지 않는다 
 
import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
maps = []
dp = [[0]*n for _ in range(n)]
dp[0][0] = 1
for _ in range(n):
    maps.append(list(map(int, input().split())))

for i in range(n):
    for j in range(n):
        
        if i == n - 1 and j == n-1:
            print(dp[i][j])
            break        
        if i + maps[i][j] < n:
            dp[i+maps[i][j]][j] += dp[i][j]
        
        if j + maps[i][j] < n:
            dp[i][j+maps[i][j]] += dp[i][j]

