var pontos = 0 
var pontos2 = 0



function add(){
    pontos += 1
    document.getElementById("p1").innerHTML = "<h1>" + pontos + "</h1>";
}

function add2(){
    pontos2 += 1
    document.getElementById("p2").innerHTML = "<h1>" + pontos2 + "</h1>";
}

function reset(){
    location.reload(true)
}

function status(){
    if(pontos == pontos2){
        document.getElementById("gg").innerHTML = "<h1>Empatadado</h1>"
    }
    else if(pontos > pontos2){
        document.getElementById("gg").innerHTML = "<h1>Jogador 1 na frente</h1>"
    }
    else if(pontos2 > pontos){
        document.getElementById("gg").innerHTML = "<h1>Jogador 2 na frente</h1>"
    }
}