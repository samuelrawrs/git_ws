#include <iostream>
using namespace std;

//Function Prototype
int sum(int array[], int size);
void print(int array[], int size);

int main(){
    int a1[] = {8,4,5,3,2};
    print(a1, 5);
    cout << "sum is " << sum(a1,5) << endl;
}

//Function definitions
//Return sum of given array
