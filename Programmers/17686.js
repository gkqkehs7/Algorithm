function solution(files) {

    let sort_files = [];
    for(let i=0; i<files.length; i++){                
        let head = /^[\D]*/g.exec(files[i])[0];
        files[i] = files[i].replace(/^[\D]*/g,'');
        
        let number = /[\d]*/g.exec(files[i])[0]; 
        files[i] = files[i].replace(/[\d]*/,'');
                
        let tail = files[i];        
        sort_files.push( {'head':head, 'number':number, 'tail':tail});
    }   

    console.log(sort_files)

    sort_files.sort((prev, next) => {  
        
        if(prev.head.toLowerCase() > next.head.toLowerCase()) {
            return 1;
        }

        if(prev.head.toLowerCase() === next.head.toLowerCase()) {

            if(parseInt(prev.number) === parseInt(next.number)) {
                return 0;
            }

            return parseInt(prev.number) - parseInt(next.number)
        }

        return -1;
    })

    console.log(sort_files)

    let answer = [];

    for(let i=0; i<sort_files.length; i++) {
        answer.push(sort_files[i].head + sort_files[i].number + sort_files[i].tail)
    }

    console.log(answer)

 

    return answer;
}

solution(["MUZI1.png", "muzi1.png"] )