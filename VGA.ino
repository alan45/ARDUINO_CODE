

// action, pointer
// Used to write character strings

void vga(int action, char *p1)
{
  int i = 0;
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  // Write out characters until we get a null

  while (p1[i] != 0x00)
  {
    Serial1.write(p1[i]);
    i++;
  };

  Serial1.write(0x00);

  waitForResponse();
}






// action, parameter, pointer, pointer , parameter
void vga(int action, int p1, int *p2, int *p3, int p4)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  Serial1.write((p1 >> 8) & 0xFF);
  Serial1.write( p1 & 0xFF);

  for (int i = 0; i < p1; i++)
  {
    Serial1.write((p2[i] >> 8) & 0xFF);
    Serial1.write( p2[i] & 0xFF);

    Serial1.write((p3[i] >> 8) & 0xFF);
    Serial1.write( p3[i] & 0xFF);
  }

  Serial1.write((p4 >> 8) & 0xFF);
  Serial1.write( p4 & 0xFF);

  waitForResponse();
}




// action only
void vga (int action)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  waitForResponse();
}





// action plus 1 parameter
void vga (int action, int p1)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  Serial1.write((p1 >> 8) & 0xFF);    // p1 value
  Serial1.write(p1 & 0xFF);

  waitForResponse();
}




// action plus 2 parameters
void vga (int action, int p1, int p2)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  Serial1.write((p1 >> 8) & 0xFF);    // p1 value
  Serial1.write(p1 & 0xFF);

  Serial1.write((p2 >> 8) & 0xFF);    // p2 value
  Serial1.write(p2 & 0xFF);

  waitForResponse();
}





// action plus 3 parameters
void vga (int action, int p1, int p2, int p3)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  Serial1.write((p1 >> 8) & 0xFF);    // p1 value
  Serial1.write(p1 & 0xFF);

  Serial1.write((p2 >> 8) & 0xFF);    // p2 value
  Serial1.write(p2 & 0xFF);

  Serial1.write((p3 >> 8) & 0xFF);    // p3 value
  Serial1.write(p3 & 0xFF);

  waitForResponse();
}




// action plus 4 parameters
void vga (int action, int p1, int p2, int p3, int p4)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  Serial1.write((p1 >> 8) & 0xFF);    // p1 value
  Serial1.write(p1 & 0xFF);

  Serial1.write((p2 >> 8) & 0xFF);    // p2 value
  Serial1.write(p2 & 0xFF);

  Serial1.write((p3 >> 8) & 0xFF);    // p3 value
  Serial1.write(p3 & 0xFF);

  Serial1.write((p4 >> 8) & 0xFF);    // p4 value
  Serial1.write(p4 & 0xFF);

  waitForResponse();
}



// action plus 5 parameters
void vga (int action, int p1, int p2, int p3, int p4, int p5)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  Serial1.write((p1 >> 8) & 0xFF);    // p1 value
  Serial1.write(p1 & 0xFF);

  Serial1.write((p2 >> 8) & 0xFF);    // p2 value
  Serial1.write(p2 & 0xFF);

  Serial1.write((p3 >> 8) & 0xFF);    // p3 value
  Serial1.write(p3 & 0xFF);

  Serial1.write((p4 >> 8) & 0xFF);    // p4 value
  Serial1.write(p4 & 0xFF);

  Serial1.write((p5 >> 8) & 0xFF);    // p5 value
  Serial1.write(p5 & 0xFF);

  waitForResponse();
}





// action plus 6 parameters
void vga (int action, int p1, int p2, int p3, int p4, int p5, int p6)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  Serial1.write((p1 >> 8) & 0xFF);    // p1 value
  Serial1.write(p1 & 0xFF);

  Serial1.write((p2 >> 8) & 0xFF);    // p2 value
  Serial1.write(p2 & 0xFF);

  Serial1.write((p3 >> 8) & 0xFF);    // p3 value
  Serial1.write(p3 & 0xFF);

  Serial1.write((p4 >> 8) & 0xFF);    // p4 value
  Serial1.write(p4 & 0xFF);

  Serial1.write((p5 >> 8) & 0xFF);    // p5 value
  Serial1.write(p5 & 0xFF);

  Serial1.write((p6 >> 8) & 0xFF);    // p6 value
  Serial1.write(p6 & 0xFF);

  waitForResponse();
}



// action plus 7 parameters
void vga (int action, int p1, int p2, int p3, int p4, int p5, int p6, int p7)
{
  Serial1.clear();

  Serial1.write((action >> 8) & 0xFF);
  Serial1.write(action & 0xFF);

  Serial1.write((p1 >> 8) & 0xFF);    // p1 value
  Serial1.write(p1 & 0xFF);

  Serial1.write((p2 >> 8) & 0xFF);    // p2 value
  Serial1.write(p2 & 0xFF);

  Serial1.write((p3 >> 8) & 0xFF);    // p3 value
  Serial1.write(p3 & 0xFF);

  Serial1.write((p4 >> 8) & 0xFF);    // p4 value
  Serial1.write(p4 & 0xFF);

  Serial1.write((p5 >> 8) & 0xFF);    // p5 value
  Serial1.write(p5 & 0xFF);

  Serial1.write((p6 >> 8) & 0xFF);    // p6 value
  Serial1.write(p6 & 0xFF);

  Serial1.write((p7 >> 8) & 0xFF);    // p7 value
  Serial1.write(p7 & 0xFF);



  waitForResponse();
}







void waitForResponse()
{
  int flag = 0;
  elapsedMillis millisecondsResponseTime;

  millisecondsResponseTime = 0;

  while (flag == 0)
  {
    if (Serial1.available() > 0)          flag = 1;
    if (millisecondsResponseTime >= 1000)   flag = 1;
  }
  Serial1.clear();
}



