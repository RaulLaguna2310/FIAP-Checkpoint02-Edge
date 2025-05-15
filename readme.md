🍷 Projeto de Monitoramento Ambiental para Vinícola
 
Integrantes
Henrique Brigo - 563323
 
Eric Yang — 563290
 
Piettra Sattolo — 562538
 
Raul Laguna — 562684
 
Guilherme Reis - 564226
 
Pedro Gomes Souza -  563191
 
 
Descrição do Desafio
Após a apresentação da primeira fase do projeto, os proprietários da vinícola demonstraram satisfação, mas solicitaram novas funcionalidades. 
A principal demanda é o monitoramento preciso das condições ambientais do depósito — especialmente temperatura, umidade e luminosidade — além de alertas visuais 
e sonoros para situações fora dos padrões ideais.
 
Objetivos da Fase 2
Implementar um sistema automatizado que:
 
Meça temperatura, umidade e luminosidade do ambiente;
 
Exiba os dados em tempo real em um display LCD;
 
Sinalize alterações críticas com LEDs e buzzer;
 
Atualize os dados periodicamente com base na média de leituras.
 
Funcionalidades Requeridas
1.  Leitura de Temperatura e Umidade
Utilizar o sensor DHT11, que já possui biblioteca compatível com a IDE do Arduino.
 
O sistema deve calcular e exibir a média de pelo menos 5 leituras, com atualização a cada 5 segundos.
 
2.  Monitoramento de Luminosidade
LEDs indicam o nível de luz ambiente:
 
LED Verde: ambiente escuro;
 
LED Amarelo: ambiente com meia luz + mensagem “Ambiente a meia luz” no display;
 
LED Vermelho: ambiente muito claro + mensagem “Ambiente muito claro” no display.
 
Quando o ambiente estiver totalmente iluminado, o buzzer deve permanecer ligado continuamente.
 
3.  Monitoramento de Temperatura
Faixa ideal: entre 10°C e 15°C
 
Mostrar “Temperatura OK” e valor da temperatura no display.
 
Fora da faixa:
 
Acima de 15°C: exibir “Temp. Alta”, ativar LED Amarelo e buzzer.
 
Abaixo de 10°C: exibir “Temp. Baixa”, ativar LED Amarelo e buzzer.
 
4. Monitoramento de Umidade
Faixa ideal: entre 50% e 70%
 
Mostrar “Umidade OK” e valor da umidade no display.
 
Fora da faixa:
 
Acima de 70%: exibir “Umidade Alta”, ativar LED Vermelho e buzzer.
 
Abaixo de 50%: exibir “Umidade Baixa”, ativar LED Vermelho e buzzer.
 
Tecnologias e Componentes
Arduino IDE
 
Sensor DHT11 (temperatura e umidade)
 
Sensor LDR (luminosidade)
 
Display LCD 16x2
 
LEDs: Verde, Amarelo e Vermelho
 
Buzzer
 
Protoboard e jumpers
 
Etapas de Implementação
Instalar e configurar a biblioteca do sensor DHT11.
 
Conectar e testar o sensor DHT11 com o Arduino.
 
Implementar a lógica para leitura e média de temperatura e umidade.
 
Conectar o display LCD e configurar a exibição dos dados.
 
Conectar os LEDs e o buzzer.
 
Colar o código do arquivo no repositório no Arduino IDE.

Vá em Sketch -> Incluir Biblioteca -> Gerenciar Biblioteca -> Barra de busca digitar: "DHT sensor library by Adafruit" -> Clicar em intala.

Aperte o botão responsável por verificar o código.

Após a verificação, apertar o botão de Update para enviar o código para o arduino.
 
Realizar testes, ajustes e validações finais.
 
Observações Finais
Este projeto representa a segunda fase de uma solução IoT voltada para o controle de qualidade em uma vinícola. A implementação prática exige montagem física do circuito 
e desenvolvimento de código utilizando a IDE do Arduino. Todos os componentes devem estar devidamente conectados e configurados conforme os requisitos para garantir o bom 
funcionamento do sistema.
