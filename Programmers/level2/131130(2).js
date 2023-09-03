function solution(cards) {

    let tree = Array(cards.length).fill(-1);

    function find_parent(child) {
        if(tree[child] === -1) return child;
        return tree[child] = find_parent(tree[child]);
    }

    function merge(child1, child2) {
        let child1_parent = find_parent(child1);
        let child2_parent = find_parent(child2);

        if(child1_parent === child2_parent) return;

        tree[child2_parent] = child1_parent;
    }

    for(let i=1; i<cards.length; i++) {
        tree[cards[i]] = i;
    }

    console.log(tree)
}

solution([8,6,3,7,2,5,1,4])