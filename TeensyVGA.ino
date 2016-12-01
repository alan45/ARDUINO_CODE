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
  float x, fX;
  int i;
  int graphXdata[1200];
  int graphYdata[1200];
  
  for (i = 0; i < 1000; i++)
  {
    x = (float)(i / 100.0);
    fX = sin(x) * 100;
    
    graphXdata[i] = i;
    graphYdata[i] = (int)(fX);
  }

  drawGraph();
  plotData(graphXdata,graphYdata);



  delay(10000);

}

void plotData(int *Xdata,int *Ydata)
{
  int i, xValue, yValue;
  
  for (i = 0; i < 1000; i++)
  {

    //Note need to work on a way to scale the Xaxis value automatically
    xValue = (int)(((float)(Xdata[i])/1.79)) + GRAPH_MIN_X; // Convert i to pixels offset from start of x axis
    yValue = Ydata[i] + 300;
    vga(PUT_PIXEL, xValue , yValue, BLACK);
  }
}











