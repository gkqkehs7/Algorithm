a = input()
b = input()

a_len = len(a)
b_len = len(b)

dp = [[0]*b_len for _ in range(a_len)]
for i in range(a_len):
    dp[i][0] = 1;
dp[0] = [1]*b_len

for i in range(1,a_len)