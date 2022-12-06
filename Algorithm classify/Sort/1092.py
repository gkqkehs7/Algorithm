import sys
input = sys.stdin.readline

n = int(input())
cranes = list(map(int, input().split()))

m = int(input())
boxes = list(map(int, input().split()))

boxes.sort(reverse=True)
cranes.sort(reverse=True)

if boxes[0] > cranes[0]:
    print(-1)
else:
    time = 0
    
    while boxes:
        
        for crane in cranes:
            for box in boxes:
                if crane >= box:
                    boxes.remove(box)   
                    break
                
        time += 1
    print(time)


