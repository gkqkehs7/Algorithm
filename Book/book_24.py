n = int(input())

houses = list(map(int, input().split()))

houses.sort()

result = 0;
answer = houses[0];

for i in range(houses[0], houses[-1]+1):
    
    distances = list(map(lambda x : abs(x-i), houses))
    
    if i == houses[0]: result = sum(distances)
    if result > sum(distances): 
        result = sum(distances)
        answer = i;

print(answer)