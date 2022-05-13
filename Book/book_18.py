def balanced_str(string):
    count = 0;
    result = 0;
    for str in string:
        if str == ")":
            count += 1;
        else:
            count -=1;
            
        result += 1;
        if(count == 0):
            return result;
        
def collect_str(string):
    count = 0;
    #음수가 되는 순간 왼쪽보다 오른쪽의 개수가 많아졌다는 소리이니 False
    for str in string:
        if str == "(":   
            count += 1;
        else:
            count -= 1;
        
        if count < 0:
            return False;
        
    return True;

def solution(p):
    
    if len(p) == 0:
        return ""
    
    u = p[:balanced_str(p)]
    v = p[balanced_str(p):]
    
    if collect_str(u) == True:
        return u + solution(v)
    
    else:
        u = u[1:-1]
        
        flop = ""
        for i in range(len(u)):
            if u[i] == "(":
                flop += ")"
            else:
                flop += "("

        new = "(" + solution(v) + ")" + flop
        return new;
