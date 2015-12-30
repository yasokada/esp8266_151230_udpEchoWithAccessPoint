#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

static const char *kSsid = "esp8266";
static const char *kPassword = "12345678";

ESP8266WebServer myServer(80);

void handleRoot() {
    myServer.send(200, "text/html", "<h1>You are connected</h1>");
}

void setup() {
    pinMode(4,OUTPUT);
    delay(1000);

    Serial.begin(115200);
    Serial.println();
    Serial.print("Configuring access point...");
    WiFi.softAP(kSsid, kPassword);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

    myServer.on("/", handleRoot);
    myServer.begin();
    Serial.println("HTTP server started");
}

void loop() {
    myServer.handleClient();
}
