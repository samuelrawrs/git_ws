#include <iostream>
using namespace std;

void selectionSort(int a[], int size);
void print(int a[], int iMin, int iMax);


int main(){
    const int SIZE = 8;
    int a1[SIZE]= {8,4,5,3,2,9,4,1};
    print(a1, 0, SIZE-1);
    cout << endl;
    selectionSort(a1, SIZE);
}


void selectionSort(int a[], int size){
    int pass = 1;
    for (int i = 0; i <= size; i++){
        //tracing output
        cout << "Pass: " << pass++ << endl;
        print(a,0,i-1);
        print(a, i, size-1);

        int smallest = a[i];
        for(int select = i; select <= size -1; select++){
            if(smallest>a[select]){ // no longer smallest
                smallest = a[select]; //store smallest value
                a[select] = a[i]; // shift values    
                a[i] = smallest;
            }
        }
        cout << "=> ";
        print(a,0,i-1);
        print(a, i, size-1);
        cout << endl;
    }
    
}

void print(int a[], int iMin, int iMax){
    cout << "{";
    for(int i = iMin; i <= iMax; i++){
        cout << a[i];
        if(i <=iMax - 1){
            cout << ",";
        }
    }
    cout << "} ";
}