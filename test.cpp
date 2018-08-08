// Simple C++ program to display "Hello World"
#include <unistd.h>

// Header file for input output functions
#include <iostream>

/* @secret
 */
int main() {
  for (int i = 0 ; ; i++)  {
    std::cout << "Hello World " << i << "\n";
    std::cout.flush();
    usleep(1000000);
  }
  return 0;
}
