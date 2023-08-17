function get_num(number, bianry) {
    let result = [];

    while(number > 0) {
        let temp = number % bianry;
        if(temp === 10) {
            result.unshift("A")
        } else if(temp === 11) {
            result.unshift("B")
        } else if(temp === 12) {
            result.unshift("C")
        } else if(temp === 13) {
            result.unshift("D")
        } else if(temp === 14) {
            result.unshift("E")
        } else if(temp === 15) {
            result.unshift("F")
        } else {
            result.unshift(number % bianry);
        }
   
        number = parseInt(number / bianry);
    }

    return result.join("")
}

function solution(n, t, m, p) {

    let total = 0;
    let count = 1;
    let str = ""
    let answer = "";

    if(p === 1) {
        total++;
        answer += "0"
    }

    while(total < t) {
        
        str += get_num(count, n);

        console.log(str)

        count += 1;

        if(str.length >= p) {
            answer += str[p - 1];
            str = str.slice(p, str.length);
            total++;
        }
    }

    console.log(answer)

    return answer;
}


solution(2, 4, 2, 1);