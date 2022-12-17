n, k = map(int, input().split())

dp = [[0]*(n+1) for _ in range(k+1)]


for i in range(0, n+1):
    dp[1][i] = 1
    
for i in range(2, k+1):
    for j in range(0, n+1):
    
        temp = 0
        for p in range(j+1):
            temp += dp[i-1][p]
                
            dp[i][j] = temp
            
print(dp[-1][-1]% 1000000000)