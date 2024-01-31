#include "DHT.h"
#define RELAY 2
#define DHT11PIN 3 //датчик температуры и влажности
#define FC37 A0 //FC37
#define LIGHTSENSOR A1
#define WATERSENSOR A2
#define DAY 1 //промежуток между поливами в днях, при необходимости изменить
#define OPTIM 800 //верхняя граница оптимальной влажности
//#define OPTIMUMWATER 800 //верхняя граница оптимальной воды

long last_irrigation = -1; //последнее значение срабатывания мотора в миллисекунах, -1 - значит ещё не было полива
long time_to_future_irrigation = -1; //время до ближайшего полива
float DHT11_humidity = 0;
float DHT11_temperature = 0;
bool DHT11_error = false;
char mode = 0; //режим работы устройства, считывается с выбранной кнопки в GUI

DHT dht(DHT11PIN, DHT11);

int sensorsoilValue = 0;
int sensorlightValue = 0;
//int sensorwaterValue = 0;

void mode_1_tekpar() {
	sensorsoilValue = analogRead(FC37);
	sensorlightValue = analogRead(LIGHTSENSOR);
	DHT11_humidity = dht.readHumidity();
	DHT11_temperature = dht.readTemperature();

	if( isnanf(DHT11_humidity)  || isnanf(DHT11_temperature) ||
		isnanf(sensorsoilValue) || isnanf(sensorlightValue)) {
		Serial.println("Ошибка считывания датчиков");
		return;
	}
}

void setup() {
  DDRD |= (1<<RELAY);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
	mode = Serial.read();	//считываем, какая кнопка нажата в GUI
	switch (mode) {
		case ('1'):
			mode_1_tekpar();
			int a = (millis()-last_irrigation);
			//Serial.print("Время с последнего полива : ");
			Serial.print(a);
			Serial.print(" ");
			
			//Serial.print("Время до ближайшего полива : ");
			Serial.print(time_to_future_irrigation);
			Serial.print(" ");

			//Serial.print("Влажность : ");
			Serial.print(DHT11_humidity);
			Serial.print(" ");

			//Serial.print("Температура : ");
			Serial.print(DHT11_temperature);
			Serial.print(" ");
			//Serial.println(" *C, ");

			//Serial.print("Влажность почвы : ");
			Serial.print(sensorsoilValue);
			Serial.print(" ");

			//Serial.print("Освещённость : ");
			Serial.print(sensorlightValue);
			Serial.print(" ");
			break;
		case ('2'):
			//полив, проверка помпы
			PORTD |= (1<<RELAY);
			delay(3000);
			PORTD &= ~(1<<RELAY);
			last_irrigation = millis();
			delay(2000);				
			break;
		default:
			break;
    }
	
	unsigned long now = millis(); //прошедшее время с момента запуска ардуино
	unsigned long delta = DAY*24*60*60*1000; //минимальное количество времени между поливами
	mode_1_tekpar();
	
	//Если пришло время или почва сухая
	if( (now-last_irrigation > delta) || (sensorsoilValue > OPTIM) ) {
		//полив
		PORTD |= (1<<RELAY);
		delay(3000);
		PORTD &= ~(1<<RELAY);
		last_irrigation = millis();
		delay(2000);
		time_to_future_irrigation = DAY*24; //примерное время до будущего полива
	}
}
