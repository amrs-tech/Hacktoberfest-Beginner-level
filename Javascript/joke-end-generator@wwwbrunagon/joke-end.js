function getRandomSentence () {
    let index= Math.floor(Math.random() * (sentences.length));
    return sentences[index];
}

let sentences= [
    'Eight bytes walk into a bar.  The bartender asks, “Can I get you anything? Yeah, reply the bytes.  “Make us a double.',
    '“Knock, knock.” ...  “Who’s there?” ...  very long pause…. ... “Java.”',
    'There are three kinds of lies: Lies, damned lies, and benchmarks',
    'All programmers are playwrights, and all computers are lousy actors.',
    'Q: How many programmers does it take to screw in a light bulb? | A: None. Its a hardware problem.',
    'Id like to make the world a better place, but they wont give me the source code...',
    'Definition, Programmer: An organism that turns caffeine and pizza into software',
    'A programmer puts two glasses on his bedside table before going to sleep. A full one, in case he gets thirsty, and an empty one, in case he doesn’t.'

  
];

function scribble(){

  let canvas = document.getElementById("joker");
  let context = canvas.getContext("2d");
  context.clearRect(0, 0, canvas.width, canvas.height);
  context.font = "18px Arial";
  context.fillStyle = "#9a48d0"; 
  context.fillText(getRandomSentence(),0, canvas.height/2 + 10);
}

