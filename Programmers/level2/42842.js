function solution(brown, yellow) {

    let result = [];
    for(let i=1; i<= yellow; i++) {
        if(yellow % i === 0) {
            result.push([i, yellow / i]);
        }
    }

    let answer = [];

    for(let i=0; i<result.length; i++) {
        let [a, b] = result[i];


        if((a + 2) * (b + 2) - yellow === brown) {

            if(a > b) {
                answer = [a + 2, b + 2];
            } else {
                answer = [b + 2, a + 2];
            }
            
            break;
        }
    }


    return answer;
}

solution(8, 1);