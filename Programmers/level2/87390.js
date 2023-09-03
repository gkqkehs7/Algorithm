function solution(n, left, right) {

    if (n === 1) {
        if (left >= 1) {
            return []
        } else {
            return [1]
        }
    }

    const answer = [];
    let rowCount = Math.floor(left / n) + 1;

    for (let i = left; i < right + 1; i++) {
        if ((i + 1) % n === 0) {
            answer.push(n);
            rowCount += 1;
            continue;
        }
        if (i % n < rowCount){
            answer.push(rowCount);
        } else {
            answer.push((i + 1) % n);
        }
    }
    return answer;
}

solution(4, 7, 14);