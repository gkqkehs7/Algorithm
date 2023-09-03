function solution(n,a,b)
{
    let numA=a,numB=b,tried = 0
    while(numA !== numB){
        numA = Math.ceil(numA/2)
        numB = Math.ceil(numB/2)
        tried++
    }

    return tried
}