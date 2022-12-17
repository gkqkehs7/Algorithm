a = input()
b = input()

alen = len(a)
blen = len(b)

dp = [[0] * (blen + 1) for _ in range(alen + 1)]
for i in range(1, alen+1):
    for j in range(1, blen+1):
        if a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[-1][-1])