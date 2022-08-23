# 제발 표를 그려서 규칙을 찾아내라
# 표를 그려서 푸는 문제
# 나머진 다 채워져있다ㅏ고 자정, 뒤에서 부터 빼는 문제
# https://huiyu.tistory.com/entry/DP-01-Knapsack%EB%B0%B0%EB%82%AD-%EB%AC%B8%EC%A0%9C
import sys
input = sys.stdin.readline

n, k = map(int, input().split())

bag = []
for _ in range(n):
    bag.append(list(map(int, input().split())))

dp = [0] * (k+1)

for item in bag:
    weight = item[0]
    value = item[1]
    if weight > k:
        continue
    
    dp[weight] 