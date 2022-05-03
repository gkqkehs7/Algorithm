place = input()

col = 0
if(place[0] == 'a'):
    col = 1
elif(place[0] == 'b'):
    col = 2;  
elif(place[0] == 'c'):
    col = 3;  
elif(place[0] == 'd'):
    col = 4; 
elif(place[0] == 'e'):
    col = 5;  
elif(place[0] == 'f'):
    col = 6;  
elif(place[0] == 'g'):
    col = 7;  
elif(place[0] == 'h'):
    col = 8;  
        
row = int(place[1])

moves = [(-2,-1),(-2,1),(2,-1),(2,1),(-1,-2),(1,-2),(-1,2),(1,2)]

count = 0;
for move in moves:
    hor = move[0];
    ver = move[1];
    
    if((hor + col > 0) & (row + ver > 0)):
        count += 1;

print(count)