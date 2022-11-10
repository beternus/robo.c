int IN1 = 4;
int IN2 = 5;
int IN3 = 8;
int IN4 = 7;

int SensorD = 10;        // sensor de linha da direita
int SensorE = 11;       // sensor de linha da esquerda
int SensorL = 6;  //define sensor lateral
//int SensorF = 13;  //sensor da frente

int E = 2;
int D = 3; //REVISAR PABLO
int ledplaca = 13;
int L = 1;

//int contagemlateral;
int contador = 0;
int contadorL = 0;

void setup(){
  Serial.begin(9600);
  
  //Define os pinos como saida e entrada
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(D, INPUT);
 pinMode(E, INPUT);
 pinMode(L, INPUT);
 
 pinMode(SensorD, INPUT);
 pinMode(SensorE, INPUT);
 pinMode(SensorL, INPUT);

//inicia parado
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
}

void frente()
{
// Serial.println( digitalRead(SensorF));
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW); 
}

void esquerda()
{
//Serial.println( digitalRead(SensorF));
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}

void direita()
{
// Serial.println( digitalRead(SensorF));
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}

// so a preparacao
void loop()
{
  delay(500);
  D = digitalRead(SensorD);   // lê o pino de entrada
  E = digitalRead(SensorE);
  L = digitalRead(SensorL);

  if ((D == LOW )&&(E == LOW))
  {
    frente();    
    Serial.println(" indo p frente"); 
  }

 if ((D == LOW)&&(E == HIGH))
  {
    direita();
    Serial.println("indo p direita"); 
  }
 if ((D == HIGH)&&(E == LOW))
  {
    esquerda();
    Serial.println("indo p esquerda"); 
  }
  else if ((D == HIGH)&&(E == HIGH))
  {
    contador++;
    frente();
    Serial.println(" indo p frente"); 
  }
  Serial.println(contador);
  if(L == HIGH)
  {
    contadorL++;
    frente();
  }
//ABAIXO MUDEI DE L PARA contador...
  if (contador == 3)
  {  
    //NESSA PARTE AQUI O COLEGA ME AJUDOU A FAZER - CONSISTE EM UMA CONTAGEM DOS QUADRANTES PARA PODER GIRAR PARA A ESQUERDA
    while(contadorL <= 4)
    {
      esquerda();
      delay(50);
      digitalWrite(13, HIGH);
      contador = 4;
    }
  }    
}
