
#include <DHT.h>
#include <LiquidCrystal.h>

// DHT11 setup
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// LCD1602 setup
// Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Data logging settings
const int MAX_READINGS = 100;
const unsigned long LOG_INTERVAL = 5000;

int readingCount = 0;

void setup()
{
  // Starts communication with the Serial Monitor
  Serial.begin(9600);
  delay(500);

  // Starts the DHT11 sensor
  dht.begin();

  // Starts the 16-column, 2-row LCD
  lcd.begin(16, 2);

  delay(1000);

  // CSV column headings
  Serial.println("Reading,Time_ms,Temperature_C,Temperature_F,Humidity");
}

void loop()
{
  // Reads humidity and temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Checks for failed sensor readings
  if (isnan(humidity) || isnan(temperature))
  {
    delay(LOG_INTERVAL);
    return;
  }

  // Converts Celsius to Fahrenheit
  float fahrenheit = (temperature * 9.0 / 5.0) + 32;

  // ---------- DATA LOGGING ----------

  // Saves up to 100 readings to the Serial output
  if (readingCount < MAX_READINGS)
  {
    readingCount++;

    Serial.print(readingCount);
    Serial.print(",");

    Serial.print(millis());
    Serial.print(",");

    Serial.print(temperature, 1);
    Serial.print(",");

    Serial.print(fahrenheit, 1);
    Serial.print(",");

    Serial.println(humidity, 1);
  }

  // ---------- LCD1602 ----------

  // Displays humidity on the first row
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(humidity, 0);
  lcd.print("%");

  // Displays Celsius and Fahrenheit on the second row
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);

  lcd.print("C:");
  lcd.print(temperature, 1);

  lcd.print(" F:");
  lcd.print(fahrenheit, 1);

  // Waits 5 seconds before the next reading
  delay(LOG_INTERVAL);
}
