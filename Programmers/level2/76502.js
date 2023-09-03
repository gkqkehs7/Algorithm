function solution(s) {
    
    let slen = s.length;

    if(slen%2 !== 0) {
        return 0;
    } 

    s = s + s;

    let start = 0;
    let end = slen;
    let answer = 0;

    for(let j=0; j<slen; j++) {
        let right_str = true;
        let stack = [];

        for(let i=start; i<end; i++) {
            let str = s[i];
            
            if(str === "[") {
                stack.push(str)
            } else if(str === "(") {
                stack.push(str)
            } else if(str === "{") {
                stack.push(str)
            } else {
                if(stack.length > 0) {
                    let compare = stack.pop();
             
                    if(compare === "(") {
                        if(str !== ")") {
                            right_str = false;
                            break;
                        }
                    } else if(compare === "{") {
                        if(str !== "}") {
                            right_str = false;
                            break;
                        }
                    } else if(compare === "[") {
                        if(str !== "]") {
                            right_str = false;
                            break;
                        }
                    }
                    
                } else {
                    right_str = false;
                    break;
                }

            }           
        }

            
        if(right_str) {
            answer++;
        }

        start++;
        end++;
    }

    
    console.log(answer);

    return answer;
}

console.log(solution("("))
