

function solution(picks, minerals) {

    let graph = [[1,1,1], [5,1,1], [25,5,1]];

    // 이렇게 바꿔버리면 먼저 광물의 순서를 바꾸었기 때문에 먼저 처리할 수 있는 광물들 만을 남겨야한다.
    let pick_cnt = 0;
    for(let i=0; i<picks.length; i++) {
        pick_cnt += picks[i];
    }

    minerals = minerals.slice(0, pick_cnt * 5);

    for(let i=0; i<minerals.length; i++) {
        if(minerals[i] === "diamond") {
            minerals[i] = 0;
        } else if(minerals[i] === "iron") {
            minerals[i] = 1;
        } else {
            minerals[i] = 2;
        }
    }

    const divide_mineral = minerals.reduce((acc, curr, index) => {
        const chunkIndex = Math.floor(index / 5); // 어느 배열에 넣을 것인가
        if (!acc[chunkIndex]) { // 해당 배열이 생성되지 않았으면 배열 생성
          acc[chunkIndex] = [];
        }
        acc[chunkIndex].push(curr); // 현재 값 넣기
        return acc;
      }, []);

    const count = (ary,word) => ary.filter(el => el === word).length

    divide_mineral.sort((a, b) => {
        const a_dia_cnt = count(a, 0);
        const b_dia_cnt = count(b, 0);

        if(a_dia_cnt === b_dia_cnt) {
            const a_iron_cnt = count(a, 1);
            const b_iron_cnt = count(b, 1);

            if(a_iron_cnt === b_iron_cnt) {
                return b_iron_cnt - a_iron_cnt;
            }
        }
        
        return b_dia_cnt - a_dia_cnt; // 우선순위가 높게 하고 싶은경우를 앞에 둔다
    })

    var divide_pick = [];

    for(let i=0; i<picks.length; i++) {
        for(let j=0; j<picks[i]; j++) {
            divide_pick.push(i);
        }
    }

    let answer = 0;

    for(let i=0; i<divide_pick.length; i++) {

        if(divide_mineral[i]) { // 곡괭이가 있는 경우만
            for(let j=0; j<divide_mineral[i].length; j++) {
                
                let mineral = divide_pick[i];
                let pick = divide_mineral[i][j];

                answer += graph[mineral][pick];
            }
        } else {
            break;
        }
        
    }

    console.log(divide_pick)
    console.log(divide_mineral)

    return answer;
}

console.log(solution([0, 1, 2], ["diamond", "diamond", "iron", "diamond", "diamond", "iron", "iron", "iron", "diamond", "iron", "diamond"] ));