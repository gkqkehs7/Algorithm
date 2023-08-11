function solution(name) {
    let alphabet = { "A": 1, "B": 2, "C": 3, "D":4, "E": 5,
    "F":6, "G":7, "H":8, "I":9, "J":10, "K":11, "L":12, "M":13, "N":14, "O":15, "P": 16, "Q":17,
    "R":18, "S":19, "T":20, "U":21, "V":22, "W":23, "X":24, "Y":26, "Z": 27 }

    let move = 0;
    let a_idx = 0;
    for(let i=0; i<name.length; i++) {
        if(name[i] !== 'A') {
            move++;
        } else {
            a_idx = i;
            break;
        }
    }

    let else_idx = 0;
    for(let i=a_idx + 1; i<name.length; i++) {
        if(name[i] !== 'A') {
            else_idx = i;
            break;
        }
    }

    move = Math.min(name.length - 1, (move - 1) * 2 + name.length - else_idx);

    console.log(move)

    let count = 0;
    for(let i=0; i<name.length; i++) {
        count += Math.min(alphabet[name[i]] - 1, 27 - alphabet[name[i]]);
    }

    let answer = count + move;
    return answer;
}

solution("JEROEN")