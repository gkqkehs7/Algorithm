import sys
input = sys.stdin.readline

d, k = map(int, input().split())

dp=[0]*(d+1)

dp[1] = (1,0)
dp[2] = (0,1)
dp[3] = (1,1)

for i in range(4, d+1):
    dp[i] = (dp[i-1][0]+dp[i-2][0], dp[i-1][1]+dp[i-2][1])
    

a = dp[d][0]
b = dp[d][1]

temp = k // b + 1

for i in range(1,temp+1):
    if (k - (a * i)) % b == 0:
        print(i)
        print(( (k - (a * i)) // b ))
        break
        