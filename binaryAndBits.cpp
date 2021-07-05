#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int bitsToInt(char bitList[]) {
  char bit = '0';

  int digits = 0;
  char i = ' ';
  int counter = 0;
  while(i != '\0') {
    i = bitList[counter];
    counter++;
  }
  digits = counter - 1 ;

  int result = 0;

  int placeValue = pow(2, digits - 1);

  for (int i = 0; i < digits; i++) {
    bit = bitList[i];
    if (i == 0 && bitList[i] == '1') {
      result = -1 * pow(2, digits - 1);
      placeValue *= 0.5;
      continue;
    }
    result += (bit == '1') ? placeValue : 0;
    placeValue *= 0.5;
  }

  return result;
}

int main(int argc, char* argv[]) {

  cout << argv[1] << " is " << bitsToInt(argv[1]) << endl;

  return 0;
}
