function fizzBuzz (num) {
    for (let i = 1; i <= num; i++) {
        let output = '';
            if (i % 3 === 0) {output += "Fizz"}
            if (i % 5 === 0) {output += "Buzz"}
            if (output == "") {output = i}
                console.log(output)
        } 
}

fizzBuzz(100)