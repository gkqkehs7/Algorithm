function solution(dirs) {

    let x = 0;
    let y = 0;

    let visited = Array(11).fill().map(() => 
        Array(11).fill().map(() => Array(11).fill().map(() => Array(11).fill(0)))
    )

    let ans = 0;
    for(let i=0; i<dirs.length; i++) {
        let command = dirs[i];

        let nx = x;
        let ny = y;
        if(command === "U") {
            ny = y + 1;
        } else if(command === "D") {
            ny = y - 1;
        } else if(command === "R") {
            nx = x + 1;
        } else if(command === "L") {
            nx = x - 1;
        }

        if(Math.abs(nx) > 5 || Math.abs(ny) > 5) {
            continue;
        }

        console.log(nx, ny)

        if(visited[x + 5][y + 5][nx + 5][ny + 5] === 0 && visited[nx + 5][ny + 5][x + 5][y + 5] === 0) {
            ans++;
            visited[x + 5][y + 5][nx + 5][ny + 5] = 1;
        }

        x = nx;
        y = ny;
    }


    console.log(ans)
    return ans;
}

solution("RRRRRLLLLL")