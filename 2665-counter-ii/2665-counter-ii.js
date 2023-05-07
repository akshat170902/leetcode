var createCounter = function(init) {
  let currentCount = init;
  return {
    increment: function() {
       currentCount += 1;
       return currentCount;
    },
    decrement: function() {
       currentCount -= 1;
       return currentCount;
    },
    reset: function() {
       currentCount = init;
       return currentCount;
    },
  }
};