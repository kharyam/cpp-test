// Simple C++ program to display "Hello World"
 
// Header file for input output functions
#include <iostream> 
#include <unistd.h>

using namespace std;
 
int main()
{
    for (int i = 0 ; i < 5 ; i++)
    {
        cout << "Hello World " << i << "\n";
        cout.flush();
        usleep(1000000);
    }    
    return 0;
}
