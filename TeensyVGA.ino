
#include "/home/alan/Documents/ARDUINO_CODE/TeensyVGA/Definitions.ino"


const int byte0 =    20;       
const int byte1 =    19;      
const int byte2 =    18;        
const int byte3 =    17;        
const int byte4 =    16;        
const int byte5 =    15;      
const int byte6 =    14;        
const int byte7 =    13; 
const int loadFPGA  = 22;
const int FPGAready = 21;


const int RESET =  4;
const int GRAPH_MIN_X = 60;
const int GRAPH_MIN_Y = 100;
const int GRAPH_MAX_X = 620;
const int GRAPH_MAX_Y = 420;


volatile int  count;
volatile byte data_from_FPGA;
volatile int graphXdata[1200];
volatile int graphYdata[1200];





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
  
  
  
  // Set up the interrupt input from the FPGA
  count = 0;
  
  // initialize digital pins.

  pinMode(byte0,     INPUT);
  pinMode(byte1,     INPUT);
  pinMode(byte2,     INPUT);
  pinMode(byte3,     INPUT);
  pinMode(byte4,     INPUT);
  pinMode(byte5,     INPUT);
  pinMode(byte6,     INPUT);
  pinMode(byte7,     INPUT);
  pinMode(FPGAready, INPUT);
  pinMode(loadFPGA,  OUTPUT);
 
 data_from_FPGA = 39;
 digitalWriteFast(loadFPGA,LOW);
 attachInterrupt(digitalPinToInterrupt(FPGAready), service_FPGA, RISING);
  
}


void loop()
{
  int i;
  char s[20];

 for(i=0;i<250;i++)
 {
  digitalWriteFast(loadFPGA,LOW);
  delay(1);
  digitalWriteFast(loadFPGA,HIGH);
  delayMicroseconds(1);
  digitalWriteFast(loadFPGA,LOW);
 }


 if(count > 1000)  
 {
  detachInterrupt(digitalPinToInterrupt(FPGAready));;
  drawGraph();
  plotData(graphXdata,graphYdata);
  count = 0;
  attachInterrupt(digitalPinToInterrupt(FPGAready), service_FPGA, RISING);
 }

   
  vga(MOVE_ORIGIN, 20,20);
  sprintf(s, "%i", count);
  vga(PUT_STRING, s);

  vga(MOVE_ORIGIN, 80,20);
  i = (int)(data_from_FPGA);
  sprintf(s, "%d", i);
  vga(PUT_STRING, s);
  
  
  delay(500);

  
}





void plotData(volatile int *Xdata,volatile int *Ydata)
{
  int i, xValue, yValue;
  
  for (i = 0; i < 1000; i++)
  {

    //Note need to work on a way to scale the Xaxis value automatically
    xValue = (i/2) + GRAPH_MIN_X; // Convert i to pixels offset from start of x axis
    yValue = GRAPH_MAX_Y - Ydata[i] ;
    vga(PUT_PIXEL, xValue , yValue, BLACK);
  }
}








// Interrupt routine
void service_FPGA()
{
  // Get data from FPGA and set the appropriate bits in the byte dat_from_FPGA
  bitWrite(data_from_FPGA, 0, digitalReadFast(byte0));
  bitWrite(data_from_FPGA, 1, digitalReadFast(byte1));
  bitWrite(data_from_FPGA, 2, digitalReadFast(byte2));
  bitWrite(data_from_FPGA, 3, digitalReadFast(byte3));
  bitWrite(data_from_FPGA, 4, digitalReadFast(byte4));
  bitWrite(data_from_FPGA, 5, digitalReadFast(byte5));
  bitWrite(data_from_FPGA, 6, digitalReadFast(byte6));
  bitWrite(data_from_FPGA, 7, digitalReadFast(byte7));
  graphYdata[count] = data_from_FPGA;
  count++;
}









