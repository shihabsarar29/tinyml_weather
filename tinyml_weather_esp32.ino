#include <EloquentTinyML.h>
#include <eloquent_tinyml/tensorflow.h>
#include "DHT.h"
#include "weather_model.h"


#define NUMBER_OF_INPUTS 2
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE 2*1024

#define DHTPIN 4
#define DHTTYPE DHT22


DHT dht(DHTPIN, DHTTYPE);
Eloquent::TinyML::TensorFlow::TensorFlow<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;


void setup() {
    Serial.begin(115200);
    ml.begin(weather_model);
    dht.begin();
}


void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();


  float input[2] = {temperature, humidity};
  float predicted = ml.predict(input);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" K\tHumidity: ");
  Serial.print(humidity);
  Serial.print(" %\tPressure: ");
  Serial.println(predicted);

  delay(1000);
}
