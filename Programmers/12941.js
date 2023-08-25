function solution(A,B){


    A.sort((prev, next) => {
        return prev - next;
    })

    B.sort((prev, next) => {
        return next - prev;
    })

    let answer = 0;
    for(let i=0; i<A.length; i++) {
        answer += A[i] * B[i];
    }

    return answer;
}