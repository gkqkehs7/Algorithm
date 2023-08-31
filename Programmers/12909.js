function solution(s){

    let stack_count = 0;

    for(let i=0; i<s.length; i++) {
        let str = s[i];

        if(str === "(") {
            stack_count++;
        } else {
    
            stack_count--;
               
            if(stack_count < 0) {
                return false;
            }
        }
    }

    if(stack_count === 0) {
        return true;
    } else {
        return false;
    }
}