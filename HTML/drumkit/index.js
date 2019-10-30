function clicked(pressed) {


  switch(pressed){
    case 'w' : var tom1 = new Audio("sounds/tom-1.mp3");
             tom1.play();
    break;
    case 'a' : var tom2 = new Audio("sounds/tom-2.mp3");
             tom2.play();
    break;
    case 's' : var tom3 = new Audio("sounds/tom-3.mp3");
             tom3.play();
    break;
    case 'd' : var tom4 = new Audio("sounds/tom-4.mp3");
             tom4.play();
    break;
    case 'j' : var snare = new Audio("sounds/snare.mp3");
             snare.play();
    break;
    case 'k' : var crash = new Audio("sounds/crash.mp3");
             crash.play();
    break;
    case 'l' : var kick = new Audio("sounds/kick-bass.mp3");
             kick.play();
    break;
    default: console.log(pressed);
  }

}


var noOfDrumButtons = document.querySelectorAll("button").length;

for(var i=0;i<noOfDrumButtons;i++)
{
  document.querySelectorAll(".drum")[i].addEventListener("click", function(){
    clicked(this.innerHTML);
    buttonPressed(this.innerHTML);
  });
}

document.addEventListener("keypress", function(e){
  clicked(e.key);
  buttonPressed(e.key);
  });


function buttonPressed(keyPressed){
    var activeButton = document.querySelector("." + keyPressed);
    activeButton.classList.add("pressed");
    setTimeout(function(){
      activeButton.classList.remove("pressed");
    },100);

}
