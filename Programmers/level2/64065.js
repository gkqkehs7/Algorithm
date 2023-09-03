function solution(s) {

    // . 빈 문자열은 split() 메서드를 사용할 때 인접하는 구분자가 있을 때 빈 문자열로 처리되는 특성 때문에 발생합니다.
    // let str = s.replace(/[{},]/g, "");
    // let numbers = s.split(/[{},]/).filter(item => item !== "");

    let arr = [];
    s.split("},{").map((str) => {
        arr.push(str.split(/[{},]/).filter((item) => item !== ""))
    })

    let temp = arr.map((items) => items.map((item) => parseInt(item, 10)))
    
    temp.sort((a,b)=> a.length - b.length)

    let answer = [];

    temp.forEach((v)=>{
        v.forEach((val)=>{
            if(!answer.includes(parseInt(val))){
                answer.push(parseInt(val))
            }
        })
    })

    console.log(answer)

    return answer;
}

solution("{{2},{2,1},{2,1,3},{2,1,3,4}}")