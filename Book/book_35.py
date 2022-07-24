n = int(input())

d = [0] * 10001;
d[1] = 1;

dp = [0] * 10001;
dp[1] = 1;
count = 1

for i in range(2,1000):
    if count == n:
        print(dp[n])
        break;
    if i % 2 == 0:
        if d[i//2] == 1:
            d[i] = 1
            count += 1;
            dp[count] = i;
    elif i % 3 == 0:
        if d[i//3] == 1:
            d[i] = 1
            count += 1;
            dp[count] = i;
    elif i % 5 == 0:
        if d[i//5] == 1:
            d[i] = 1
            count += 1;
            dp[count] = i;
    else: continue;

