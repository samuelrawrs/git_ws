#include <iostream>
using namespace std;

int main (){
    char msg[256];
    cout << "Enter a message with spaces" << endl;
    cin.getline(msg, 256); //Read up to 255 characters
    cout << msg << endl;
    
    for (int i = 0; msg[i] == '\0'; ++i){
        cout << msg[i];
    }
    }