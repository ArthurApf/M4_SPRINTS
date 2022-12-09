
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <uri/UriBraces.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
// Defining the WiFi channel speeds up the connection:
#define WIFI_CHANNEL 6

WebServer server(80);


void sendHtml() {
  String response = R'(
<!DOCTYPE html>
<head>
    <meta charset="UTF-8"> 
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <script>
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
    </script>
    <style>
        #circle{
    display: flex;
    width: 300px;
    height:300px;
    border-radius: 50%;
    align-items: center;
    margin-right: 9rem;
    }

    #circle2{
        display: flex;
        width: 300px;
        height:300px;
        border-radius: 50%;
        align-items: center;
    }

    #stats{
        height: 50px;
        width: 400px;
        border-radius: 15px;
        margin: 1rem;
    }

    .reset{
        width: 80px;
        height: 50px;
        border-radius: 20px;
        font-weight: bold;
        margin-bottom: 0.5rem;
    }
</style>



</head>
<body>
    <div class="container">
        <div class="d-flex justify-content-center">
            <h1>Click Click</h1>
        </div>
        <br>
        <div>
            <button class="reset" onclick="reset()">Reset</button>
            <br>
            <button class="reset">Trocar Player</button>
        </div>
        <div class="d-flex justify-content-center">
            <button class="d-flex justify-content-center" id="circle" style="background-color:blue" onclick="add(); status()">
                <h1>PLAYER 1</h1>
            </button>
            <button class="d-flex justify-content-center" id="circle2" style="background-color:blue" onclick="add2(); status()">
                <h1>PLAYER 2</h1>
            </button>
        </div>
        <br>
        <div class="row; d-flex justify-content-center">
            <div class="d-flex justify-content-center" style="background-color: purple;" id="stats">
                <div><h1>PONTOS PLAYER 1</h1></div>
            </div>
            <div class="d-flex justify-content-center" style="background-color: purple;" id="stats">
                <div><h1>PONTOS PLAYER 2</h1></div>
            </div>
        </div>
        <div class="row; d-flex justify-content-center">
            <div class="d-flex justify-content-center" style="background-color: purple;" id="stats">
                <div id="p1"><h1>0</h1></div>
            </div>
            <div class="d-flex justify-content-center" style="background-color: purple;" id="stats">
                <div id="p2"><h1>0</h1></div>
            </div>
        </div>
        <div class="row; d-flex justify-content-center">
            <div class="d-flex justify-content-center" style="background-color: purple;" id="stats">
                <div id="gg"><h1>EMPATADO</h1></div>
            </div>
    </div>
</body>
  )';
}

void setup(void) {
  Serial.begin(115200);
  pinMode(46, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(48, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);
  Serial.print("Connecting to WiFi ");
  Serial.print(WIFI_SSID);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", sendHtml);

  server.begin();
  Serial.println("HTTP server started");

  if(/*pontos > pontos2*/){
    digitalWrite(45, HIGH);
  }

  if(/*pontos < pontos2*/){
    digitalWrite(48, HIGH);
  }

  if(/*pontos == pontos2*/){
    digitalWrite(46, HIGH);
  }
}

void loop(void) {
  server.handleClient();
  delay(2);
}
