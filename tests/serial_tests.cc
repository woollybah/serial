#include <string>
#include <iostream>

#include "serial/serial.h"

using std::string;
using std::cout;
using std::endl;
using serial::Serial;
using serial::SerialExecption;

int main(int argc, char **argv) {
  try {
    Serial s("/dev/tty.usbserial-A900adHq", 115200, 2000);
    s.flush();
    long long count = 0;
    while (1) {
      // size_t available = s.available();
      // cout << "avialable: " << available << endl;
      string line = s.readline();
      cout << count << ": " << line << line.length() << endl;
      count++;
    }
  }
  catch (SerialExecption e)
  {
    cout << "Caught SerialException: " << e.what() << endl;
  }
  catch (...)
  {
    cout << "Caught an error." << endl;
  }
}
