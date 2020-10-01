function fizzBuzz (x) {
    for (let i = 1; i <= x; i++) {
        let output = '';
            if (i % 3 === 0) {output += "Fizz"}
            if (i % 5 === 0) {output += "Buzz"}
            if (output == "") {output = i}
                console.log(output)
        } 
}

fizzBuzz(100)