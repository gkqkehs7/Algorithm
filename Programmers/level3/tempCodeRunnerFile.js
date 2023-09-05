function solution(n, s) {

    if(s < n) {
        return [-1];
    }

    let temp = parseInt(s/n);
    let rest = s % n;

    console.log(temp, rest)

    let answer = Array(n).fill(temp);

    for(let i=0; i<rest; i++) {
        answer[i] = answer[i] + 1;
    }

    answer.sort((prev, next) => {
        return prev - next;
    })
    
    console.log(answer)

    // let temp2 = parseInt(n / rest); // 몇개씩 나누어 더 줄거냐
    // let rest2 = n % rest;

    // answer = answer.map((item) => item + temp2);

    // console.log(answer)

    // console.log(temp2, rest2);

    return answer;
}

solution(7, 103)