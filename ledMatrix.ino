/*

  LED matrix breadboard project
  
  Library functions available (so far):
   
    void turnOn();
    void turnOff();
    void turnOnAll();
    void turnOffAll();
    void downHorizontal(int count, int time);
    void upHorizontal(int count, int time);
    void downLeft(int count, int time);
    void upRight(int count, int time);
    void upLeft(int count, int time);
    void downRight(int count, int time);
    void snakeDown(int count, int time);
    void snakeUp(int count, int time);
    void randomOne(int count, int time);
    void randomTwo(int count, int time);
    void randomThree(int count, int time);
    void blinkRed(int count, int time);
    void blinkWhite(int count, int time);
    void rowDown(int count, int time);
    void rowUp(int count, int time);
    void blinkSingleWhiteDown(int count, int time);
    void blinkSingleRedDown(int count, int time);
    void blinkSingleWhiteUp(int count, int time);
    void blinkSingleRedUp(int count, int time);
    void turnOnAllButOne(int count, int time);
    void turnOnAllButTwo(int count, int time);
        
*/

// Include the custom LED matrix library
#include <LedMatrix.h>

// Initialize a matrix object and pass values for its banks
Matrix matrixMain(2,3,4,5,6,7,8,9);

// Initialize global variables - note we added the buttons.
int bankState = 16;	// initializing a value here to start the counter without resetting it throughout the loop 
int timeHigh;
int timeMedium;
int timeLow;
int timeSlow;
int cycleCount;
int button01;   // our left button read pin on the arduino
int button02;   // our right button read pin on the arduino
int buttonState01;  
int buttonState02;  

void setup() {
  
  // Lets initialize serial.  Why not?
	Serial.begin(9600);

	// Set the read pins for the buttons
	button01 = 12;
	button02 = 13;

	// Set pinModes
	pinMode(button01, INPUT);
	pinMode(button02, INPUT);

}

void loop() {

	// read the state of the pushbuttons
	int buttonState01 = digitalRead(button01);
	int buttonState02 = digitalRead(button02);


	// check if the pushbutton is pressed.if it is, the buttonState is HIGH: When either button is pressed it will change the state of the counter variable.
  
	if (buttonState01 == HIGH) {
		// increment button state
		bankState++;
		Serial.println(bankState);
		} 
			
	else {
		// print value
		Serial.println(bankState);
	}

	if (buttonState02 == HIGH) {
		// decrement button state
		bankState--;
		Serial.println(bankState);
		} 
		
	else {
		// print value
		Serial.println(bankState);
	}

	// We are moving to a fixed time value now that we have buttons
 
	timeHigh = (50);
	timeMedium = (100);
	timeLow = (250);
	timeSlow = (500);

	// Changing the cycle count to a single count now that we have a button selecting states 
	cycleCount = 1;  
  
switch (bankState) {

  case 0:
    // statements
    matrixMain.downHorizontal(cycleCount, timeMedium);
    break;
  case 1:
    // statements
    matrixMain.upHorizontal(cycleCount, timeMedium);
    break;
  case 2:
    // statements
    matrixMain.downLeft(cycleCount, timeHigh);
    break;
  case 3:
    // statements
    matrixMain.upRight(cycleCount, timeHigh);
    break;
  case 4:
    // statements
    matrixMain.upLeft(cycleCount, timeHigh);
    break;
  case 5:
    // statements
    matrixMain.downRight(cycleCount, timeHigh);
    break;
  case 6:
    // statements
    matrixMain.snakeDown(cycleCount, timeLow);
    break;
  case 7:
    // statements
    matrixMain.snakeUp(cycleCount, timeLow);
    break;
    case 8:
    // statements
    matrixMain.blinkRed(cycleCount, timeMedium);
    break;
    case 9:
    // statements
    matrixMain.blinkWhite(cycleCount, timeMedium);
    break;
    case 10:
    // statements
    matrixMain.rowDown(cycleCount, timeMedium);
    break;
    case 11:
    // statements
    matrixMain.rowUp(cycleCount, timeMedium);
    break;
    case 12:
    // statements
    matrixMain.blinkSingleWhiteDown(cycleCount, timeMedium);   
    break; 
    case 13:
    // statements
    matrixMain.blinkSingleRedDown(cycleCount, timeMedium);    
    break;
    case 14:
    // statements
    matrixMain.blinkSingleWhiteUp(cycleCount, timeMedium);
    break;
    case 15:
    // statements
    matrixMain.blinkSingleRedUp(cycleCount, timeMedium);
    break;
    case 16:
    // statements
    matrixMain.randomThree(cycleCount, timeLow);
    break;
    
	}    
}
