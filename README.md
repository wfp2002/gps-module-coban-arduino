# gps-module-coban-arduino

Usado modulo do GPS Tracker TK-104 mas serve para todos os modulos de GPS da Coban NS-1315 Newstar

Connect the GPS TX (transmit) pin to Digital 3

Connect the GPS RX (receive) pin to Digital 2

O modulo possui RX e TX A e B, foram usados o TX e RX (A), pinos 4 e 5.

Ainda tem erro para as coordenadas, XXXX (S), XXXX (W), pois no endereco do google maps, esta faltando o sinal de (-) menos na frente das coordenadas.

Se for ligar a energia diretamente no modulo do GPS, ligar 3.3V na entrada VCC (pino 12), no meu caso estou usando o aparelho completo, sem alteracoes, so conectei o TX e RX.

O modulo so funcionou com baud Rate do GPS em 4800. Para informacoes do monitor serial esse pode ser 115200

#############################################################

Conversao das coordenadas de GPS para usar no Google MAPS

DMS to DD

Location: 4659.2270W

DD = d + (min/60) + (sec/3600)

DD = 46 + (59/60) + (22.70/3600)

DD = 46 + 0.9833333 + 0.006305555

DD = 46.989638855

#############################################################

Referencia;

https://forum.arduino.cc/index.php?topic=194110.0
