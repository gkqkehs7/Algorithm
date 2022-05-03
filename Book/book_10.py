def open(key_size, lock_size, container):
    for i in range(lock_size):
        for j in range(lock_size):
            if(container[i+key_size-1][j+key_size-1] != 1):
                return False;
            
    return True

def rotated(a):
    n = len(a)
    m = len(a[0])
    result = [[0]* n for _ in range(m)]

    for i in range(n):
        for j in range(m):
            result[j][n-i-1] = a[i][j]
    return result;

def solution(key, lock):
    
    key_size = len(key)
    lock_size = len(lock)
    container_size = 2*key_size+lock_size-2
    
    container = [[0]*container_size for _ in range(container_size)]
    
    for i in range(lock_size):
        for j in range(lock_size):
            container[i+key_size-1][j+key_size-1] = lock[i][j]
            
    rotate_size = key_size + lock_size -1;
    
    for i in range(4):
        key = rotated(key)
        for x in range(rotate_size):
            for y in range(rotate_size):
                
                for i in range(key_size):
                    for j in range(key_size):
                        
                        container[i+x][j+y] += key[i][j]
                        if open(key_size, lock_size, container) == True:
                            return True;
                        
                for i in range(key_size):
                    for j in range(key_size):       
                        container[i+x][j+y] -= key[i][j]
                            
    return False
        
