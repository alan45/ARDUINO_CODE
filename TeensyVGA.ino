//Simple Demo that demonstrates 'print' and 'println' new functionality.

#include "/home/alan/Documents/ARDUINO_CODE/TeensyVGA/Definitions.ino"

const int RESET =  4;

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
  int xArray[5] = {200, 230, 280, 400, 300};
  int yArray[5] = {250, 270, 300, 450, 220};
  char s[100] = "Hello World how are you today";
  char s1[100];
  elapsedMillis t;




  vga(BACK_COLOUR, BISQUE );
  vga(TEXT_BOLD, OFF);
  vga(TEXT_ITALIC, OFF);
  vga(TEXT_INVERSE, OFF);

  vga(TEXT_BACKGROUND, BISQUE);
  vga(TEXT_COLOUR, BLACK);

  vga(TEXT_FONT, FONT1);


  t = 0;
  vga(CLEAR_SCREEN);

  vga(MOVE_CURSOR, 20, 1);
  sprintf(s1, "Time to clear screen =  %d mS", (int)(t));
  vga(PUT_STRING, s1);
  t = 0;



  vga(MOVE_CURSOR, 3, 1);




  vga(PUT_STRING, s);

  //vga(MOVE_CURSOR,7,1);
  //vga(TEXT_FONT,FONT2);
  //vga(PUT_STRING,s);


  //vga(TEXT_INVERSE,ON);
  //vga(MOVE_CURSOR,9,1);
  //vga(TEXT_FONT,FONT3);
  //vga(PUT_STRING,s);

  //sprintf(s,"This is formatted %10.6f   %4.2f",3.1415926,5.0);
  //vga(TEXT_INVERSE,OFF);
  //vga(MOVE_CURSOR,11,1);
  //vga(TEXT_FONT,FONT3);
  //vga(PUT_STRING,s);



  vga(MOVE_CURSOR, 26, 1);
  sprintf(s1, "Text write time =  %d ", (int)(t));
  vga(PUT_STRING, s1);
  t = 0;




  vga(RECTANGLE_OUTLINE, 450, 110, 500, 320, RED );
  vga(RECTANGLE_FILLED, 500, 320, 590, 400, BLUEVIOLET);
  vga(CHANGE_COLOUR, BLUEVIOLET, CORNFLOWERBLUE );
  vga(CIRCLE_OUTLINE, 300, 300, 40, RED);
  vga(CIRCLE_FILLED, 300, 300, 20, BLUE);
  vga(DRAW_LINE, 1, 1, 300, 400, WHITE);
  vga(POLYGON_FILLED, 4, xArray, yArray, RED);
  vga(TRIANGLE_OUTLINE, 300, 200, 400, 300, 400, 40, RED);




  

    // Draw a sine wave
    for (float x = 0.0; x < 10.0; x = x + 0.01)
    {
      fX = sin(x) * 100;
      vga(PUT_PIXEL, (int)(x * 50.0 + 10), (int)(200.0 +  fX), BLACK);
    }

    vga(MOVE_CURSOR,32,1);
    sprintf(s1,"Sine wave time =  %d ",(int)(t));
    vga(PUT_STRING,s1);

    

    delay(10000);

    }















