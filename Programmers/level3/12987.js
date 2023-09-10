function solution(A, B) {

    // 내림차순
    A.sort((prev, next) => {
        return next - prev;
    })

    // 오름차순
    B.sort((prev, next) => {
        return prev - next;
    })

    let answer = 0;
    
    for(const a of A) {
        const max = B[B.length - 1];

        if(a < max) {
            answer++;
            B.pop();
        }
    }

    // 1 3 5 9 
    // 2 2 6 8

    return answer;
}

solution([1,3,5,9], [2, 2, 6, 8])