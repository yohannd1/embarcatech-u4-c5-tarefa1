# Tarefa U4.C5.1

Esta tarefa é composta por duas atividades, cada uma em sua respectiva
pasta.

## Execução

Para rodar estas simulações no Wokwi via VSCode, basta abrir a pasta da
atividade (`atividade1/` ou `atividade2`) pelo editor. É possível que
seja necessário também importar o projeto (dita pasta) antes disso.

## Atividade 1 (`atividade1/`)

Esta atividade consiste em um semáforo conectado às portas GPIO 11, 12 e
13, que muda de estado a cada 3 segundos, enquanto uma mensagem é
enviada via serial a cada 1 segundo.

Testando na placa BitDogLab, os LEDs acenderam na ordem desejada, mas
como não há LED amarelo, o resultado não foi idêntico ao da simulação.

## Atividade 2 (`atividade2/`)

Esta atividade consiste em um botão conectado à porta GPIO 5 que, ao ser
pressionado, acende todos os LEDs e, a cada 3 segundos, um deles se
apaga.
