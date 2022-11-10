int IN1 = 4;
int IN2 = 5;
int IN3 = 8;
int IN4 = 7;

int SensorD = 10;        // sensor de linha da direita
int SensorE = 11;       // sensor de linha da esquerda

int E = 2;
int D = 3; //REVISAR PABLO
int ledplaca = 13;

int contador = 3;
bool dobrou = false;

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
 pinMode(SensorL, INPUT);

//inicia parado
 parar();
}

void frente()
{
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW); 
}

void esquerda()
{
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}

void direita()
{
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}

void parar()
{
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
}

// so a preparacao
void loop()
{
  D = digitalRead(SensorD);   // lê o pino de entrada
  E = digitalRead(SensorE);

  if ((D == LOW )&&(E == LOW))
  {
    frente();    
    Serial.println(" indo p frente"); 
  }

 else if ((D == LOW)&&(E == HIGH))
  {
    esquerda();
    Serial.println("indo p direita"); 
  }
 else if ((D == HIGH)&&(E == LOW))
  {
    direita();
    Serial.println("indo p esquerda"); 
  }
  else if ((D == HIGH)&&(E == HIGH))
  {
    Serial.println("cruzamento");
    frente();
    delay(300); // delay para cruzar a linha
    if (--contador == 0) // se chegou num ponto de dobrar/terminar
    {  
      Serial.println(contador);
      if (!dobrou)
      {
        Serial.println("dobrando p esquerda");
        esquerda();
        delay(800); // delay para fazer a curva
        dobrou = true;
        contador = 1; // numero de linhas pra cruzar depois de fazer a curva
        frente();
      }
      else
      {
        Serial.println("chegou nou fim");
        frente();
        delay(300); // tempo para ir até o final
        parar();
        while(1) // fica parado para sempre
        {
          
        }
      }
    }    
  }
  
}
