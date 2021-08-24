//Incluindo biblioteca Json
#include <ArduinoJson.h>

//Definindo as variáveis 
//O tamanho de cada objeto do documento Json aceita 3 objetos
const int TAMANHO = JSON_OBJECT_SIZE(3);
//Objeto Json tem o tamanho que setamos na linha acima
StaticJsonDocument<TAMANHO> json;

//Definindo as variáveis 
int Vo;
float R1 = 10000;
float logR2, R2, L2, T, Tc, Tf, temp, light, wind;
float a = 0.6904626097e-03, b = 2.890757430e-04, c = 0.01366717388e-07; 

//Portas do arduino
int ldr = A0;
int tmp = A1;
int vnt = 2;

//Configurando o setup
void setup(){
	//Medida alta para a tranmissão de dados
	Serial.begin(115200);
	pinMode(ldr, INPUT);
	pinMode(tmp, INPUT);
	pinMode(vnt, INPUT);
}


void loop() {
	//Funções que leem os dados que vem dos pinos 
	light = readLight(ldr);
	temp = readTemp(tmp);
	wind = readWind(vnt);
	//Setando as varáveis recebidas através dos sensores e definindo-as 
	//no documento Json em formato chave e valor 
	json["temp"] = round(temp);
	json["light"] = round(light);
	json["vento"] = round(wind);	
	//Constroi o Json e manda para o serial 
	serializeJson(json, Serial);
	delay(3000);
}

//Função que le temperatura
float readTemp(int tmp){
	Vo = analogRead(tmp);
	R2 = R1 * (1023.0 / (float)Vo - 1.0);
	logR2 = log(R2);
	T = (1.0 / (a + b*logR2 + c*logR2*logR2*logR2));
	Tc = T - 273.15; 
	return Tc;
}

//Printar na serial a temperatura
void printTempSerial(float Tc){
	Serial.print("Temp.: ");
	Serial.print(round(Tc));
	Serial.println(" C");
}

//Função que le a luminosidade
float readLight(int ldr) {
	int adc = analogRead(ldr);
	float rDark = 100000;
	float light, RLDR, Vout;
	float alfa = 1/0.8582;
	
	Vout = (adc * 0.0048898525);
	RLDR = (10000.0 * (5 - Vout))/Vout; 
	light = pow((rDark/RLDR), alfa);
	return light;
}

//Função que le a velocidade do vento
float readWind(int vtn) {
	unsigned long frequency;
	int pulseHigh = pulseIn(vtn, HIGH);
	int pulseLow = pulseIn(vtn, LOW);
	float pulseTotal = pulseHigh + pulseLow;
	frequency = 1000000/pulseTotal;
	return frequency;
}

//Printar na serial a velocidade do vento
void printWindSerial(float wind){
	Serial.print("Freq.: ");
	Serial.print(round(wind));
	Serial.println(" Hz");
}

//Printar na serial a luminosidade
void printLightSerial(float light){
	Serial.print("Lumin.: ");
	Serial.print(light);
	Serial.println(" lux");
}








