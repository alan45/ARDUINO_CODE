void drawGraph()
{

  int i, labelLength, labelStart, pixelLength;
  float increment;
  char s[20];
  double xValue = 0;
  double yValue = 0;


  vga(BACK_COLOUR,  LIGHTSTEELBLUE );
  vga(TEXT_BOLD, OFF);
  vga(TEXT_ITALIC, OFF);
  vga(TEXT_INVERSE, OFF);
  vga(TEXT_BACKGROUND,  LIGHTSTEELBLUE);
  vga(TEXT_COLOUR, BLACK);
  vga(TEXT_FONT, FONT1);
  vga(CLEAR_SCREEN);

  // Draw the outline of the graph
  vga(RECTANGLE_OUTLINE, GRAPH_MIN_X, GRAPH_MIN_Y, GRAPH_MAX_X, GRAPH_MAX_Y, GREEN);

  //*******************Draw and label the Axes ******************************


  increment = (GRAPH_MAX_X - GRAPH_MIN_X) / 10;
  //Draw X axis ticks
  for (int x1 = GRAPH_MIN_X + increment; x1 < GRAPH_MAX_X; x1 = x1 + increment)
  {
    vga(DRAW_LINE, x1, GRAPH_MAX_Y, x1, GRAPH_MIN_Y, GREEN );
  }

  increment = (GRAPH_MAX_X - GRAPH_MIN_X) / 10;
  //Label X axis ticks
  for (int x1 = GRAPH_MIN_X; x1 < GRAPH_MAX_X + increment; x1 = x1 + increment)
  {
    vga(MOVE_ORIGIN, x1 - 8, GRAPH_MAX_Y + 5);
    sprintf(s, "%0.1f", xValue);
    vga(PUT_STRING, s);
    xValue = xValue + 0.1;
  }


  increment = (GRAPH_MAX_Y - GRAPH_MIN_Y) / 10;
  //Draw Y axis ticks
  for (int y1 = GRAPH_MIN_Y + increment; y1 < GRAPH_MAX_Y; y1 = y1 + increment)
  {
    vga(DRAW_LINE, GRAPH_MIN_X, y1, GRAPH_MAX_X, y1, GREEN );
  }


  increment = (GRAPH_MAX_Y - GRAPH_MIN_Y) / 10;
  //Label Y axis ticks
  for (int y1 = GRAPH_MAX_Y; y1 > GRAPH_MIN_Y - increment; y1 = y1 - increment)
  {
    vga(MOVE_ORIGIN, GRAPH_MIN_X - 25, y1 - 5);
    sprintf(s, "%0.1f", yValue);
    vga(PUT_STRING, s);
    yValue = yValue + 0.1;
  }


  // Label the Xaxis with the midpoint of the string positioned at half way along under the X axis.

  sprintf(s, "Time in seconds"); // Defines the string to label the X axis
  pixelLength  = strlen(s) * 8;  // gets the length in pixels
  labelStart   = GRAPH_MIN_X + ((GRAPH_MAX_X - GRAPH_MIN_X) / 2) - (pixelLength / 2);

  vga(MOVE_ORIGIN, labelStart, GRAPH_MAX_Y + 20);
  vga(PUT_STRING, s);



  // Label the Yaxis with the midpoint of the string positioned at half way along  the Y axis and vertical text.

  sprintf(s, "Alans Y Label");     // Defines the string to label the X axis
  labelLength  = strlen(s);        // gets the length in characters
  pixelLength  = labelLength * 10;  // gets the height of the character in pixels
  labelStart   = GRAPH_MAX_Y - ((GRAPH_MAX_Y - GRAPH_MIN_Y) / 2) - pixelLength / 2;

  for (i = 0; i < labelLength; i++)
  {
    vga(MOVE_ORIGIN, GRAPH_MIN_X - 40, labelStart + i * 10);
    vga(PUT_CHARACTER, s[i]);
  }
}

