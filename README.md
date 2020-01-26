# gps-module-coban-arduino

Usado modulo do GPS Tracker TK-104 mas serve para todos os modulos de GPS da Coban NS-1315 Newstar

Connect the GPS TX (transmit) pin to Digital 3

Connect the GPS RX (receive) pin to Digital 2

O modulo possui RX e TX A e B, foram usados o TX e RX (A), pinos 4 e 5.

Ainda tem erro para as coordenadas, XXXX (S), XXXX (W), pois no endereco do google maps, esta faltando o sinal de (-) menos na frente das coordenadas.

Se for ligar a energia diretamente no modulo do GPS, ligar 3.3V na entrada VCC (pino 12), no meu caso estou usando o aparelho completo, sem alteracoes, so conectei o TX e RX.

Referencia;

https://forum.arduino.cc/index.php?topic=194110.0
