import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

dp = [0]*(n+1)
dp[0] = 1
dp[1] = 1
dp[2] = 2
for i in range(3,n+1):
    dp[i] = dp[i-1] + dp[i-2]
    
counts = []
fixs = []
for _ in range(m):
    fixs.append(int(input()))

if len(fixs) != 0:
    fixs.insert(0,0)
    fixs.append(n+1)

    for i in range(len(fixs)-1):
        temp = fixs[i+1] - fixs[i] - 1
        if temp != 0:
            counts.append(temp)


    answer = 1
    for i in range(len(counts)):
        answer = answer * dp[counts[i]]

    print(answer)
else:
    print(dp[n])
