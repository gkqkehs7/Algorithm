function solution(n, words) {
  
    let word_dic = {};

    let prev = words[0][words[0].length - 1];

    word_dic[words[0]] = 0;

    let idx = 0;

    for(let i=1; i<words.length; i++) {

        let next_word = words[i];
        let first_alphabet = next_word[0];
        let last_alphabet = next_word[next_word.length - 1];

        // console.log(prev, first_alphabet)

        // console.log(word_dic)

        if(word_dic.hasOwnProperty(next_word)) {
            idx = i;
            break;
        }

        if(first_alphabet !== prev) {
            idx = i;
            break;
        }

        word_dic[next_word] = 0;
        prev = last_alphabet;
    }

    if(idx === 0) {
        return [0, 0]
    }

    idx = idx + 1;
    
    let number = 0;
    let order = 0;

    if(idx % n === 0) {
        number = n;
    } else {
        number = idx % n;
    }

    order = Math.ceil(idx / n);
    
    let answer = [number, order];

    // 번호, 차례
    console.log(answer)

    return answer;
}

solution(2, ["hello", "one", "even", "never", "now", "world", "draw"]);