int IN1 = 4;
int IN2 = 5;
int IN3 = 8;
int IN4 = 7;
int SensorD = 10;        // sensor de linha da direita
int SensorE = 11;       // sensor de linha da esquerda
int E = 2;
int D = 3;

//Carrega a biblioteca do sensor ultrassonico
#include Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Define os pinos para o trigger e echo
#define pino_trigger 12
#define pino_echo 13

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);


void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(D, INPUT);
 pinMode(E, INPUT);
 pinMode(SensorD, INPUT);
 pinMode(SensorE, INPUT);

//inicia parado
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 digitalWrite(E, LOW);
 digitalWrite(D, LOW);

 Serial.begin(115200);
 Serial.println("Lendo dados do sensor…");
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

  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  cmMsec = ultrasonic.distanceRead(CM);
  inMsec = ultrasonic.distanceRead(INC);

  //Exibe informacoes no serial monitor
  Serial.print(“Distancia em cm: “);
  Serial.print(cmMsec);
  Serial.print(” – Distancia em polegadas: “);
  Serial.println(inMsec);

  delay(1000);
  
//  delay(50);
//  Serial.print("Ping: ");
//  int dist = sonar.ping();
//  Serial.print(sonar.convert_cm(dist)); //send ping, get distance
//  Serial.println("us");
  
  
  
  frente();
  delay(1000);
//  esquerda();
//  delay(1000);
//  direita();
//  delay(1000);
  
  Serial.println("loop normal");

  do{

  if((D == 1) && (E == 1))
 {
    frente();
     Serial.println("frente"); 
  }
  
  else if ((D == 1)&&(E == 0))
  {
    esquerda();
    Serial.println("esquerda"); 

  }
  else if ((D == 0)&&(E == 1))
  {
    direita();
    Serial.println("direita"); 
  }
  
  else if ((D == 1)&&(E == 1))
  {
    parar();
    Serial.println("parar"); 
  }
  }while (U==0);
    if (U==1)
  {
    parar();
  }
  delay(100);
}

  }
  else if ((D == 0)&&(E == 1))
  {
    direita();
    Serial.println("direita"); 

  }
  else if ((D == 1)&&(E == 1))
  {
    parar();
    Serial.println("parar"); 
  }
  if (U == 1)
  {
    parar();
  }
  delay(100);
}
