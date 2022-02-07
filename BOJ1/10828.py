import sys

N = int(sys.stdin.readline());

arr = [];

def command(cmd):
    if(cmd[1] == "u"):
        cmd = cmd.split()
        arr.append(int(cmd[-1]))
    elif(cmd == "pop"):
        if(len(arr) == 0):
            print(-1)
        else:
            print(arr[-1])
            arr.pop(-1)
    elif(cmd == "size"):
        print(len(arr))
    elif(cmd == "empty"):
        if(len(arr) ==0):
            print(1)
        else:
            print(0)
    elif(cmd == "top"):
        if(len(arr) == 0):
            print(-1)
        else:
            print(arr[-1])
    else:
        return
        
for n in range(N):
    cmd = sys.stdin.readline().rstrip()
    command(cmd)

