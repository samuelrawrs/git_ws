/*  Purpose of this cpp file is to experiment and learn cpp at the same time.
    This has been a long time coming...
*/
#include <iostream>
using namespace std;

float float_var = 1.25;


void learn_printf()
{
    char ch = 'A';
    char ascii = 65;
    char str[20] = "fresh2refresh.com";
    float flt = 10.234;  // 7 decimal digits
    int no = 150, no1 = 2, no2 = 5;
    double dbl = 20.123456;  // 15 decimal digits
    bool boolean_var = false;
    unsigned int a = 10;

    printf("%u \n", a);
    printf("%s \n", boolean_var ? "true":"false");
    printf("Boolean is %d \n", boolean_var);
    printf("Character is %c \n", ch);
    printf("String is %s \n" , str);
    printf("Float value is %f \n", flt);
    printf("Integer value is %d\n" , no);
    printf("Integer value of no2 is %d \n",no2);
    printf("Double value is %lf \n", dbl);
    printf("Octal value is %o \n", no);
    printf("Hexadecimal value is %x \n", no);
    printf("ASCII value is %c \n", ascii);
    printf("Multiple values is %d by %d order %f\n", no, no1, dbl);
}

void learn_cout_cin(){
    int x, y, z;
    cout << "This is the value of the float var: " << float_var << endl;
    cout << "Testing input of 2 values separated by space\n";
    cin >> x >> y;
    cout << x << y;
}


void learn_operators(){
    int x, y, result;
    x = 70;
    y = 50;
    // result = x + y;
    // result = x - y;
    // result = x * y;
    // result = x / y; //quotient
    result = x % y;  //remainder
    ++result; //or result++
    --result; //or result--
    result+=5; //adding inplace
    printf("%d\n",result);

    // && and, || or, !, not, etc...

    //note that arithmetic operations on 2 ints make an int, but arithmetic operations on int and double makes a double
    //i.e. 1/2=0 but 1.0/2.0 =0.5, 1.0/2 = 0.5, 1/2.0 = 0.5
    int i = 3;
    double d;
    d = i;  // d = 3.0
    d = 88; // d = 88.0

    d = 55.66;
    i = d; // i = 55 (truncated w warning);

    //typecasting
    d = 5.5;
    i = int(d); // i = 5 (truncated without warning)

}

void learn_pointers(){
    //reference (&) is getting address from variable
    //dereference (*) is getting variable from address


    // (*) can either be a declaration or an expression
    // [int *declare = &something is a declaration]
    // [*declare = 10 is an expression]

    // (&) can either be a declaration or an expression
    // [int number = 20] &number is declared 
    // [int &declare = number is an expression]
    // so now, in some sense, declare and number are always tied together since they point to the same reference
    
    int ptr = 20;  //&ptr to access address
    int another_ptr = 30;
    int *foo = &ptr;  //declare a pointer variable foo pointing to an int, filled by &ptr, address of ptr

    printf("address of ptr is %p\n",&ptr);
    printf("foo is a pointer, equals to ptr:%p\n",foo);
    printf("you can also see what the pointer is pointing to (dereference) using *pointer, in this case expecting an int, %d\n", *foo);

    *foo = 99;
    printf("Assigned a value to where the pointer points to, ptr changes value too:%d\n",ptr);

    foo = &another_ptr;
    printf("Shifted foo to look at smth else %d\n",*foo);

    //note pointer has types too, can only point to address of declared type

    int i = 88;
    double d = 55.66;
    int *iPtr = &i;    // int pointer pointing to an int value
    double *dPtr = &d; // double pointer pointing to a double value
    
    // iPtr = &d;   // ERROR, cannot hold address of different type
    // dPtr = &i;   // ERROR
    // iPtr = i;    // ERROR, pointer holds address of an int, NOT int value

    //using nullpointers
    int * p = nullptr;

    //testing references/aliasing
    int number = 20;
    int &twin_number = number;
    printf("twin_number value is:%d\n",twin_number);
    twin_number = 30;
    printf("Now number has changed value too, %d\n",number);
}

void ntu_learn_pointers(){
 int number1 = 88, number2 = 22;
 
   // Create a pointer pointing to number1
   int * pNumber1 = &number1;  // Explicit referencing
   *pNumber1 = 99;             // Explicit dereferencing
   cout << *pNumber1 << endl;  // 99
   cout << &number1 << endl;   // 0x22ff18
   cout << pNumber1 << endl;   // 0x22ff18 (content of the pointer variable - same as above)
   cout << &pNumber1 << endl;  // 0x22ff10 (address of the pointer variable)
   pNumber1 = &number2;        // Pointer can be reassigned to store another address
 
   // Create a reference (alias) to number1
   int & refNumber1 = number1;  // Implicit referencing (NOT &number1)
   refNumber1 = 11;             // Implicit dereferencing (NOT *refNumber1)
   cout << refNumber1 << endl;  // 11
   cout << &number1 << endl;    // 0x22ff18
   cout << &refNumber1 << endl; // 0x22ff18
   //refNumber1 = &number2;     // Error! Reference cannot be re-assigned
                                // error: invalid conversion from 'int*' to 'int'
   refNumber1 = number2;        // refNumber1 is still an alias to number1.
                                // Assign value of number2 (22) to refNumber1 (and number1).
   number2++;   
   cout << refNumber1 << endl;  // 22
   cout << number1 << endl;     // 22
   cout << number2 << endl;     // 23

   //stopped at 2.4
}

void ntu_basics() {
    //fundamental types: and at least __ bytes = 8*
    int signed_integer = 0; // 4 bytes, -2147483648 to 2147483647
    signed int similar_to_above_int;
    unsigned int unsigned_integer = 0; // 4 bytes, 0 to 4294967295
    char character = 'A'; // 1 byte, signed or unsigned depends on implementation
    signed char tiny_int = 0; // 1 byte, -128 to 127
    unsigned char unsigned_tiny_int = 0; //1 byte, 0 to 255
    short short_signed_integer = 0; // 2 bytes, -32768 to 32767
    signed short similar_to_above_short;
    unsigned short short_unsigned_integer = 0; // 2 bytes, 0 to 65535
    long long_signed_integer = 0; // 4 bytes - similar to int
    unsigned long long_unsigned_integer = 0; // 4 bytes - similar to int
    long long long_long_signed_integer = 0; // 8 bytes, -2**63 to 2**63 - 1
    unsigned long long long_long_unsigned_integer = 0; // 8 bytes, 0 to 2**64 -1

    float float_var; // 4 bytes, 7 digits 
    double double_var; // 8 bytes, 15 digits
    long double long_double_var; // 12 bytes

    bool true_or_false; // 1 byte
    wchar_t wide_char; // char can take 256 values (iso) but wchar_t can take 65546(unicode)
    std::size_t foo; //equivalent to an unsigned int, used for counting, size and length

    // #include <limits> // contains information about limits of integer type std::numeric_limits
    

    //rule of thumb: use integer and double by default, use int/unsigned int for counting/indexing

    typedef unsigned int uint; //alias for types
    typedef unsigned int size_t;  //most C++ compilers already use this

    //literals are just specific constant values

    // int literals can start with 0 for octal, 0x for hexa, 0b for binary
    int number1 = 1234;       // Decimal
    int number2 = 01234;      // Octal 1234, Decimal 2322
    int number3 = 0x1abc;     // hexadecimal 1ABC, decimal 15274
    int number4 = 0b10001001; // binary (may not work in some compilers)

    cout <<"number1: "<<number1<<"\n";
    cout <<"number2: "<<number2<<"\n";
    cout <<"number3: "<<number3<<"\n";
    cout <<"number4: "<<number4<<"\n";

    // long literals is identified by suffix L, and LL for long long
    long long_number = 12345678L;     // Suffix 'L' for long
    long sum = 123;              // int 123 auto-casts to long 123L so that "sum" can accept it
    long long bigNumber = 987654321LL;  // Need suffix 'LL' for long long int
    cout <<"long_number: "<<long_number<<"\n";

    //numbers with decimal points are treated as double by default, must use suffix
    float f=0.67;  //0.67 is a double but autocasts to float so that float accepts it
    if(f == 0.67){  // since f is a float and 0.67 is a double, it's not equal
        printf("no suffix works\n");
    }
    else if (f == 0.67f){
        printf("with suffix works\n");
    }
    else{
        printf("error"); 
    }

    //char literals must use 'singlequotes', char and 8-bit signed integers are interchangeable
}


void test(){
    string &test;
    test = "testing";
    cout<<test.empty();
}
int main(){
    // learn_cout_cin();
    // variables();
    // learn_printf();
    // learn_pointers();
    // learn_operators();
    // ntu_basics();
    test();
    return 0;
}