/*
https://www.youtube.com/watch?v=82zbSgUhJdE&gt;. Acesso em: 14 jun. 2018.
*/
int portaldr1 = A0;
int portaldr2 = A1;
int motor1 = 11;
int motor2 = 10;
int led1 = 6;
int led2 = 7;
void setup() 
{
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, 1); //led ligado
  digitalWrite(led2, 1); 
}
void loop() 
{
  int leitura_ldr1;
  int leitura_ldr2;
  leitura_ldr1=analogRead(portaldr1);
  leitura_ldr2=analogRead(portaldr2); 
  Serial.println(leitura_ldr1);
  
  if (leitura_ldr1 > 900 && leitura_ldr2 > 900)// ldr 0- 1023, maior for luz
    //menor vai ser o valor
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,HIGH);
  }
  if (leitura_ldr1 > 900 && leitura_ldr2 < 900) //ldr1 escuro e ldr2 claro
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW); 
  }
  if (leitura_ldr1 < 900 && leitura_ldr2 > 900)
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,HIGH);         
  }
  if (leitura_ldr1 < 900 && leitura_ldr2 < 900)
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
  }
}



