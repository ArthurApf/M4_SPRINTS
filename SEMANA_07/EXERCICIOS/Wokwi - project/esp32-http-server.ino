/* ESP32 HTTP IoT Server Example for Wokwi.com

  https://wokwi.com/arduino/projects/320964045035274834

  To test, you need the Wokwi IoT Gateway, as explained here:

  https://docs.wokwi.com/guides/esp32-wifi#the-private-gateway

  Then start the simulation, and open http://localhost:9080
  in another browser tab.

  Note that the IoT Gateway requires a Wokwi Club subscription.
  To purchase a Wokwi Club subscription, go to https://wokwi.com/club
*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <uri/UriBraces.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
// Defining the WiFi channel speeds up the connection:
#define WIFI_CHANNEL 6

WebServer server(80);

const int LED1 = 26;
const int LED2 = 27;

bool led1State = false;
bool led2State = false;

void sendHtml() {
  String response = R"(
    <!DOCTYPE html> <head> <meta charset="UTF-8">  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous"> <script> var pontos = 0  var pontos2 = 0 function add(){ pontos += 1 document.getElementById("p1").innerHTML = "<h1>" + pontos + "</h1>"; } function add2(){ pontos2 += 1 document.getElementById("p2").innerHTML = "<h1>" + pontos2 + "</h1>"; } function reset(){ location.reload(true) } function status(){ if(pontos == pontos2){ document.getElementById("gg").innerHTML = "<h1>Empatadado</h1>" } else if(pontos > pontos2){ document.getElementById("gg").innerHTML = "<h1>Jogador 1 na frente</h1>" } else if(pontos2 > pontos){ document.getElementById("gg").innerHTML = "<h1>Jogador 2 na frente</h1>" } } </script> <style> #circle{ display: flex; width: 300px; height:300px; border-radius: 50%; align-items: center; margin-right: 9rem; } #circle2{ display: flex; width: 300px; height:300px; border-radius: 50%; align-items: center; } #stats{ height: 50px; width: 400px; border-radius: 15px; margin: 1rem; } .reset{ width: 80px; height: 50px; border-radius: 20px; font-weight: bold; margin-bottom: 0.5rem; } </style> </head> <body> <div class="container"> <div class="d-flex justify-content-center"> <h1>Click Click</h1> </div> <br> <div> <button class="reset" onclick="reset()">Reset</button> <br> <button class="reset">Trocar Player</button> </div> <div class="d-flex justify-content-center"> <button class="d-flex justify-content-center" id="circle" style="background-color:blue" onclick="add(); status()"> <h1>PLAYER 1</h1> </button> <button class="d-flex justify-content-center" id="circle2" style="background-color:blue" onclick="add2(); status()"> <h1>PLAYER 2</h1> </button> </div> <br> <div class="row; d-flex justify-content-center"> <div class="d-flex justify-content-center" style="background-color: purple;" id="stats"> <div><h1>PONTOS PLAYER 1</h1></div> </div> <div class="d-flex justify-content-center" style="background-color: purple;" id="stats"> <div><h1>PONTOS PLAYER 2</h1></div> </div> </div> <div class="row; d-flex justify-content-center"> <div class="d-flex justify-content-center" style="background-color: purple;" id="stats"> <div id="p1"><h1>0</h1></div> </div> <div class="d-flex justify-content-center" style="background-color: purple;" id="stats"> <div id="p2"><h1>0</h1></div> </div> </div> <div class="row; d-flex justify-content-center"> <div class="d-flex justify-content-center" style="background-color: purple;" id="stats"> <div id="gg"><h1>EMPATADO</h1></div> </div> </div> </body>
  )";
  response.replace("LED1_TEXT", led1State ? "ON" : "OFF");
  response.replace("LED2_TEXT", led2State ? "ON" : "OFF");
  server.send(200, "text/html", response);
}

void setup(void) {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

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

  server.on(UriBraces("/toggle/{}"), []() {
    String led = server.pathArg(0);
    Serial.print("Toggle LED #");
    Serial.println(led);

    switch (led.toInt()) {
      case 1:
        led1State = !led1State;
        digitalWrite(LED1, led1State);
        break;
      case 2:
        led2State = !led2State;
        digitalWrite(LED2, led2State);
        break;
    }

    sendHtml();
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(2);
}
