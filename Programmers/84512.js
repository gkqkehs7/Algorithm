function get_next(alphabet) {
    if(alphabet === "A") {
        return 'E'
    } else if(alphabet === "E") {
        return 'I';
    } else if(alphabet === "I") {
        return 'O';
    } else if(alphabet === "O") {
        return 'U'
    } else if(alphabet === "U") {
        return -1;
    }
}


function solution(word) {

    let queue = [];
    queue.push("A");

    let answer = 1;

    while(queue.length > 0) {
        let last = queue[queue.length - 1];

        if(word === queue.join("")){
            break;
        }
      
        if(queue.length === 5) {

            while(last === "U") {
                queue.pop();
                last = queue[queue.length - 1];

                if(last !== "U") {
                    break;
                }
            }

            queue[queue.length - 1] = get_next(last);

        
        } else {
            queue.push("A");
        }

        answer++;
    }


    console.log(answer);

    return answer;
}

solution("EIO")