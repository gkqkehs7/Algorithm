function to_binary(num) {
    let next_str = [];
    while(num > 1) {
        next_str.unshift(num % 2);
        num = parseInt(num / 2);
    }

    next_str.unshift(num)
    return next_str.join("");
}

function solution(s) {

    let count = 0;
    let zero_count = 0;

    function binary_change(str) {
        
        if(str === "1") {
            return;
        }

        let one_count = 0;
        for(let i=0; i<str.length; i++) {
            if(str[i] === "0") {
                zero_count++;
            } else {
                one_count++;
            }
        }

        count++;
        binary_change(to_binary(one_count))
    }

    binary_change(s)

    var answer = [count, zero_count];

    return answer;
}

solution("110010101001")