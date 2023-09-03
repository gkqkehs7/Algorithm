function solution(msg) {

    msg += "@"

    let dic = {
        "A": 1,
        "B": 2,
        "C": 3,
        "D": 4,
        "E": 5,
        "F": 6,
        "G": 7,
        "H": 8,
        "I": 9,
        "J": 10,
        "K": 11,
        "L": 12,
        "M": 13,
        "N": 14,
        "O": 15,
        "P": 16,
        "Q": 17,
        "R": 18,
        "S": 19,
        "T": 20,
        "U": 21,
        "V": 22,
        "W": 23,
        "X": 24,
        "Y": 25,
        "Z": 26,
    }

    let idx = 0;

    let answer = [];
    while(idx < msg.length) {
    
        let word = msg[idx];
        let last_idx = 0;

        for(let i=idx + 1; i<msg.length; i++) {
            if(dic.hasOwnProperty(word)) {
              word += msg[i];
              last_idx = i;
            } else {
                answer.push(dic[word.slice(0, -1)])
                // console.log(word.slice(0, -1))
                let dic_len = Object.keys(dic).length;
                dic[word] = dic_len + 1;
                break;
            }
        }

        if(last_idx === msg.length - 1) {
            answer.push(dic[word.slice(0, -1)])
            // console.log(word.slice(0, -1))
            break;
        }
        
        idx = last_idx

    }

    return answer;
}

solution("ABABABABABABABAB")