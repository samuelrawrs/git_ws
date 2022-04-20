#include <stdio.h>
#include <iostream>
#define arrayLength(array) (sizeof((array))/sizeof((array)[0]))


void wrongMethod(int ar[]) // notice how this doesn't work as it's passing a pointer inside
{
    printf("%d\n", (int) sizeof(ar)/sizeof(int));
}



namespace anotherWay {
    typedef struct
        {
          int *values;
          int capacity;
        } intArray;

    void temp(intArray array)
    {
      printf("%d\n", array.capacity);
    }

    int main2(void)
    {
        int ar[]= {1, 2, 3};
        intArray arr;
        arr.values = ar;
        arr.capacity = arrayLength(ar);
        temp(arr); 
        return 0;
    }
}
int main(void)
{
    int ar[]={1,2,3};
    printf("%d\n", (int) sizeof(ar)/sizeof(int));
    wrongMethod(ar); //2
    std::cout<<arrayLength(ar)<<std::endl; //3
    std::cout<< sizeof(ar)/sizeof(ar[0]) << std::endl; //3

    anotherWay::main2();
    return 0;
}