#ifndef SMART_ESP_UTILS_H
#define SMART_ESP_UTILS_H

#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

/* ----------- WebSocket Global ----------- */
AsyncWebSocket ws("/ws");

/* ----------- Structure de données ----------- */
struct AutoUpdatePayload {
  String ecran1 = "";
  String ecran2 = "";
  String ecran3 = "";
  String ecran4 = "";
  float indicateur1 = 0.0;
  float indicateur2 = 0.0;
  float indicateur3 = 0.0;
  float indicateur4 = 0.0;
  String bulb1 = "";
  String bulb2 = "";
  String bulb3 = "";
  String bulb4 = "";
  String notif = "false";
  String ia = "false";
  String statusMessage = "";
};

/* ----------- Connexion Wi-Fi ----------- */
void connectToWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  Serial.print("Connexion au WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

/* ----------- Événement WebSocket ----------- */
void onWebSocketEvent(
  AsyncWebSocket* server,
  AsyncWebSocketClient* client,
  AwsEventType type,
  void* arg,
  uint8_t* data,
  size_t len,
  String* lastCommandPtr
) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("Client WebSocket #%u connecté depuis %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("Client WebSocket #%u déconnecté\n", client->id());
      break;
    case WS_EVT_DATA:
      AwsFrameInfo* info = (AwsFrameInfo*)arg;
      if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        data[len] = 0;
        *lastCommandPtr = (char*)data;
        Serial.printf("Commande reçue : %s\n", (char*)data);
      }
      break;
  }
}

/* ----------- Initialisation WebSocket ----------- */
void setupWebSocket(AsyncWebServer& server, String* lastCommandPtr) {
  ws.onEvent([lastCommandPtr](AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
    onWebSocketEvent(server, client, type, arg, data, len, lastCommandPtr);
  });
  server.addHandler(&ws);
  server.begin();
}

/* ----------- Fonction d’envoi Auto-Update ----------- */
void sendAutoUpdate(const AutoUpdatePayload& payload) {
  StaticJsonDocument<512> doc;

  doc["Ecran1"] = payload.ecran1.isEmpty() ? String(millis()) : payload.ecran1;
  doc["Ecran2"] = payload.ecran2;
  doc["Ecran3"] = payload.ecran3;
  doc["Ecran4"] = payload.ecran4;

  doc["Indicateur1"] = payload.indicateur1;
  doc["Indicateur2"] = payload.indicateur2;
  doc["Indicateur3"] = payload.indicateur3;
  doc["Indicateur4"] = payload.indicateur4;

  doc["Bulb1"] = payload.bulb1;
  doc["Bulb2"] = payload.bulb2;
  doc["Bulb3"] = payload.bulb3;
  doc["Bulb4"] = payload.bulb4;

  doc["notif"] = payload.notif;
  doc["AI"] = payload.ia;
  doc["message"] = payload.statusMessage;

  // Infos système fixes
  doc["status"] = "auto-update";
  doc["Wifi"] = WiFi.SSID();
  doc["ip_address"] = WiFi.localIP().toString();
  doc["mac_address"] = WiFi.macAddress();
  doc["signal_strength"] = WiFi.RSSI();
  doc["gateway_ip"] = WiFi.gatewayIP().toString();
  doc["free_memory"] = ESP.getFreeHeap();
  doc["flash_memory"] = ESP.getFlashChipSize();

  String output;
  serializeJson(doc, output);
  ws.textAll(output);
  Serial.println("🔄 Mise à jour envoyée via AutoUpdatePayload");
   
   
}

#endif
