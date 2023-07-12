function solution(storey) {

    storey = storey.toString().split("").reverse().map(Number)

    let answer = 0;
    let up = false;

    for(let i=0; i<storey.length; i++) {
        let now = storey[i];

        if(up) {
            now += 1;
            up = false;
        }
    
        if(now === 10) {
            if(i === storey.length - 1) {
                answer += 1;
                break;
            } 

            up = true;
            continue;
        }

        if(now < 5) {
            answer += now;
        } else if(now === 5) {
            if(i === storey.length - 1) {
                answer += now;

            } else {
                let next = storey[i+1];

                if(next >= 5) {
                    up = true;
                    answer += (10 - now);
                } else {
                    answer += now;
                }
            }

        } else if(now > 5) {
            up = true;
            answer += (10 - now);
        }
    }

    if(up) answer += 1;
 
    return answer;
}

solution(678)