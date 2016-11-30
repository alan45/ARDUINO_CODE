//Simple Demo that demonstrates 'print' and 'println' new functionality.

#include "/home/alan/Documents/ARDUINO_CODE/TeensyVGA/Definitions.ino"

const int RESET =  4;
const int GRAPH_MIN_X = 40;
const int GRAPH_MIN_Y = 30;
const int GRAPH_MAX_X = 590;
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
  float increment;
  char s[20];
  elapsedMillis t;




  vga(BACK_COLOUR,  LIGHTSTEELBLUE );
  vga(TEXT_BOLD, OFF);
  vga(TEXT_ITALIC, OFF);
  vga(TEXT_INVERSE, OFF);
  vga(TEXT_BACKGROUND,  LIGHTSTEELBLUE);
  vga(TEXT_COLOUR, BLACK);
  vga(TEXT_FONT, FONT1);
  vga(CLEAR_SCREEN);

  // The outline of the graph
  vga(RECTANGLE_OUTLINE,GRAPH_MIN_X,GRAPH_MIN_Y,GRAPH_MAX_X,GRAPH_MAX_Y,GREEN);


 double xValue = 0;

 increment = (GRAPH_MAX_X - GRAPH_MIN_X)/10;
 //Draw X axis ticks
   for(int x1=GRAPH_MIN_X + increment; x1< GRAPH_MAX_X; x1 = x1 + increment)
   {
   vga(DRAW_LINE,x1,GRAPH_MAX_Y,x1,GRAPH_MIN_Y,LIGHTGREEN ); 
   }

 increment = (GRAPH_MAX_X - GRAPH_MIN_X)/10;
 //Label X axis ticks
 for(int x1=GRAPH_MIN_X; x1 < GRAPH_MAX_X + increment; x1 = x1 + increment)
   {
   vga(MOVE_ORIGIN,x1-8,GRAPH_MAX_Y+5);
   sprintf(s,"%0.1f",xValue);
   vga(PUT_STRING,s);
   xValue = xValue + 0.1;
   }






   // Draw a sine wave
    for (float x = 0.0; x < 10.0; x = x + 0.1)
    {
      fX = sin(x) * 100;
      vga(PUT_PIXEL, (int)(x * 50.0 + GRAPH_MIN_X), (int)(200.0 +  fX), BLACK);
    }

  

    delay(10000);

    }















