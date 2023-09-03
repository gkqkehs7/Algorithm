function getMaxDivisor(n) {

    for (let i = 2; i <= Math.sqrt(n); i++) {
      if(n%i === 0) {
        console.log(i)
      }
      if ( n % i === 0 && n / i <= 1e7 ) {
        return n / i;
      }
    }
    return 1;
  }
  

function solution(begin, end) {

    console.log(getMaxDivisor(100000014))

    // let answer = [];
    // for(let i=begin; i<=end; i++) {
    //     answer.push(getMaxDivisor(i))
    // }

    // if (begin === 1) answer[0] = 0;

    // return answer;
}


solution(100000014, 100000016)