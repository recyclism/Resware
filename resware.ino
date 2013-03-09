/*
Reading a NES Controller

Original code by:
Sebastian Tomczak
21 July 2007
Adelaide, Australia

Modified by:
Joshua de Haan
21 June 2009
Landgraaf, The Netherlands

Modified by:
Benjamin Gaulon
December 2010
Dublin, Ireland
*/

/* INITIALISATION */

// Controller 1
int latch = 2; // set the latch pin
int clock = 3; // set the clock pin
int datin = 4;// set the data in pin
char controller_data[8];

// Controller 2
int latch2 = 5; // set the latch pin
int clock2 = 6; // set the clock pin
int datin2 = 7;// set the data in pin
char controller_data2[8];

// Controller 3
int latch3 = 8; // set the latch pin
int clock3 = 9; // set the clock pin
int datin3 = 10;// set the data in pin
char controller_data3[8];

/* SETUP */
void setup()
{
  Serial.begin(9600);
  
  // controller 1
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(datin,INPUT);
  
  // controller 2
  pinMode(latch2,OUTPUT);
  pinMode(clock2,OUTPUT);
  pinMode(datin2,INPUT);
    
  // controller 3
  pinMode(latch3,OUTPUT);
  pinMode(clock3,OUTPUT);
  pinMode(datin3,INPUT);
}

/* CONTROLLER 1 READ */
void controllerRead()
{
  digitalWrite(latch,LOW);
  digitalWrite(clock,LOW);
  digitalWrite(latch,HIGH);
  delayMicroseconds(200);
  digitalWrite(latch,LOW);
  if (digitalRead(datin) == 1)
  {
    controller_data[0] = '1';
  }
  else
  {
    controller_data[0] = '0';
  }
  delayMicroseconds(200);
  for (int i = 1; i <= 7; i ++)
  {
    digitalWrite(clock,HIGH);
    delayMicroseconds(200);
    if (digitalRead(datin) == 1)
    {
      controller_data[i] = '1';
    }
    else
    {
      controller_data[i] = '0';
    }
    digitalWrite(clock,LOW);
    delayMicroseconds(200);
  }

}


/* CONTROLLER 2 READ */
void controllerRead2()
{
  digitalWrite(latch2,LOW);
  digitalWrite(clock2,LOW);
  digitalWrite(latch2,HIGH);
  delayMicroseconds(200);
  digitalWrite(latch2,LOW);
  if (digitalRead(datin2) == 1)
  {
    controller_data2[0] = '1';
  }
  else
  {
    controller_data2[0] = '0';
  }
  delayMicroseconds(200);
  
  for (int i = 1; i <= 7; i ++)
  {
    digitalWrite(clock2,HIGH);
    delayMicroseconds(200);
    if (digitalRead(datin2) == 1)
    {
      controller_data2[i] = '1';
    }
    else
    {
      controller_data2[i] = '0';
    }
    digitalWrite(clock2,LOW);
    delayMicroseconds(200);
  }

}


/* CONTROLLER 3 READ */
void controllerRead3()
{
  digitalWrite(latch3,LOW);
  digitalWrite(clock3,LOW);
  digitalWrite(latch3,HIGH);
  delayMicroseconds(200);
  digitalWrite(latch3,LOW);
  
  if (digitalRead(datin3) == 1)
  {
    controller_data3[0] = '1';
  }
  else
  {
    controller_data3[0] = '0';
  }
  delayMicroseconds(200);
  for (int i = 1; i <= 7; i ++)
  {
    digitalWrite(clock3,HIGH);
    delayMicroseconds(200);
    if (digitalRead(datin3) == 1)
    {
      controller_data3[i] = '1';
    }
    else
    {
      controller_data3[i] = '0';
    }
    digitalWrite(clock3,LOW);
    delayMicroseconds(200);
  }

}



/* PROGRAM */
void loop()
{
  controllerRead();
  for (int i = 0; i <= 7; i++){
   Serial.print(controller_data[i]);
   delayMicroseconds(200);
   }
  
  Serial.print(" ");
  delayMicroseconds(200);
     
  controllerRead2();
  for (int i = 0; i <= 7; i++){
   Serial.print(controller_data2[i]);
   delayMicroseconds(200);
   }
   
     
  Serial.print(" ");
  delayMicroseconds(200);
     
  controllerRead3();
  for (int i = 0; i <= 7; i++){
   Serial.print(controller_data3[i]);
   delayMicroseconds(200);
   }
   
   Serial.println();
  delayMicroseconds(200);
} 
