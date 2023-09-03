function solution(n)
{
    let answer = 0;
    while(n !== 1) {
        if(n % 2 === 0) {
            n = n / 2;
        } else {
            n = n - 1;
            answer++;
        }
    }

    return answer + 1;
}

console.log(solution(1))