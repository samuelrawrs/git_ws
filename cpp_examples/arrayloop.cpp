#include <iostream>
#include <iomanip>
#include <cmath>
#define SIZE 7

using namespace std;

int main() {
    int marks[] = {40, 30, 59, 60, 70};
    int sum = 0;
    int sumSq= 0;
    int num_marks;
    double mean, stdDev;
    
    num_marks = sizeof(marks)/sizeof(marks[0]);
    cout << "Number of marks: " ; 
    cout << num_marks << endl;
    
    for (int i = 0; i < num_marks; ++i) {
        sum += marks[i];
        sumSq += pow(marks[i],2);
    }
    mean = (double)sum/num_marks;
    cout << fixed << "Mean is " << setprecision(2) << mean << endl;

    stdDev = sqrt((double)sumSq/num_marks - pow(mean,2));
    cout << fixed << "Std dev is " << setprecision(2) << stdDev << endl;
}