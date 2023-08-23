function solution(s){
    
    let stack = [];
    for(var i=0; i<s.length; i++){
        if(stack[stack.length-1] != s[i]){
            stack.push(s[i]);
        }else{
            stack.pop();
        }
    }

    if(stack.length === 0) {
        return 1;
    } else {
        return 0;
    }

}