import sys
input = sys.stdin.readline

n, d = map(int, input().split())

roads = []
for _ in range(n):
    a,b,c = map(int, input().split())
    roads.append((a,b,c))
roads = sorted(roads, key = lambda x: x[1])    

dp = [i for i in range(10001)]

for road in roads:
    if road[1] <= d:
        if dp[road[1]] - dp[road[0]] > road[2]:
            dp[road[1]] = dp[road[0]] + road[2]
            for i in range(road[1] + 1, d+1):
                dp[i] = dp[road[1]] + i - road[1]
print(dp[d])