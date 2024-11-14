#include <WiFi.h>
#include <HTTPClient.h>

// WiFi Credentials
const char* ssid = "KONTRAKKAN 01";
const char* password = "KEPOAMAT";

// Firestore API Details
const char* FIREBASE_PROJECT_ID = "hydsmartfire";
const char* FIREBASE_API_KEY = "AIzaSyCBD0g2s5pAVGQ-Fue464ZgyHZRDtdioj4";

void setup() {
  Serial.begin(115200);

  // Menghubungkan ke Wi-Fi
  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi Terhubung!");

  // Menulis data ke Firestore
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String("https://firestore.googleapis.com/v1/projects/") + FIREBASE_PROJECT_ID + "/databases/(default)/documents/users";
    http.begin(url);

    // Header untuk REST API
    http.addHeader("Content-Type", "application/json");
    String jsonPayload = R"({
      "fields": {
        "name": {"stringValue": "John Doe"},
        "age": {"integerValue": 25}
      }
    })";

    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      Serial.println("Data berhasil dikirim ke Firestore!");
      Serial.println("Response: " + http.getString());
    } else {
      Serial.print("Error saat mengirim data: ");
      Serial.println(http.errorToString(httpResponseCode));
    }

    http.end(); // Menutup koneksi HTTP
  }
}

void loop() {
  // Tidak ada operasi loop
}
