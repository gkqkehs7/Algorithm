function get_distace(x1, x2, y1, y2) {
    return Math.sqrt(Math.abs(x1-x2)**2 + Math.abs(y1-y2)**2);
}

function solution(m, n, startX, startY, balls) {

    var answers = [];

    for(let i=0; i<balls.length; i++) {
        let [targetX, targetY] = balls[i];

        let wall_x = (startX + targetX) / 2;
        let wall_y = (startY + targetY) / 2;

        console.log(wall_x, 0)
        console.log(wall_x, n)
        console.log(0, wall_y)
        console.log(m, wall_y)

        let answer = 999999999;
    
        let case1 = get_distace(wall_x, startX, 0, startY)**2 + get_distace(wall_x, targetX, 0, targetY)**2 + 2 * get_distace(wall_x, startX, 0, startY) * get_distace(wall_x, targetX, 0, targetY);
        if(case1 < answer) {
            answer = case1;
        }

        let case2 = get_distace(wall_x, startX, n, startY)**2 + get_distace(wall_x, targetX, n, targetY)**2 + 2 * get_distace(wall_x, startX, n, startY) * get_distace(wall_x, targetX, n, targetY);
        if(case2 < answer) {
            answer = case2;
        }

        let case3 = get_distace(0, startX, wall_y, startY)**2 + get_distace(0, targetX, wall_y, targetY)**2 + 2 * get_distace(0, startX, wall_y, startY) * get_distace(0, targetX, wall_y, targetY);
        if(case3 < answer) {
            answer = case3;
        }

        let case4 = get_distace(m, startX, wall_y, startY)**2 + get_distace(m, targetX, wall_y, targetY)**2 + 2 * get_distace(m, startX, wall_y, startY) * get_distace(m, targetX, wall_y, targetY);
        if(case4 < answer) {
            answer = case4;
        }

        console.log(case1);
        console.log(case2);
        console.log(case3);
        console.log(case4);
        answers.push(answer);
    }

    return answers;
}

console.log(solution(10, 10, 3, 7, [[7, 7], [2, 7], [7, 3]]));