import sys
input = sys.stdin.readline

n = int(input())

maps = []
dp = [[0]*n for _ in range(n)]
for _ in range(n):
    maps.append(list(map(int, input().split())))

