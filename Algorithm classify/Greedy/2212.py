import sys

input = sys.stdin.readline
n = int(input())
k = int(input())

road = list(map(int, input().split()))
road.sort()
road_distance = []
prev = road[0]
for i in range(1, len(road)):
    road_distance.append(road[i]-prev)
    prev = road[i]

if (k == 1):
    print(sum(road_distance))
else: 
    road_distance.sort()
    road_distance = road_distance[:-(k-1)]

    print(sum(road_distance))
