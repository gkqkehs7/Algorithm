
function check_rule(person1, person2, map) {
    let [x1, y1] = person1;
    let [x2, y2] = person2;

    // 거리가 2 초과인 경우는 무조건 true
    if((Math.abs(x1-x2) + Math.abs(y1-y2)) > 2) {
        return true;
    }

    // x좌표 차이가 없는 경우 (세로 일직선 상)
    if(x1 === x2) {
        if(map[x1][Math.min(y1, y2) +1] !== 'X') {
            return false;
        }
    }

    // y좌표 차이가 없는 경우 (기로 일직선 상)
    if(y1 === y2) {
       if(map[Math.min(x1, x2) +1][y1] !== 'X') {
            return false;
       }
    }

    // x좌표 y좌표 차이가 1씩 나는 경우
    if(Math.abs(x1 - x2) === 1 && Math.abs(y1 - y2) === 1) {

        let small_x = Math.min(x1, x2);
        let small_y = Math.min(y1, y2);

        let case1 = true;
        let case2 = true;
        if(map[small_x][small_y] !== 'X' || map[small_x + 1][small_y + 1] !== 'X') {
            case1 = false;

        } 
        
        if(map[small_x+1][small_y] !== 'X' || map[small_x][small_y + 1] !== 'X') {
            case2 = false;

        } 

        if(!case1 && !case2) {
            return false;
        }
    }

    return true;
}

function solution(places) {

    let answer = [];

    for(let i=0; i<places.length; i++) {
        let place = places[i];

        let people = [];
        for(let j=0; j<place.length; j++) {
            for(let k=0; k<place.length; k++) {
                if(place[j][k] === "P") {
                    people.push([j, k]);
                }   
            }
        }

        let result = 1;
        for(let j=0; j<people.length; j++) {
                for(let k=j+1; k<people.length; k++) {
                    if(check_rule(people[j], people[k], place) === false) {
                        result = 0;
                        break;
                    }
                }
        }

        answer.push(result);
       
    }


    console.log(answer)

    return answer;
}

solution([["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]])