function solution(n) {
    var answer = 1;
    for (let k = 1; k <= n / 2; k++) {
        let sum = 0;
        let i = k;
        while (sum < n) sum += i++;
        if (sum == n) answer++;
    }
    return answer;
}