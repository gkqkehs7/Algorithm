function solution(n, edge) {

    let map = Array(n + 1).fill().map(() => {
        return [];
    })

    for(let i=0; i<edge.length; i++) {
        const [start, end] = edge[i];
        map[start].push(end);
        map[end].push(start);
    }

    let dp = Array(n+1).fill(999999999);
    dp[1] = 0;

    let queue = [1];

    let max = 0;

    while(queue.length) {
        let now = queue.shift();

        for(let i=0; i<map[now].length; i++) {
            let next = map[now][i];

            if(dp[next] > dp[now] + 1) {
                max = Math.max(max, dp[now] + 1)
                dp[next] = dp[now] + 1;
                queue.push(next);
            }
        }
    }

    let answer = 0;

    for(let i=0; i<dp.length; i++) {
        if(dp[i] === max) {
            answer++;
        }
    }
    return answer;
}

// solution(7, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2], [6, 7]])