#include <iostream>
using namespace std;

int main() {
    int numbers[] = {11, 22, 33, 44, 55};

    // read-only numbers in array
    for (int number : numbers){
        cout << number << " ";
    }
    cout << endl;
    
    // using reference (&) to change all numbers to 99
    for (int &number : numbers){
        number = 99;
        cout << number << " ";
    }
    cout << endl;
    cout << numbers[0] << endl;

}