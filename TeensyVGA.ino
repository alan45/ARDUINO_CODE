//Simple Demo that demonstrates 'print' and 'println' new functionality.

#include "/home/alan/Documents/ARDUINO_CODE/TeensyVGA/Definitions.ino"

const int RESET =  4;
const int GRAPH_MIN_X = 60;
const int GRAPH_MIN_Y = 100;
const int GRAPH_MAX_X = 620;
const int GRAPH_MAX_Y = 420;



void setup()
{


  Serial1.begin(9600);
  // ************************  Reset the uVGA-III module ************

  pinMode(RESET, OUTPUT);    // Set D4 on Arduino to Output
  digitalWrite(RESET, LOW);  // Reset the Display via D4
  delay(100);
  digitalWrite(RESET, HIGH); // unReset the Display via D4
  delay(5000);

  // ************************ Reset Baud rate ************************
  vga(SET_BAUD_RATE, 19); // Nominal 600,000 baud rate actually 703125
  delay(1000);
  Serial1.begin(703125);

  vga(SCREEN_MODE, LANDSCAPE);
  vga(GRAPHICS_PARAMETER, SCREEN_RESOLUTION, 1); // 62 mS

}


void loop()
{
  float fX;

  drawGraph();

  // Draw a sine wave
  for (float x = 0.0; x < 10.0; x = x + 0.1)
  {
    fX = sin(x) * 100;
    vga(PUT_PIXEL, (int)(x * 50.0 + GRAPH_MIN_X), (int)(200.0 +  fX), BLACK);
  }

  delay(10000);

}














