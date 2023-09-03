function solution(s) {

    let arr = s.split(" ").map((str) => parseInt(str))

    arr.sort((prev, next) => {
        return prev - next;
    })

    var answer = `${arr[0]} ${arr[arr.length - 1]}`;
    return answer;
}

solution("-1 -2 -3 -4")