int IN1 = 4;
int IN2 = 5;
int IN3 = 8;
int IN4 = 7;
int SensorD = 10;        // sensor de linha da direita
int SensorE = 11;       // sensor de linha da esquerda
int SensorL = 6;  //define sensor lateral
int SensorF = 13;  //sensor da frente
int E = 2;
int D = 3;
int U = 13;


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
 pinMode(SensorF, INPUT);
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
  frente();
  delay(1000);
  esquerda();
  delay(1000);
  direita();
  delay(1000);
  tras();
  delay(1000);
  D = digitalRead(SensorD);   // lê o pino de entrada
  E = digitalRead(SensorE);

  Serial.print("Direita: ");
  Serial.println( digitalRead(SensorD));
  Serial.print("Esquerda: ");
  Serial.println( digitalRead(SensorE));
  Serial.print("Frente: ");
  Serial.println( digitalRead(SensorF));
  Serial.print("Lateral: ");
  Serial.println( digitalRead(SensorL));

   if ((SensorD == 0)&&(SensorE == 0))
  {
    frente();
    Serial.println(D); 
  }
   if ((SensorD == 0)&&(SensorE == 1))
  {
    direita();
    Serial.println(D); 
  }
  
   if ((SensorD == 1)&&(SensorE == 0))
  {
    esquerda();
    Serial.println("esquerda"); 

  }
   if ((SensorD == 0)&&(SensorE == 1))
  {
    direita();
    Serial.println("direita"); 
  }
  
  if ((SensorD == 1)&&(SensorE == 1))
  {
    parar();
    Serial.println("parar"); 
  }

  delay(100);
}
