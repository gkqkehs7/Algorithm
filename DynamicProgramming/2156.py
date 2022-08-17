from pickle import DUP
import sys
input = sys.stdin.readline

n = int(input())

drinks = []
dp = [0] * 10001

for _ in range(n):
    drinks.append(int(input()))
    
dp[0] = drinks[0]
dp[1] = drinks[1]
dp[2] = drinks[2]

for i in range(3, n):
    dp[i] = max(dp[i-2] + dp[i-2], dp[i-3]+dp[i-1], )