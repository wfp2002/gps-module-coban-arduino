#define GPS_RX 3
#define GPS_TX 2
#define GPS_Serial_Baud 4800
#include <SoftwareSerial.h>
#include "TinyGPS++.h"

SoftwareSerial gpsSerial(GPS_RX, GPS_TX);
TinyGPSPlus gps;

float gpsLat0;
float gpsLong0;

float gpsLatUltimoLido = 0.00;
float gpsLongUltimoLido = 0.00;

float somaDistancia = 0.00;


/* tabela de cursos de direcao pontos subcolaterais 
Este - Nordeste   ENE
Este - Sudeste    ESE
Leste             E
Nordeste          NE
Noroeste          NW
Norte - Nordeste  NNE
Norte - Noroeste  NNW
Oeste             W
Oeste - Noroeste  WNW
Oeste - Sudoeste  WSW
Sudeste           SE
Sudoeste          SW
Sul               S
Sul - Sudeste     SSE
Sul - Sudoeste    SSW
*/


void setup()
{
  Serial.begin(115200);
  gpsSerial.begin(GPS_Serial_Baud);
}
 
void loop()
{
  bool newData = false;
  unsigned long chars;
  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (gpsSerial.available())
    {
      char c = gpsSerial.read();
      // Serial.write(c); //apague o comentario para mostrar os dados crus
      if (gps.encode(c)) // Atribui true para newData caso novos dados sejam recebidos
        newData = true;
    }
  }
  
  
  if (newData)
  {

    //avante exemplo de ponto fixo
    const double AVANTE_LAT = -22.692943;
    const double AVANTE_LNG = -46.988746;

    //Gerando o ponto inicial fixo do momento que pegou sinal do GPS.
    if (gpsLat0 == 0.0)
    {
      gpsLat0 = gps.location.lat();
      gpsLong0 = gps.location.lng();
    }

    if (gpsLatUltimoLido == 0.0)
    {
      somaDistancia = 0.00;
      gpsLatUltimoLido = gps.location.lat();
      gpsLongUltimoLido = gps.location.lng();      
    } else {
      somaDistancia = somaDistancia + (gps.distanceBetween(gps.location.lat(),gps.location.lng(),gpsLatUltimoLido,gpsLongUltimoLido) / 1000.0);
      gpsLatUltimoLido = gps.location.lat();
      gpsLongUltimoLido = gps.location.lng();
    }
    
    double distanceKmAvante = gps.distanceBetween(gps.location.lat(),gps.location.lng(),AVANTE_LAT,AVANTE_LNG) / 1000.0;
    double courseToAvante = gps.courseTo(gps.location.lat(),gps.location.lng(),AVANTE_LAT,AVANTE_LNG);
    double distanceKmPercorrida = gps.distanceBetween(gps.location.lat(),gps.location.lng(),gpsLat0,gpsLong0) / 1000.0;

    Serial.println("###### Processando informações GPS ######");
    Serial.println("Distancia Percorrida Linha Reta do ponto de partida: " + String(distanceKmPercorrida,3) + " KM");
    Serial.println("Distancia Percorrida Total: " + String(somaDistancia,3) + " KM");
    Serial.println("Distancia Ate Avante LInha Reta: " + String(distanceKmAvante,3) + " KM");
    Serial.println("Direção para o Avante: " + String(courseToAvante) + " Graus");
    Serial.println("Direção Cardeal Bussola Avante: " + String(gps.cardinal(courseToAvante)));
    Serial.println("Precisao do GPS: " + String(gps.hdop.value()) + " Metros"); 
    Serial.println("Altitude: " + String(gps.altitude.meters()) + " Metros");
    Serial.println("------ Outras Informacoes Geograficas ------");
    Serial.println("Coordenadas iniciais ponto de partida:" + String(gpsLat0, 6) + "," + String(gpsLong0, 6));
    Serial.println("http://maps.google.com/maps?q=" + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6));
    Serial.println("Velocidade Atual: " + String(gps.speed.kmph()));
    Serial.println("Quantidade de Satelites utilizados no momento: " + String(gps.satellites.value()));
    Serial.println(); 

    
  }
}
