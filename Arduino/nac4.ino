#include <ArduinoJson.h>
const int TAMANHO = JSON_OBJECT_SIZE(3);
StaticJsonDocument<TAMANHO> json;

int Vo;
float R1 = 10000;
float logR2, R2, L2, T, Tc, Tf, temp, light, wind;
float a = 0.6904626097e-03, b = 2.890757430e-04, c = 0.01366717388e-07; 



int ldr = A0;
int tmp = A1;
int vnt = 2;

void setup(){
	Serial.begin(115200);
	pinMode(ldr, INPUT);
	pinMode(tmp, INPUT);
	pinMode(vnt, INPUT);
}

void loop() {
	light = readLight(ldr);
	temp = readTemp(tmp);
	wind = readWind(vnt);
	json["temp"] = round(temp);
	json["light"] = round(light);
	json["vento"] = round(wind);	
	serializeJson(json, Serial);

	delay(300);
}

float readTemp(int tmp){
	Vo = analogRead(tmp);
	R2 = R1 * (1023.0 / (float)Vo - 1.0);
	logR2 = log(R2);
	T = (1.0 / (a + b*logR2 + c*logR2*logR2*logR2));
	Tc = T - 273.15; 
	return Tc;
}


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

float readWind(int vnt) {
	unsigned long tempo;
	int pulseHigh = pulseIn(vnt, HIGH);
	int pulseLow = pulseIn(vnt, LOW);
	float pulseTotal = pulseHigh + pulseLow;
	tempo = 1000000;
	wind = tempo/pulseTotal;       
	return wind;
}

void printWindSerial(float wind){
	Serial.print("Freq.: ");
	Serial.print(round(wind));
	Serial.println(" Hz");
}

void printLightSerial(float light){
	Serial.print("Lumin.: ");
	Serial.print(light);
	Serial.println(" lux");
}
void printTempSerial(float Tc){
	Serial.print("Temp.: ");
	Serial.print(round(Tc));
	Serial.println(" C");
}














