
/* Testing string class input and output (TestStringIO.cpp) */
#include <iostream>
#include <string>     // Need this header to use string class
#include <limits>
using namespace std;  // Also needed for <string>
 
int main() {
   string message("Hello");
   string message2;
   cout << message << endl;
 
   // Input a word (delimited by space) into a string
   cout << "Enter a message (no space): ";
   cin >> message;
   cout << message << endl;
 

   cout << "Second arg will still be in message, cin accepts it: ";
   cin >> message; // obtain 2nd arg
   cin >> message2; // obtain 3rd arg
   cout << "Now cout will show it: " << message <<endl;
   cout << message2 << endl;

   cout << "Now let's flush the cin buffer" << endl;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // flush cin up to newline (need <limits> header)
   // Input a line into a string
   cout << "Enter a message (with spaces): ";
   getline(cin, message);  // Read input from whole of cin into message
   cout << message << endl;
   return 0;
}
