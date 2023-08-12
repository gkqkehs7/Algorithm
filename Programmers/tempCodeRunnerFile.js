   numbers.sort((prev, next) => {
       let first = prev + next;

       let second = next + prev;

       if(first > second) {
        return prev - next;
       }

       return next - prev;
    });