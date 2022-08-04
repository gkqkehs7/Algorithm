import sys
input = sys.stdin.readline

t = int(input())

answers = []
for _ in range(t):
    n = int(input())
    
    trees = list(map(int, input().split()))
    trees.sort(reverse=True)
    
    temp = []
    for i in range(len(trees)):
        if i % 2 == 0:
            temp.append(trees[i])
        else:
            temp.insert(0, trees[i])
        
    max = 0
    for i in range(len(temp)-1):
        if max < abs(temp[i]-temp[i+1]):
            max = temp[i]-temp[i+1]

    if max < abs(temp[-1] - temp[0]):   
        max = abs(temp[-1] - temp[0])
        
    answers.append(max)

    
for answer in answers:
    print(answer)