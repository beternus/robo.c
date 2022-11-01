int IN1 = 4;
int IN2 = 5;
int IN3 = 8;
int IN4 = 7;
int SensorD = 10;        // sensor de linha da direita
int SensorE = 11;       // sensor de linha da esquerda
int SensorL = 6;    //define sensor lateral
int SensorF = 13;  //sensor da frente

//Carrega a biblioteca do sensor ultrassonico
//#include Ultrasonic ultrasonic(pino_trigger, pino_echo);

//#include <NewPing.h>
//Define os pinos para o trigger e echo
//#define TRIGGER_PIN 12
//#define ECHO_PIN 13
//#define MAX_DISTANCE 150

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
  Serial.begin(9600);
  //PinMode define os pinos como saida ou entrada
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(SensorD, INPUT);
 pinMode(SensorE, INPUT);
 pinMode(SensorF, INPUT);
 pinMode(SensorL, INPUT);

//inicia parado
 digitalWrite(IN1, LOW);  
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
// digitalWrite(SensorD, LOW);
// digitalWrite(SensorE, LOW);
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
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 delay(200);
}

// so a preparacao
void loop()
{
 // digitalRead(SensorD);   // lê o pino de entrada
 // digitalRead(SensorE);
 // digitalRead(SensorF);   // lê o pino de entrada
//  digitalRead(SensorL);   // lê o pino de entrada

  Serial.print("Direita: ");
  Serial.println( digitalRead(SensorD));
  Serial.print("Esquerda: ");
  Serial.println( digitalRead(SensorE));
  Serial.print("Frente: ");
  Serial.println( digitalRead(SensorF));
  Serial.print("Lateral: ");
  Serial.println( digitalRead(SensorL));
/*
   if ((SensorD == 1)&&(SensorE == 0))
  {
    esquerda();
    Serial.println(D); 

  }
   if ((SensorD == 0)&&(SensorE == 1))
  {
    direita();
    Serial.println(D); 
  }
  
  if ((D == 1)&&(E == 1))
  {
    parar();
    Serial.println(D); 
  }*/
  delay(250);
}
