#include <iostream>
#include <math.h>
#include <string>
#include <stack>
using namespace std;

int bitsToInt(char bitList[], bool show) {
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

  if (show) {
    cout << bitList << " is " << result << endl;
    return 0;
  }

  return result;
}

void intToBits(string bitList) {
  int num = stoi(bitList);
  stack<int> bits;

  int temp = num;
  while (temp != 0) {
    bits.push(temp % 2);
    temp *= 0.5;
  }

  cout << num << " is ";
  while (!bits.empty()) {
    cout << bits.top();
    bits.pop();
  }
  cout << endl;
}

int main(int argc, char* argv[]) {

  intToBits(argv[1]);

  return 0;
}
