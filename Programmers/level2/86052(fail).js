
function get_direct(now, next, now_x, now_y) {
    if(now === 0) {
        if(next === "S") {
            return [now_x - 1, now_y, 0];
        } else if(next === "R") {
            return [now_x, now_y + 1, 1];
        } else if(next === "L") {
            return [now_x, now_y - 1, 3];
        }
    } else if(now === 1) {
        if(next === "S") {
            return [now_x, now_y + 1, 1];
        } else if(next === "R") {
            return [now_x + 1, now_y, 2];
        } else if(next === "L") {
            return [now_x - 1, now_y, 0];
        }
    } else if(now === 2) {
        if(next === "S") {
            return [now_x + 1, now_y, 2];
        } else if(next === "R") {
            return [now_x, now_y - 1, 3];
        } else if(next === "L") {
            return [now_x, now_y + 1, 1];
        }
    } else if(now === 3) {
        if(next === "S") {
            return [now_x, now_y - 1, 3];
        } else if(next === "R") {
            return [now_x - 1, now_y, 0];
        } else if(next === "L") {
            return [now_x + 1, now_y, 2];
        }
    }
}

function solution(grid) {

    let queue = [];

    let wid = grid[0].length;
    let hei = grid.length;

    let start_x = 0;
    let start_y = 0;
    
    let visited = Array(grid.length).fill().map(() => {
        return Array(grid[0].length).fill(0);
    })

    queue.push([0, 0, 2]);
    visited[0][0] = 1;


    while(queue.length > 0) {
        let [x, y, now_direct] = queue.shift();

        console.log(x, y, now_direct);

        let [nx, ny, next_direct] = get_direct(now_direct, grid[x][y], x, y);

        if(nx === hei) {
            nx = 0;
        }

        if(nx === -1) {
            nx = hei - 1;
        }

        if(ny === wid) {
            ny = 0;
        }

        if(ny === -1) {
            ny = wid - 1;
        }


        console.log(nx, ny, next_direct);

        console.log("---------------------")

        if(start_x === nx && start_y === ny) {
            break;
        }


        visited[nx][ny] += 1;
        queue.push([nx, ny, next_direct]);
    }



    let dx = [-1, 0, 1, 0];
    let dy = [0, 1, 0, -1];

    var answer = [];
    return answer;
}

solution(["SL","LR"])