function solution(n, k) {
    let result = [];
    while(k <= n) {
        let rest = n % k;
        result.unshift(rest);

        n = parseInt(n / k);
    }
    result.unshift(n);

    let primes = [];
    let temp = "";

    for(let i=0; i<result.length; i++) {
        if(result[i] !== 0) {
            temp += result[i].toString();
        } else {
            if(temp !== "") {
                primes.push(parseInt(temp));
                temp = "";
            }
            
        }
    }

    if(temp !== "") {
        primes.push(parseInt(temp));
    }
    
    let isPrime = Array(10000001).fill(0);
    
    isPrime[0] = 1;
    isPrime[1] = 1;
    isPrime[2] = 0;

    for(let i=2; i<= Math.sqrt(10000001); i++) {
        if(isPrime[i] === 0) {
            for(let j = i + i; j < 10000001; j += i) {
                isPrime[j] = 1;
            }
        }   
    }

    let answer = 0;

    for(let i=0; i<primes.length; i++) {

        if(isPrime[primes[i]] === true) {
            answer++;
        }  

    }

    console.log(answer)
    return answer;
}

solution(1000000, 3)