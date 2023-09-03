function solution(land) {
    
    let dp = Array(100001).fill().map(() => {
        return Array(4).fill(0);
    });

    function dfs(depth, now, idx) {

        if(depth === land.length - 1) {
            return;
        }

        for(let i=0; i<4; i++) {
            if(idx === i) continue;

            if(dp[depth + 1][i] < now + land[depth + 1][i]) {
                dp[depth + 1][i] = now + land[depth + 1][i]
                dfs(depth + 1, now + land[depth + 1][i], i)
            }
        }
    
    }

    for(let i=0; i<4; i++) {
        dfs(0, land[0][i], i)
    }

    return Math.max(...dp[land.length - 1])
}

function solution2(land) {
    for(let i=1;i<land.length;i++){
        land[i][0]+=Math.max(land[i-1][1],land[i-1][2],land[i-1][3])
        land[i][1]+=Math.max(land[i-1][0],land[i-1][2],land[i-1][3])
        land[i][2]+=Math.max(land[i-1][0],land[i-1][1],land[i-1][3])
        land[i][3]+=Math.max(land[i-1][0],land[i-1][1],land[i-1][2])
    }

    return Math.max(...land[land.length-1])
}
solution2([[1,2,3,5],[5,6,7,8],[4,3,2,1]])