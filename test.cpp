// Simple C++ program to display "Hello World"

// Header file for input output functions
#include <iostream>
#include <unistd.h>
 
int main()
{
  for (int i = 0 ; i < 5 ; i++)
  {
    std::cout << "Hello World!! " << i << "\n";
    std::cout.flush();
    usleep(1000000);
  }
  return 0;
}
