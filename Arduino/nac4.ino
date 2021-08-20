const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 13;

void setup(){
  //-------------- Confitura pinos de saida -----//

  pinMode(ledPin1,OUTPUT);                             //  Configura o pino 13 do arduino como saida(OUTPUT)              
  pinMode(ledPin2,OUTPUT); 
  pinMode(ledPin3,OUTPUT); 

  //---------------Configura pinos de entrada ------//

  pinMode(2,INPUT_PULLUP);                        //  Configura o pino 2 do arduino como entrada com resistor de pullup interno (assim não precisa mais colocar o resistor no pino)              
  pinMode(3,INPUT_PULLUP);                        //  Configura o pino 3 do arduino como entrada com resistor de pullup interno (assim não precisa mais colocar o resistor no pino)
  

  //-----------  Configuração da Interrução ------------------- //                                 

  //attachInterrupt(digitalPinToInterrupt(2),interrupcaoPino2,RISING);  //  Configura o pino2 como interrupção externa do tipo Rising (borda de LOW para HIGH)
  
}

void loop(){  
  //------- Programa pricipal -----//

  if (digitalRead(2) == LOW ){
    digitalWrite(ledPin1,!digitalRead(ledPin1));
  }
  if (digitalRead(3) == LOW ){
    digitalWrite(ledPin2,!digitalRead(ledPin2));
  }
  digitalWrite(ledPin3,HIGH);
  delay(1000);
  digitalWrite(ledPin3,LOW);
  delay(1000);
   
}

//void interrupcaoPino2()           //funcão de interrupção do pino2, é executado quando o botao do pino2 pressionado
//{                    
//  digitalWrite(ledPin1,!digitalRead(ledPin1));
//}
