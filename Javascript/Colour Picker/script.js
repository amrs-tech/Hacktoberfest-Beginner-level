var colour1 = document.getElementById("colour1");
var colour2 = document.getElementById("colour2");
var body = document.getElementById("gradient");
var css = document.querySelector("h3");

// console.log(colour1.value);
// console.log(colour2.value);

function setGradient() {
	body.style.background = 
	"linear-gradient(to right, " 
	+ colour1.value 
	+ ", " 
	+ colour2.value 
	+ ")";
	css.innerHTML = body.style.background + " ";
}


colour1.addEventListener("input", setGradient);
colour2.addEventListener("input", setGradient);