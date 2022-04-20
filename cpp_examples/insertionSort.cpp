#include <iostream>
using namespace std;

void insertionSort(int a[], int size);
void print(const int a[], int iMin, int iMax);

int main(){
    const int SIZE = 8;
    int a[SIZE] = {8,4,5,3,2,9,4,1};
    print(a, 0, SIZE -1);
    cout << endl;
    insertionSort(a, SIZE);
}

void insertionSort (int a[], int size){
    int temp;
    for (int i = 1 ; i < size; ++i){
        cout << "i: " << i << endl;

        // for tracing
        print(a, 0, i-1); // LHS, already sorted
        print(a, i, size-1);  //RHS, going to be sorted
        cout << endl;
        // for element at position i, insert into correct position in [0, i-1]
        for (int prev = 0; prev < i ; ++prev){
            cout << "Check with position at: " << prev << endl;
            if (a[i] < a[prev]){
                cout << a[i] << " is smaller than " << a[prev]<< endl;
                //check marker vs first element and until marker
                temp = a[i]; // store a[i]
                for (int shift = i; shift > prev; --shift){ 
                    // shift = marker position, keep shifting until in the correct position
                    cout << "shift " << a[shift -1] << " to "<< a[shift] << endl;
                    a[shift] = a[shift -1]; //moving other sorted numbers to the right
                }
                a[prev] = temp; // new position of moved value
                break;
            }
        }
    }
}


void print(const int a[], int iMin, int iMax){
    cout << "{";
    for (int i = iMin; i <= iMax; ++i){
        cout << a[i];
        if (i < iMax) cout << ","; // check if in between
    }
    cout << "} ";
}