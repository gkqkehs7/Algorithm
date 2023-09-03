function solution(n, wires) {

    let tree = [];
    let answer = 999999999;

    function get_parent(child) {
        if(tree[child] === child) return child;

        return tree[child] = get_parent(tree[child])
    }

    function merge(child1, child2) {
        let parent1 = get_parent(child1);
        let parent2 = get_parent(child2);

        if(parent1 === parent2) return;

        if(parent1 > parent2) {
            tree[parent1] = parent2;
        } else {
            tree[parent2] = parent1;
        }

    }

    let now = 0;
    for(let i=0; i<wires.length; i++) {

        for(let i=0; i<=n; i++) {
            tree[i] = i;
        }

        for(let i=0; i<wires.length; i++) {
            if(i == now) {
                continue;
            }

            const [a, b] = wires[i];
            merge(a, b);
        }


        console.log(tree)
        
       

        for(let j=1; j<=n; j++) {
            tree[j] = get_parent(j)
        }

        console.log(tree)
    
    
   
        let count_one = 0;
        let count_else = 0;
        
        for(let j=1; j<tree.length; j++) {
            if(tree[j] === 1) {
                count_one ++;
            } else {
                count_else++;
            }
        }
    
        now++;

        answer = Math.min(answer, Math.abs(count_one - count_else))
    }


    return answer;
}

solution(4,[[1, 2], [3, 4], [2, 3]])