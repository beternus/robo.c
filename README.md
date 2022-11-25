# robo.c
Robô Seguidor de Linha com Arduino
Este código em C serve para controlar um robô, nele, as variáveis estão declaradas (usamos variáveis inteiras). Existe um setup das variáveis
Foram declaradas as entradas do arduino, dentre elas seis entradas digitais. O código possui, antes do void loop (uma espécie de int main) as funções para movimentação do robô. Estas funções são: frente(), esquerda(), direita(), tras(), parar().
Dentro destas funções, existem ativações das saías, IN1,IN2, IN3,IN4.
Elas enviam sinais digitais de 1 ou 0 (0 ou 5V) para a placa da ponte H

![image](https://user-images.githubusercontent.com/90293389/198030272-ea027de5-800e-47a5-9455-fed582887c5f.png)

A placa da ponte H, com um transistor de potência L298N, recebe esses sinais e envia para os motores,
que tracionam as rodas num sentido ou no outro. Quando uma roda gira para um lado e a outra gira para outro, ela se movimenta na lateral.
Este é o princípio de movimento para a esquerda e para a direita. Quando as duas rodas giram na mesma direção, HIGH ou 1, o robô anda para frente. 
A função trás é importante para o robô poder voltar e dobrar à esquerda ou à direita quando se deparar com um obstáculo.
Na parte do Ultrassom, é necessário incluir a biblioteca NewPing.h dentro do próprio Arduino. Foi incluído também um sensor lateral. Está sendo ajustada a lógica para o carrinho ser guiado pelos sensores corretamente...

O robo deve contar na lateral as passagens na linha. ex: ele pode contar duas e depois virar para o lado.
para isso, criar uma variavel do sensor lateral e contar. 
a contagem do robo 14 deve ser: G7, segundo o prof. Jean.
ele sai do G e chega no 7. portanto ele conta 3 na lateral e aí vira à esquerda
int L;
for (a=0; a>3; a++){
   ...
}

O trabalho foi convertido em um texto para Congresso Acadêmico
