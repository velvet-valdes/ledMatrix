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

// Include the custome LED matrix library
#include <LedMatrix.h>

// Initialize a matrix object and pass values for its banks
Matrix matrixMain(2,3,4,5,6,7,8,9);

// Here we are initializing global variables
int bankState;  
int timeHigh;
int timeMedium;
int timeLow;
int timeSlow;
int cycleCount;

void setup() {
// We've already initialized an object that has taken care of the setup for us so far

}

void loop() {  
// Here we are going to attempt to use a random function to select states
  
int bankState = random(0, 16);
  
// We are also going to use a random value to adjust the time values
  
timeHigh = random(10,50);
timeMedium = random(50,75);
timeLow = random(75,100);
timeSlow = random(100,150);

// Lets generate an even random number to pass into functions as the cycle count
  
cycleCount = random(1,4);
  
  
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
