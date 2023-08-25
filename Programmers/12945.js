function solution(n) {

    let arr = Array(100001).fill(0);

    arr[0] = 0;
    arr[1] = 1;
    for(let i=2; i<100001; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % 1234567;              
    }

    var answer = arr[n] % 1234567;

    console.log(answer);
    return answer; 
}


solution(6)