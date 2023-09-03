


function solution(maps) {

    let maps_hei = maps.length;
    let maps_wid = maps[0].length;

    let new_map = new Array(maps_hei).fill(0).map(() => {
        return new Array(maps_wid).fill(0)
    })

    let visited = new Array(maps_hei).fill(false).map(() => {
        return new Array(maps_wid).fill(false)
    })   

    for(let i=0; i<maps_hei; i++) {
        for(let j=0; j<maps_wid; j++) {
            if(maps[i][j] === "X") {
                new_map[i][j] = -1;
            } else {
                new_map[i][j] = parseInt(maps[i][j])
            }
        }
    }


    let dx = [-1, 0, 1, 0];
    let dy = [0, -1, 0, 1];


    function dfs(x, y) {

        let cost = new_map[x][y];

        for(let i=0; i<4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];

            if(nx >= 0 && nx < maps_hei && ny >= 0 && ny < maps_wid && new_map[nx][ny] !== -1) {
                if(visited[nx][ny] === false) {
                    visited[nx][ny] = true;
                    cost += dfs(nx, ny);
                }
            } 
        }
        
        return cost;
    }

    let answer = []
    for(let i=0; i<maps_hei; i++) {
        for(let j=0; j<maps_wid; j++) {
            if(new_map[i][j] !== -1 && visited[i][j] === false)  {
                visited[i][j] = true;
                answer.push(dfs(i, j))
            }
        }
    }

    // 콜백함수가 제공되지 않으면 요소를 문자열로 변환하고 유니 코드 코드 포인트 순서로 문자열을 비교하여 정렬됩니다-
    answer.sort(((a,b) => a-b))

    console.log(answer)

    if(answer.length === 0) {
        return [-1];
    }

    return answer;
}

solution(["X591X","X1X5X","X231X", "1XXX1"])