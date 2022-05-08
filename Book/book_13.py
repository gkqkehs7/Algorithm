from itertools import combinations

first = list(map(int, input().split()))
size = first[0]
left_store = first[1]

houses = [] #집위치
chickens = [] #치킨집위치
country = [] #마을
 
for i in range(size):
    country.append(list(map(int, input().split())))
    
#집과 치킨집의 위치 저장
for i in range(size):
    for j in range(size):
        if(country[i][j] == 1):
            houses.append([i,j])
        elif(country[i][j] == 2):
            chickens.append([i,j])

#폐업시키지 않은 치킨집들 조합
chicken_picks = list(combinations(chickens, left_store))

result = 99999
for chicken_pick in chicken_picks:
    chicken_distances = [] #다 합하면 도시의 치킨거리
    # n개 고른 치킨 집중 가장 치킨 거리가 짧은 수 선정 
    for house in houses: #집마다 치킨집까지의 거리 선정
        chicken_distance = 99999
        for chicken in chicken_pick:
            distance = abs(house[0]-chicken[0])+abs(house[1]-chicken[1]) 
            chicken_distance = min(distance, chicken_distance)
    
        chicken_distances.append(chicken_distance)
        
    result = min(result,sum(chicken_distances))

print(result)
