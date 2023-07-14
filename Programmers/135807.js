function get_gcd(a, b){
    if(a<b){
        let temp = a;
        a = b;
        b = temp;
    }
    
    while(b!=0){
        let n = a%b;
        a = b;
        b = n;
    }
    return a;
}

function solution(arrayA, arrayB) {

    let a_gcd = 0;
    if(arrayA.length === 1) {
        a_gcd = arrayA[0]
    } else {
        a_gcd = get_gcd(arrayA[0], arrayA[1]);
    }
     
    for(let i=2; i < arrayA.length; i++) {
        a_gcd = get_gcd(a_gcd, arrayA[i]);
    }

    let b_gcd = 0;
    if(arrayB.length === 1) {
        b_gcd = arrayB[0]
    } else {
        b_gcd = get_gcd(arrayB[0], arrayB[1]);
    }
    
    for(let i=2; i < arrayB.length; i++) {
        b_gcd = get_gcd(b_gcd, arrayB[i]);
    }

    let a = true;
    for(let i=0; i < arrayB.length; i++) {
        if(arrayB[i] % a_gcd === 0) {
            a = false;
            break;
        }
    }


    let b = true;
    for(let i=0; i < arrayA.length; i++) {
        if(arrayA[i] % b_gcd === 0) {
            b = false;
            break;
        }
    }


    if(a && b) {
        return Math.max(a_gcd, b_gcd);
    } else if(a === true) {
        return a_gcd;
    } else if(b === true) {
        return b_gcd;
    } else {
        return 0;
    }
}

console.log(solution([5], [8]))