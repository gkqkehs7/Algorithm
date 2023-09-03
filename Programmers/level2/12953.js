function get_gcd(a, b) {
    if(a < b) {
        let temp = a;
        a = b;
        b = temp;
    }

    while(b !== 0) {
        let rest = a%b;
        a = b;
        b = rest;
    }

    return a;
}

function get_lcm(a, b) {
    let gcd = get_gcd(a, b);
    
    return (a * b) / gcd;
}

function solution(arr) {

    let lcm = arr[0];
    for(let i=1; i<arr.length; i++) {
        lcm = get_lcm(lcm, arr[i]);
    }

    return lcm;
}

solution([2,6,8,14])