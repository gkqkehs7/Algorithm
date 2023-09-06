function solution(n, works) {

    works.sort((prev, next) => {
        return next - prev;
    })

    while (n > 0) {

        for (let idx = 0; idx < works.length; idx++) {
            works[idx]--;
            n--;
            if (works[idx] >= works[idx + 1] || n <= 0) break;
        }
    }

    var answer = works.reduce((acc, cur) => (cur > 0 ? acc + cur ** 2 : acc), 0);

    return answer;
}

solution(7, [5, 3, 2])