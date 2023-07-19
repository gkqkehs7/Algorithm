function isPrimeNumber(number) {
    if (number <= 1) {
      return false;
    }
    for (let i = 2; i <= Math.sqrt(number); i++) {
      if (number % i === 0) {
        return false;
      }
    }
    return true;
  }
  


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


    let answer = 0;

    for(let i=0; i<primes.length; i++) {

        if(isPrimeNumber(primes[i]) === true) {
            answer++;
        }  

    }

    console.log(answer)
    return answer;
}

solution(1000000, 3)