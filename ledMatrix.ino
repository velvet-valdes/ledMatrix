#include <dht.h>          // We are using the DHT library found at http://playground.arduino.cc/Main/DHTLib
#include <LedMatrix.h>    // Custom animation library found at https://github.com/velvet-valdes/ledMatrix_lib.git

/*
 * Here we are taking the original LED matrix project and adding a temp / humidity sensor along with a digital light sensor
 */

dht DHT;  // I'm not sure what this line does but it does something like call or instantiate an object

// Initialize a matrix object and pass values for its banks
Matrix matrixMain(2,3,4,5,6,7,8,9);

// Initialize global variables - note we added the buttons.
int bankState = 16;	      // initializing a value here to start the counter without resetting it throughout the loop 
int timeHigh;
int timeMedium;
int timeLow;
int timeSlow;
int timeFloat;            // we're going to use this to store the value the digital light meter is reading 
int cycleCount;
int button01;             // our left button read pin on the arduino
int button02;             // our right button read pin on the arduino
int buttonState01;  
int buttonState02; 
int lightMeterIn = A0;    // this is our analog light intensity read pin (INPUT)
int lightMeterState = 13; // this is our digital light state read pin which determines if the light is ON or OFF (INPUT)
int valLightMeter;        // we are storing the value returned from the light meter here
int valLightState;        // we are storing the value of the light state here.  0=LOW=ON 1=HIGH=OFF
int valTemp;              // this is our temp reading in celsius
int valHumidity;          // this is our relative humidity value in percentage

// Set the pin we are going to read the data on for the temprature humidity sensor
#define DHT11_PIN 12

void setup() {
  
  // Lets initialize serial.  Why not?
	Serial.begin(9600);

	// Set the read pins for the buttons
	button01 = 10;
	button02 = 11;

	// Set pinModes
  // Increment and decrement buttons:
	pinMode(button01, INPUT);
	pinMode(button02, INPUT);

  // Set the pins we are going to read data from the light intensity meter
  pinMode(lightMeterIn, INPUT);
  pinMode(lightMeterState, INPUT);

}

void loop() {

  // Begin the temprature and humidty sensor check  
  int chk = DHT.read11(DHT11_PIN);

  valTemp = ((DHT.temperature)*(1.8)+(32));
  valHumidity = DHT.humidity;
  Serial.println(" ");
  Serial.print("Temperature = ");
  Serial.println(valTemp);
  Serial.print("Humidity = ");
  Serial.println(valHumidity);

  // Begin the light meter sensor check
  valLightMeter = analogRead(lightMeterIn);
  valLightState = digitalRead(lightMeterState);

  // Lower values indicate a brighter light source, higher values indicate dimmer light source
  Serial.print("Light Meter Value = ");
  Serial.println(valLightMeter);

  // If the state of the light sensor is LOW (read as 0) it detects light.  If the sensor state is HIGH (read as 1) there is no light detected.
  Serial.print("Light Sensor State = ");
  Serial.println(valLightState);
  

  // Print the bankState variable
  Serial.print("Bank State = ");
  Serial.println(bankState);
  Serial.println(" ");

	// read the state of the pushbuttons
	int buttonState01 = digitalRead(button01);
	int buttonState02 = digitalRead(button02);

	// check if the pushbutton is pressed.if it is, the buttonState is HIGH: When either button is pressed it will change the state of the counter variable.
  
	if (buttonState01 == HIGH) {
		// increment button state
		bankState++;
		} 
			
	else {
		// print value
	}

	if (buttonState02 == HIGH) {
		// decrement button state
		bankState--;
		} 
		
	else {
		// print value
	}

	// We are moving to a fixed time value now that we have buttons
 
	timeHigh = (50);
	timeMedium = (100);
	timeLow = (250);
	timeSlow = (500);
  timeFloat = valLightMeter;

	// Changing the cycle count to a single count now that we have a button selecting states 
	cycleCount = 1;  
  
switch (bankState) {

  case 0:
    // statements
    matrixMain.downHorizontal(cycleCount, timeFloat);
    break;
  case 1:
    // statements
    matrixMain.upHorizontal(cycleCount, timeFloat);
    break;
  case 2:
    // statements
    matrixMain.downLeft(cycleCount, timeFloat);
    break;
  case 3:
    // statements
    matrixMain.upRight(cycleCount, timeFloat);
    break;
  case 4:
    // statements
    matrixMain.upLeft(cycleCount, timeFloat);
    break;
  case 5:
    // statements
    matrixMain.downRight(cycleCount, timeFloat);
    break;
  case 6:
    // statements
    matrixMain.snakeDown(cycleCount, timeFloat);
    break;
  case 7:
    // statements
    matrixMain.snakeUp(cycleCount, timeFloat);
    break;
    case 8:
    // statements
    matrixMain.blinkRed(cycleCount, timeFloat);
    break;
    case 9:
    // statements
    matrixMain.blinkWhite(cycleCount, timeFloat);
    break;
    case 10:
    // statements
    matrixMain.rowDown(cycleCount, timeFloat);
    break;
    case 11:
    // statements
    matrixMain.rowUp(cycleCount, timeFloat);
    break;
    case 12:
    // statements
    matrixMain.blinkSingleWhiteDown(cycleCount, timeFloat);   
    break; 
    case 13:
    // statements
    matrixMain.blinkSingleRedDown(cycleCount, timeFloat);    
    break;
    case 14:
    // statements
    matrixMain.blinkSingleWhiteUp(cycleCount, timeFloat);
    break;
    case 15:
    // statements
    matrixMain.blinkSingleRedUp(cycleCount, timeFloat);
    break;
    case 16:
    // statements
    matrixMain.randomThree(cycleCount, timeFloat);
    break;
    
	}    
}
