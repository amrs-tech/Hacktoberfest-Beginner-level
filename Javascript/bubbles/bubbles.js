const canvas = document.querySelector('canvas')
const c = canvas.getContext('2d')

canvas.width = innerWidth
canvas.height = innerHeight

const colors = ['#2185C5', '#7ECEFD', '#FFF6E5', '#FF7F66', '#330136', '#5E1742', '#962E40', '#C9463D', '#FF5E35']

//Quando a tela muda de tamanho as bolas caem novamente
addEventListener('resize', () => {
    canvas.width = innerWidth
    canvas.height = innerHeight
    init();
})

let gravity = 1;
let friction = 0.99;

//Quando clica ele reinicia a pagina e as bolas caem novamente
window.addEventListener('click',function(){
   init();
})


// Objects
function Ball(x, y, radius, color,vely,velx) {
    this.x = x
    this.y = y
    this.radius = radius
    this.color = color
    this.vely = vely;
    this.velx = velx;


    this.draw = function() {
        c.beginPath()
        c.arc(this.x, this.y, this.radius, 0, Math.PI * 2, false)
        c.fillStyle = this.color
        c.fill()
        c.closePath()
    }

    this.update = function() {
        this.draw()
        //Verifica a queda da bola
        if(this.y + this.radius + this.vely > canvas.height){
            this.vely = -this.vely * friction;
        }else{
            this.vely += gravity;
        }
        //Verifica se a bola bateu nas laterais
        if(this.x + this.radius + this.velx > canvas.width || this.x + this.radius <= 0 ){
            this.velx = -this.velx;
        }

        this.x += this.velx;
        this.y += this.vely;
    }
}
// Implementation
let ball;
let ballLength = 400;


let x,y,radius,color,vely,velx;

function init() {
    ball = [];    
    for(let i = 0; i < ballLength;i++){
        radius = Math.random() * 40;
        x = (Math.random() * (canvas.width - radius));
        y = Math.floor((Math.random() * canvas.height)-(radius*3));
        color = Math.floor(Math.random() * colors.length)-1;
        vely = Math.random() * 5;
        velx = (Math.random() - 0.4) * 5;
        ball.push(new Ball(x,y,radius,colors[color],vely,velx));
    }
}


// Animation Loop
function animate() {
    requestAnimationFrame(animate)
    c.clearRect(0, 0, canvas.width, canvas.height)
    
    ball.forEach(ball =>{
        ball.update();
    })
}

init()
animate()