const binaryOneCount = (string) => string.toString(2).replace(/0/gi,'').length

function solution(n) {
    const nOneCount = binaryOneCount(n);
    
    let result = n+1
    while(n < result){
        const resultOneCount = binaryOneCount(result)

        if(resultOneCount === nOneCount){
            break;
        }
        result++
    }
    return result
}