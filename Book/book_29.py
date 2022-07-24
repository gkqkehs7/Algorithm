pin = list(map(int, input().split()))
house_num = pin[0]
share_num = pin[1]

houses = []
for i in range(house_num):
    houses.append(int(input()))
    
houses.sort()

start = 1
end = houses[-1] - houses[0]
result = 0;
while True:
    if start > end: break;
    gap = ( end + start ) // 2;
    
    count = 1
    standard = houses[0]
    #설치할 수 있는지 검사
    for i in range(1, len(houses)):
        distance = houses[i] - standard
        
        if distance >= gap:
            standard = houses[i]
            count += 1
    
    if count >= share_num:
        start = gap + 1
        result = gap
    else: 
        end = gap - 1;
        
print(result)