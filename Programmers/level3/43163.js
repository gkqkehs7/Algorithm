function compare(str1, str2) {

    let diff = 0;
    for(let i=0; i<str1.length; i++) {
       if(str1[i] !== str2[i]) {
        diff++;
       }
    }  
    return diff;
}

function solution(begin, target, words) {

    const visited = [];
    const queue = [[begin,0]];

    while(queue.length > 0) {

        let [word, count] = queue.shift();
        
        console.log(word, count)
        if(word === target) return count;

        for(let i=0; i<words.length; i++) {

            let next_word = words[i];

            if(!visited.includes(next_word)) {
                if(compare(word, next_word) === 1) {
                    queue.push([next_word, ++count])
                    visited.push(next_word)
                }
            }
        }
    }

   
    return 0;
}
