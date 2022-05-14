from itertools import combinations
from collections import deque
import copy

n = int(input())

school = []
for i in range(n):
    school.append(list(input().split()))

teachers = []
students = []
zeros = []
for i in range(n):
    for j in range(n):
        if school[i][j] == 'X':
            school[i][j] = 0;
            zeros.append((i,j))
        elif school[i][j] == 'S':
            school[i][j] = 1;
            students.append((i,j))
        else:
            school[i][j] = 2;
            teachers.append((i,j))
origin_school = copy.deepcopy(school)

walls = list(combinations(zeros, 3))

def success():
    global school
    for wall in walls:
        fail = False
        #장애물 세우기
        for wal in wall:
            school[wal[0]][wal[1]] = 3;

        # 선생마다 좌우 상하로 뻗어나가며 검사
        for teacher in teachers:
            if fail == True:
                break;
            
            dx = [-1 , 0 , 1, 0]
            dy = [0, 1, 0 , -1]
            
            for i in range(4):
                if fail == True:
                    break;
                x = teacher[0]
                y = teacher[1]
                while True:             
                    x = x + dx[i]
                    y = y + dy[i]
                    if x < 0 or y < 0 or x >= n or y >= n: 
                        break;
                    if school[x][y] == 3:
                        break;
                    if school[x][y] == 1:
                        fail = True;
                        break;
        if fail == True:
            school = copy.deepcopy(origin_school)
            fail = False;
        else: 
            return 'YES';
    return 'NO'
                    
print(success())