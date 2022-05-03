size = int(input())
apple_count = int(input())

apple_locations = []
for i in range(apple_count):
    apple_location = list(map(int, input().split()))
    apple_locations.append(apple_location) 

move_count = int(input())    
moves = []
for i in range(move_count):
    move = list(input().split())
    move[0] = int(move[0])
    moves.append(move)
    
container = [[0]*size for _ in range(size)]

for apple_location in apple_locations:
    container[apple_location[0]-1][apple_location[1]-1] = -1;



def turn(RL, direction):
    if(RL == 'D'):
        if(direction == 3):
            direction = 0;
        else:
            direction += 1;
    if(RL == 'L'):
        if(direction == 0):
            direction = 3;
        else:
            direction -=1;
    return direction;


#뱀위치 표시
x,y= 0,0
snake = []

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
  
direction = 0; #동쪽은 0
end = False;
time = 0;

left_time = moves[0][0];
rotate = 0;
while True:
    for i in range(left_time):
        
        x = x + dx[direction]
        y = y + dy[direction]
        #벽을 만난 경우
        if(x==size or y==size or x==-1 or y==-1):
            end = True;
            break; 
        #사과를 만난 경우
        elif(container[x][y] == -1):
            container[x][y] = 0;
            snake.append([x-dx[direction],y-dy[direction]])
            time += 1;
        #자기자신에 부딪힌 경우
        elif [x,y] in snake:
            end = True;
            break;  
        #정상적으로 나아간경우
        else:
            snake.append([x-dx[direction],y-dy[direction]])
            snake.pop(0)
            time += 1;
        
        
    if(end == True):
        print(time+1)
        break;
    else:
        direction = turn(moves[rotate][1], direction)
        rotate += 1;
        if(rotate == len(moves)):
            left_time = 10000;
        else:
            left_time = moves[rotate][0] - moves[rotate-1][0]
        
        
        
        
