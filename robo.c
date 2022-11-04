int IN1 = 4;
int IN2 = 5;
int IN3 = 8;
int IN4 = 7;
int SensorD = 10;        // sensor de linha da direita
int SensorE = 11;       // sensor de linha da esquerda
int SensorL = 6;  //define sensor lateral
int SensorF = 13;  //sensor da frente
int E = 2;
int D = 3; //REVISAR PABLO
int F = 13;
int L = 1;

int contagemlateral;

void setup(){
  Serial.begin(9600);
  
  //Define os pinos como saida e entrada
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 
 pinMode(D, INPUT);
 pinMode(E, INPUT);
 pinMode(SensorD, INPUT);
 pinMode(SensorE, INPUT);
 pinMode(SensorF, INPUT);

//inicia parado
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 
}

void frente()
{
  if (F == LOW)
  {
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay (200);
  } 
}

void esquerda()
{
   if (F == LOW)
  {
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay(200);
  }
}

void direita()
{
   if (F == LOW)
  {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay(200);
  }
}

void tras()
{
   if (F == LOW)
  {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay (200);
  }
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
  delay(15);
  D = digitalRead(SensorD);   // lê o pino de entrada
  E = digitalRead(SensorE);
  F = digitalRead(SensorF);
  L = digitalRead(SensorL);
  
  Serial.print("Direita: ");
  Serial.println( digitalRead(SensorD));
  Serial.print("Esquerda: ");
  Serial.println( digitalRead(SensorE));
  Serial.print("Frente: ");
  Serial.println( digitalRead(SensorF));
  Serial.print("Lateral: ");
  Serial.println( digitalRead(SensorL));

 if ((D == LOW )&&(E == LOW))
  {
    frente();    
    Serial.println(D); 
  }
  
   if ((D == LOW)&&(E == HIGH))
  {
    direita();
    Serial.println(D); 
  }
   if ((D == HIGH)&&(E == LOW))
  {
    esquerda();
    Serial.println("esquerda"); 

  }
  
  if ((D == HIGH)&&(E == HIGH))
  {
    parar();
    Serial.println("parar"); 
  }

  if (L == HIGH) 
  {
    contagemlateral = contagemlateral + 1;
     if (contagemlateral>=3)
      {
        contagemlateral = 0;
      }
     if (contagemlateral==2)
     {
      esquerda();
     }     
  }
  delay(100);
}
