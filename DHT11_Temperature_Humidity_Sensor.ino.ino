#include <DHT.h>
#include <LiquidCrystal.h>

// DHT11 setup
#define DHTPIN 7
#define DHTTYPE DHT11

// Creates the DHT11 sensor
DHT dht(DHTPIN, DHTTYPE);

// LCD1602 setup
// Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // Starts communication with the Serial Monitor
  Serial.begin(9600);
  delay(500);

  Serial.println("DHT11 Humidity & Temperature Sensor");

  // Starts the DHT11 sensor
  dht.begin();

  // Starts the 16-column, 2-row LCD
  lcd.begin(16, 2);

  delay(1000);
}

void loop()
{
  // Reads the current humidity from the DHT11
  float humidity = dht.readHumidity();

  // Reads the current temperature in Celsius
  float temperature = dht.readTemperature();

  // Converts Celsius to Fahrenheit
  float fahrenheit = (temperature * 9.0 / 5.0) + 32;


  // ---------- SERIAL MONITOR ----------

  // Displays humidity
  Serial.print("Current Humidity = ");
  Serial.print(humidity);
  Serial.print("%  ");

  // Displays temperature in Celsius
  Serial.print("C: ");
  Serial.print(temperature);

  // Displays temperature in Fahrenheit
  Serial.print("  F: ");
  Serial.println(fahrenheit);


  // ---------- LCD1602 ----------

  // Moves the cursor to the top-left of the LCD
  lcd.setCursor(0, 0);

  // Displays humidity on the first row
  lcd.print("Humidity: ");
  lcd.print(humidity, 0);
  lcd.print("%");

  // Moves the cursor to the beginning of the second row
  lcd.setCursor(0, 1);

  // Displays temperature in Celsius
  lcd.print("C:");
  lcd.print(temperature, 1);

  // Displays temperature in Fahrenheit
  lcd.print(" F:");
  lcd.print(fahrenheit, 1);


  // Waits 5 seconds before taking another reading
  delay(5000);
}