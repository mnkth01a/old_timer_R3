#include "MultiFunctionShield.h"

// put function declarations here:
int myFunction(int, int);

MultiFunctionShield mfs;

void setup()
{
  // put your setup code here, to run once:
  mfs.begin();
}

void loop()
{
  int result = myFunction(2, 3);
  mfs.Display(result);
  delay(1000);
  mfs.Clear();
  delay(1000);
  mfs.Display(1234);
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}