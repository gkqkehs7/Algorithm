function cal_score(lion, apeach) {

    let lion_score = 0;    
    let apeach_score = 0;    

    for(let i=0; i<11; i++) {
        if(lion[i] > apeach[i]) {
            lion_score = lion_score + (10 - i);
        } else {
            if(apeach[i] > 0) {
                apeach_score = apeach_score + (10 - i);
            }
        }
    }

    if(lion_score > apeach_score) {
        return lion_score - apeach_score
    } else {
        return -1;
    }
}

function solution(n, info) {

    let max = 0;
    let min_str = "99999999999";

    let origin = [];

    for(let i=0; i<11; i++) {
        origin.push(info[i])
    }

    for(let i=0; i<11; i++) {
        info[i] = info[i] + 1;
    }


    function dfs(idx, rest, result) {

        // 화살 안남았다면 끝
        if(rest === 0) { 
        
            const score = cal_score(result, origin);

            if(score === max) {
                if(result.join("") < min_str) {
                    min_str = result.join("")
                }
            }

            if(score > max) {
                max = score;
                min_str = result.join("");
            }

            return;
        }
        
        // 마지막이라면 나머지 다 쏘고 끝
        if(idx === 10) {
            result[idx] = rest;
           
            const score = cal_score(result, origin);

            if(score === max) {
                if(result.join("") < min_str) {
                    min_str = result.join("")
                }
            }

            if(score > max) {
                max = score;
                min_str = result.join("");
            }
    
            return;
        }

        if(rest >= info[idx]) {
            rest = rest - info[idx]
            result[idx] = info[idx]
        } else {
            result[idx] = 0;
        }
     
        for(let i = idx + 1; i<11; i++) {
            dfs(i, rest, [...result])
        }
    }  

    for(let i=0; i<11; i++) {
        let result = Array(11).fill(0);
        dfs(i, n, result);
    }
    
    if(min_str === "99999999999") {
        return [-1]
    }

    let answer = [];

    for(let i=0; i<min_str.length; i++) {
        answer.push(parseInt(min_str[i]))
    }


    return answer;
}

solution(9, [9,0,0,0,0,0,0,0,0,0,0])