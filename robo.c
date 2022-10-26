int IN1 = 4;
int IN2 = 5;
int IN3 = 8;
int IN4 = 7;
int SensorD = 10;        // sensor de linha da direita
int SensorE = 11;       // sensor de linha da esquerda
int E = 2;
int D = 3;

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
 Serial.begin(9600);

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
  tras();
  delay(1000);
//  esquerda();
//  delay(1000);
//  direita();
//  delay(1000);
  
  Serial.println("loop normal");
  

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
  delay(100);
}
