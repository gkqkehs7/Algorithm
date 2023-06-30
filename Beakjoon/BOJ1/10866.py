from collections import deque
import sys

N = int(sys.stdin.readline());

arr = deque([])


def command(cmd):
    if(cmd[1] == "u"):    
        if(cmd[5] == "f"):
            cmd = cmd.split()
            arr.appendleft(int(cmd[-1]))
        elif(cmd[5] == "b"):
            cmd = cmd.split()
            arr.append(int(cmd[-1]))
    elif(cmd == "pop_front"):
        if(len(arr) == 0):
            print(-1)
        else:
            print(arr[0])
            arr.popleft()
    elif(cmd == "pop_back"):
        if(len(arr) == 0):
            print(-1)
        else:
            print(arr[-1])
            arr.pop()
    elif(cmd == "size"):
        print(len(arr))
    elif(cmd == "empty"):
        if(len(arr) ==0):
            print(1)
        else:
            print(0)
    elif(cmd == "front"):
        if(len(arr) == 0):
            print(-1)
        else:
            print(arr[0])
    elif(cmd == "back"):
        if(len(arr) == 0):
            print(-1)
        else:
            print(arr[-1])
    else:
        return
        
for n in range(N):
    cmd = sys.stdin.readline().rstrip()
    command(cmd)

