int IN1 = 4;
int IN2 = 5;
int IN3 = 8;
int IN4 = 7;
int SensorD = 10;        // sensor de linha da direita
int SensorE = 11;       // sensor de linha da esquerda
int SensorL = 6;  //define sensor lateral
int E = 2;
int D = 3;
int U = 13;

//Carrega a biblioteca do sensor ultrassonico
//#include Ultrasonic ultrasonic(pino_trigger, pino_echo);

#include <NewPing.h>
//Define os pinos para o trigger e echo
#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define MAX_DISTANCE 150

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
  Serial.begin(9600);

  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(D, INPUT);
 pinMode(E, INPUT);
 pinMode(SensorD, INPUT);
 pinMode(SensorE, INPUT);
 pinMode(U, INPUT);

//inicia parado
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 digitalWrite(E, LOW);
 digitalWrite(D, LOW);

}

void frente()
{
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay (200);
}

void esquerda()
{
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay(200);
}

void direita()
{
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay(200);
}

void tras()
{
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay (200);
}

void parar()
{
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
 delay(200);
}

// so a preparacao
void loop()
{
  D = digitalRead(SensorD);   // lê o pino de entrada
  E = digitalRead(SensorE);

  Serial.print("Ping: ");
//  Serial.print(sonar.ping_cs());
  Serial.println("cm");

   if ((D == 1)&&(E == 0))
  {
    esquerda();
    Serial.println("esquerda"); 

  }
   if ((D == 0)&&(E == 1))
  {
    direita();
    Serial.println("direita"); 
  }
  
  if ((D == 1)&&(E == 1))
  {
    parar();
    Serial.println("parar"); 
  }

  delay(100);
}
