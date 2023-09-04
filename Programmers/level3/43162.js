function solution(n, computers) {

    let tree = Array(n).fill(-1);

    function get_parent(child) {
        if(tree[child] === -1) {
            return child;
        }

        return tree[child] = get_parent(tree[child])
    }

    function union(child1, child2) {
            
        let parent1 = get_parent(child1);
        let parent2 = get_parent(child2);

        if(parent1 === parent2) {
            return;
        }

        if(parent1 < parent2) {
            tree[parent2] = parent1;
        } else {
            tree[parent1] = parent2;
        }
    }

    for(let i=0; i<computers.length; i++) {
        let computer = computers[i];

        for(let j=0; j<computer.length; j++) {
            if(i === j) continue;

            if(computer[j] === 1) {
                union(i, j);
            }
            
        }
    }


    console.log(tree);

    var answer = 0;

    for(let i=0; i<tree.length; i++) {
        if(tree[i] === -1) answer++;
    }

    return answer;
}

solution(5, [[1, 1, 0, 0, 0], [1, 1, 1, 0, 0], [0, 1, 1, 0, 0], [0, 0, 0, 1, 1], [0, 0, 0, 1, 1]]	)