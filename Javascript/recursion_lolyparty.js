//Recursive function, a function that calls itself
//to return a countdown

function countDown(n){
    
    // condition to stop function from calling itself
    if (n < 0){
        return [];
    }

    //condition to continue countdown
    else {
        var count = countDown(n-1);
        count.unshift(n);
        return count;
    }
}


//Display array in console
console.log(countDown(5));