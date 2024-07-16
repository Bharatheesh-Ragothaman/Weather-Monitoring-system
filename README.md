WEATHER MONITORING SYSTEM
OVERVIEW:
	The Smart Weather Monitoring is a system of sensors that detect environmental changes.
	The main use case of this system is, it is a miniature of a real weather monitoring system, which is used by the Meteorological department. 
	It addresses the problem of knowing weather data in real time.
IDEOLOGY:
	My idea to build this system is to have a pocket friendly, real time weather monitoring system, which does not require any big external components to work upon.
	The primary aim of this project is to provide the user with:

♦	Real time data monitoring
♦	Use it anywhere pocket-friendly.
COMPONENTS:
To perform the above-mentioned project, certain hardware components are required. They are:
1.ARDUINO UNO BOARD:
	Arduino UNO is a microcontroller which is used as a processing unit in a system.
	It serves as a CPU, which collects data from various sources, processes it and produces the output accordingly. 	
	I have used this board for sensor IO connections and display screen for output display.
 
2. JUMPER WIRES:
	These are connecting wires that are used to connect various hardware components to the Arduino UNO board and the display component.
	3 types of jumper wires are used in this project for hardware connections:
♦	Male to Male
♦	Male to Female
♦	Female to Female
 

3. BREADBOARD:
	This component is used as an interface to connect various electronic components through it.
	It provides with Common GND and Common Power Supply, which is really useful on organizing the power and ground connections of various electronic components of the system.
 
4. DHT 11 SENSOR:
	This sensor is a Temperature and Humidity sensor.
	It detects both temperature as well as humidity in the surroundings.
	It needs a maximum voltage of 3.3 - 5V for smooth and proper functioning.
	There are 3 pins in this sensor, via which we communicate the sensed data to the Arduino. They are:
♦	Vcc - Power supply
♦	GND - Ground
♦	DATA - For communication of sensed data 
 
5. RAIN SENSOR:
	This sensor detects the presence of rain in the surroundings.
	It consists of 
♦	sensing pad 
♦	sensing module
	The sensing pad is a flat, nickel-coated copper tracks, which is waterproof in nature. This pad is used for gaining water droplets from the environment, based upon which further actuation can be carried.
	The sensing module will pass on the sensed data i.e, whether the water droplets are present on the sensing pad or not, to the Arduino UNO board.
	It also consists of 3 pins:
♦	Vcc
♦	GND
♦	D0
 

6. BMP180 SENSOR:
	It is Barometric Pressure sensor.
	It detects the atmospheric pressure in the surroundings.
	It consists of 4 pins:
♦	Vcc
♦	GND
♦	SDA - Serial Data Line
♦	SCL - Serial Clock Line
 
7. ARDUINO IDE:
	It is an application software, which can be installed in Windows/Apple OS.
	It acts as a bridge between the software code part and Arduino hardware connection.
	The Arduino Hardware part works only if the proper coding part is added to it. Thus, the code part is also referred to as the “SOUL OF THE IoT SYSTEM”.
 
WORKING OF WEATHER MONITORING SYSTEM:
1.	As I have mentioned the components used to build this system earlier, now we will see how to achieve the desired output from the hardware components.
2.	Firstly, we will assemble all the required components.
3.	Take 2 Male to Male Jumper Wires, connect the Power Pin and Ground pin of Arduino to the common Power supply and common Ground connection of the Breadboard respectively.
4.	Now, Take the DHT 11 Sensor and 3 Male to Female Jumper Wires. Connect Vcc pin to the common power supply and GND pin to the common ground of the breadboard respectively. 
5.	Connect the Data pin of the sensor to the Digital pin 3 of the Arduino UNO board.
6.	Now, take the rain sensor and repeat step 4.
7.	Connect the data pin of the rain sensor to the Analog pin A0 of the Arduino UNO board.
8.	Similarly, take the BMP 180 sensor and repeat 4.
9.	Connect SDA pin of the BMP 180 sensor to the Analog pin A4 and SCL pin to the Analog pin A5 of the Arduino UNO board.
10.	All the sensor, power and ground connections are done. Check for any improper connections to and from the Arduino Board.
11.	Now, connect the USB cable to the PC for power connection and software code.
12.	As mentioned, we use the Arduino IDE for coding connection. In the software, select the board as Arduino and create a new file and start coding.
13.	Before starting, install the required libraries from the Arduino IDE shop, via which only we can be able to sense and manipulate the data. The libraries we used in this project are:
♦	Wire.h
♦	Adafruit_Sensor.h
♦	Adafruit_BMP085.h
♦	DHT.h
14.	
•	Wire.h library allows you to communicate with I2C/TWI devices. 
•	Adafruit_Sensor.h library provides a simple device independent interface for interacting with Adafruit IO using Arduino.
•	Adafruit_BMP085.h library provides an interface for the BMP085 and BMP180 barometric pressure sensors from Adafruit.
15.	The below code is typed and compiled. Check for any coding errors and correct if any.
16.	Now, upload the code to the Arduino UNO board and open Serial Monitor in the Arduino IDE to view the output.
17.	Observe the changes in the data for every time cycle from the Weather monitoring system.
![image](https://github.com/user-attachments/assets/31ab2066-f903-489f-beb3-91310fe074ba)



PROGRAM EXPLANATION:
1.	INCLUDE LIBRARIES:

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>

	These lines include the necessary libraries for I2C communication, sensor operations, BMP180 sensor and the DHT11 sensor.

2.	DEFINE PINS:

#define DHTPIN 3
#define DHTTYPE DHT11
#define rainSensorPin A0

	Here, we define the digital pin for the DHT11 sensor(DHT pin), the type of DHT sensor being used(DHTTYPE), and the analog pin for the rain sensor(rainSensorPin).

3.	 SETUP FUNCTION:

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
}

	The ‘setup’ function initializes serial communication at a baud rate of 9600 bits per second, starts the DHT sensor, and checks if the BMP180 sensor is detected.
	If the BMP180 sensor is not found, it prints an error message and enters an infinite loop.
4.	LOOP FUNCTION:

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float p = bmp.readPressure() / 100.0F;
  int rainSensorValue = analogRead(rainSensorPin);

  if (isnan(h) || isnan(t) || isnan(p)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Pressure: ");
  Serial.print(p);
  Serial.print(" hPa\t");
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainSensorValue);

  delay(2000);
}

	The loop function reads the temperature, pressure and humidity values from their respective sensors. It also reads the analog value from the rain sensor.
	If any of the sensor readings are not valid, it prints an error message. Otherwise, it prints all the sensor values, including the rain sensor value, to the serial monitor.
	The delay(2000) function pauses the program for 2 seconds before repeating the loop.
	By integrating the rain sensor, this code allows you to monitor the level of rainfall alongside temperature, humidity and pressure readings.

OUTPUT:
 
	The readings are measured with an interval gap of 3 seconds. These readings from the sensors are automatically looped endlessly, and a few readings from the Serial Monitor of the Arduino IDE are shown above.
	For rain sensor, whenever the sensor detects rain in its surroundings, then the reading value decreases. This is because the sensor value is inversely proportional to the presence of rain. And the same trend can be seen in the above output.Whenever lower values appear(here in this case, 23) , it means that it is raining.
	For other sensors – such as Temperature, Humidity, Pressure - those will detect the changes in the environment and update it accordingly.

ADVANTAGES:
	It is portable. We can carry it anywhere with a small box.
	It provides real time data with updating interval less than 3 seconds.
	Cost effective to build.
	Easy cable connections and cable management.

DISADVANTAGES:
	Lot of wire connections might be a hassle.
	Constant Power support and programming is needed from a PC, which cannot be carried everywhere.


FUTURE CONSIDERATION:
	Whatever I have built is a basic weather monitoring system, which does not have any specific customizations as of now.
	But we can add few tunings to the system to make it even more useable and practical such as:
♦	WIFI module can be added to the system, so that the collected data can be stored in a server over Internet and the best part about this is, we can plot the collected data and analyze it using graphs, with which we can predict the future weather changes.
♦	Bluetooth module can be added to the system, so that the collected data can be viewed via a smartphone, which is way more portable than the existing model/system. 

CONCLUSION:
In summary, the weather monitoring system plays an important role in monitoring the surroundings of the environment, but a bit portable and practical. We have seen on how to build this system and what all are the required hardware and software components. The corresponding output is also shown with varying data over time based upon the surrounding conditions. It has its own pros and cons that are discussed above, which can be considered to improve in the future. This project is aimed to provide a better portable device, to enhance the user hassle-free experience. This project is not the end. It has its own ways to develop into something better over the time and efforts. 
REFERENCES:
	https://mytrained.com/2023/06/18/weather-monitoring-system-project-using-arduino/

	https://electronics-project-hub.com/iot-based-weather-monitoring-system-using-arduino/

![image](https://github.com/user-attachments/assets/a65ca86e-e2ca-4b31-b38d-f060a70cb13b)
