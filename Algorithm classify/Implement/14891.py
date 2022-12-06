import sys
input = sys.stdin.readline

tires= []
for _ in range(4):
    tire = input()
    temp = []
    for i in range(len(tire)):
        temp.append(tire[i])
    tires.append(temp[:-1])
    
rotation_num = int(input())
rotations = []
for _ in range(rotation_num):
    rotations.append(list(map(int, input().split())))
    
def turn_unclock(arr):
    arr.append(arr.pop(0))

def turn_clock(arr):
    arr.insert(0, arr.pop(7))


for rotation in rotations:
    to_rotate = [(rotation[0], rotation[1])]
    if rotation[0] == 1:
        if tires[0][2] != tires[1][6]:
            to_rotate.append([2, -rotation[1]])
            if tires[1][2] != tires[2][6]:
                to_rotate.append([3, rotation[1]])
                if tires[2][2] != tires[3][6]:
                    to_rotate.append([4, -rotation[1]])
                    
    elif rotation[0] == 2:
        if tires[0][2] != tires[1][6]:
            to_rotate.append([1, -rotation[1]])
            
        if tires[1][2] != tires[2][6]:
            to_rotate.append([3, -rotation[1]])
            if tires[2][2] != tires[3][6]:
                to_rotate.append([4, rotation[1]])
    
    elif rotation[0] == 3:
        if tires[2][2] != tires[3][6]:
            to_rotate.append([4, -rotation[1]])
        
        if tires[1][2] != tires[2][6]:
            to_rotate.append([2, -rotation[1]])
            if tires[0][2] != tires[1][6]:
                to_rotate.append([1, rotation[1]])
    
    elif rotation[0] == 4:
        if tires[2][2] != tires[3][6]:
            to_rotate.append([3, -rotation[1]])
            if tires[1][2] != tires[2][6]:
                to_rotate.append([2, rotation[1]])
                if tires[0][2] != tires[1][6]:
                    to_rotate.append([1, -rotation[1]])
                    
    for to_rotat in to_rotate:
        if to_rotat[1] == 1:
            turn_clock(tires[to_rotat[0]-1])
        else:
            turn_unclock(tires[to_rotat[0]-1])
        
    
answer = 0;
if tires[0][0] == '1':
    answer += 1
if tires[1][0] == '1':
    answer += 2
if tires[2][0] == '1':
    answer += 4
if tires[3][0] == '1':
    answer += 8
    
print(answer)
        