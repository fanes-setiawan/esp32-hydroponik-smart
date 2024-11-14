#include <WiFi.h>

// Ganti dengan nama Wi-Fi (SSID) dan password Anda
const char* ssid = "KONTRAKKAN 01";
const char* password = "KEPOAMAT";

void setup() {
  // Memulai Serial Monitor untuk debugging
  Serial.begin(115200);

  // Memulai koneksi ke Wi-Fi
  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);

  // Tunggu sampai koneksi berhasil
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  // Menampilkan IP Address ESP32
  Serial.println("\nWiFi Terhubung!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Tambahkan kode Anda di sini
}
