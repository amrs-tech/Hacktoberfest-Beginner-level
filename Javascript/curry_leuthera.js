const curry = function(f, ...args) {
    return args.length >= f.length
        ? f.apply(null, args)
        : (...remaining) => curry(f, ...args, ...remaining)
}

// Example
const add = curry(function (x, y) {
	return x + y;
});
add(1)(2);
