/*  Purpose of this cpp file is to experiment and learn cpp at the same time.
    This has been a long time coming...
*/
#include <iostream>
#include <iomanip> // for setprecision()
#include <vector> //include is evaluated before compile time (not runtime) so can't be in a function
#include <cstring>


using namespace std;

float float_var = 1.25;

 // [row][columns], below is fixed columns
 // need to declare function outside of another, or use lambda
void printArray(const int array[][3], int rows){
    for (int i = 0; i < rows; ++i){
        for (int j = 0 ; j < 3; ++j){
            cout << array [i][j] << " ";
        }
        cout << endl;
    }
}
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

void ntu_basics_123() {
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
    cout <<"number4: "<<number4<<"\n"; // will print in dec

    // long literals is identified by suffix L, and LL for long long
    long long_number = 12345678L;     // Suffix 'L' for long
    long sum = 123;              // int 123 auto-casts to long 123L so that "sum" of type long can accept it
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
    char a = 98;
    char b = 'a';
    printf("Value of char: %d \n",a);
    printf("Value of char: %c \n",a);
    printf("Value of char: %d \n",b); 
    //printf depends on how you wanna read the variable as shown previously
    //cout default is char unless you want int:
    cout << (int)b <<endl;
    
    //common escape sequences
    printf("carriage-return:\rreplace");
    printf("newline: \n");
    printf("tab: \t");
    printf("\"double-quote\"");
    printf("\'single-quote\'");
    printf("back-slash \\");
    printf("newline: \n");
    // <cctype> header to check for type and case of chars
    
    // string literals -> double quotes instead of single for char
    string directionMsg= "Turn Right";
    string greetingMsg = "Hello";
    string statusMsg = "";
    cout << "Use \\\" to place \n a \" within\ta\tstring" << endl;
    cout << directionMsg << "\n" <<endl;

    // bool literals -> true and false ()
}

void ntu_basics_4(){
    //4.1 Arithmetic Operators
    int a = 5, b = 10, c = 15,d = 20;
    printf("multiply: %d \n", a*b);
    printf("division(floor): %d \n", c/b); // 15/10 = 1 remainder 5
    printf("modulus(remainder): %d \n", c%b); // remainder 5
    printf("addition/subtraction: %d \n", a+b-c);
    // note that int/int produces an int i.e. 1/2 --> 0 (instead of 0.5)
    // and also, cpp does NOT have an exponent operator, need to use #include <cmath> pow(2,3)
    
    //4.3 Mixed Type Operations
    int e = 2, f = 3;
    double g = 2.2, h = 3.3, i;
    i = e + g ; //int 2 + double 2.2 -> double 2.0 + double 2.2 -> double 4.2 
    // printf("%d\n",i); //error because it's not decimal
    printf("%lf\n",i); //lf is double (long float?)
    cout << i << endl; // cout don't need define
    
    //4.4 Overflow/Underflow
    int i1 = 2147483647; // max int, range of int is: [-2147483648, 2147483647]
    cout << i1 + 1 << endl; //overflow from positive to -2147483648
    cout << i1 + 2 << endl; //overflow to -2147483647
    cout << i1 * i1 <<endl; // 1
    
    int i2 = -2147483648;     // min int
    cout << i2 - 1 << endl;   // 2147483647 (underflow)
    cout << i2 - 2 << endl;   // 2147483646
    cout << i2 * i2 << endl;  // 0

    //4.5 Compound Assignment Operators
    cout << a << endl;
    a+=5;  
    cout << a << endl;
    a++;
    cout << a << endl;
    a-=5;
    cout << a << endl;
    a--;
    cout << a << endl;
    a*=3;
    cout << a << endl;
    a/=3;
    cout << a << endl;
    a%=3;
    cout << a << endl;
    // basically assigning in place 
    a = 1, b = 2;
    --a; // pre-decrement, for itself is the same
    cout << a << endl;
    b = a--; // b = old a, a = new a
    cout << a << endl;
    cout << b << endl;
    a = 1, b = 2;
    b = ++a; // b = new a, a = new a
    cout << a << endl;
    cout << b << endl;
    
    cout << fixed << setprecision(1); // print floating point number in fixed format
    int y = 3;
    double z = y;
    cout <<"z = " << z << endl; // type-casting
    cout << (double)5 <<endl; // int 5 to double 5.0
    double aDouble = 5.6; 
    int anInt = (int)aDouble;
    cout << anInt << endl;
    
    int staticcast = static_cast<int>(aDouble); //safer as compiler will throw error
    cout << staticcast << endl;
    
    // 4.8 relational and logical operators
    // ==, != , >, >=, <, <=, &&(AND), ||(OR), !(NOT), ^ (xor)
}

int ntu_basics_5(){
    // Conditional Flow Controls
    if (true){
    } else if(true){
    }
    else{
    }

    char oper; int num1=5, num2=3, result;
    // cin >> oper;
   // if break is missing, execution will flow through to the next case and end up on the last case. 
    switch (oper){
        case '+':
            result = num1 + num2; break; //break is for switch or for/while loops case
        case '-':
            result = num1 - num2; break;  //break is for switch or for/while loops case
        case '*':
            result = num1 * num2; break;  //break is for switch or for/while loops case
        default:
            cout << "Unknown operator" <<endl;
    }
    cout << result << endl;
    
    // inline conditional operator:
    int mark = 60;
    cout << ((mark >= 50) ? "PASS" : "FAIL" )<< endl; // (condition ? true : false)

    // Loop flow controls
    int sum = 0;
    for (int number = 1; number <= 1000; ++number){ // init;test;post-proc
        sum += number;
    }
    cout << sum << endl;

    int sum1 = 0, number1 = 11; // while(condition)-do
    while (number1 <= 10) {
        sum1 += number1; 
        ++number1; //increment number
        printf("\nnumber1: %d",number1);
    }
    // cout << sum1 << endl;
     
    int sum2 = 0, number2 = 11;
    do {                       // do-while(condition)
        sum2 += number2;
        ++number2;
        printf("\nnumber2: %d",number2);
    } while (number2 <=10);
    
    // cout << sum2 << endl;
    // difference between while-do and do-while is the order of the body and condition. in while-do, condition is tested first, then executed (might not be executed once)
    // do-while, the body is executed then the condition is tested (will be executed at least once) 
    // usually do-while is for input with validity check:
    // while-do is good for emergency stopping program i.e. sentinel value (indicates end of data) 
    bool valid = false;
    int number;
    do {
        cout << "Enter a number an int from 1-10:" << endl;
        cin >> number;
        
        if (number >=1 && number <=10){
            valid = true;
        }
    } while (!valid);

    //breaking the flow with break and continue
    //flows include for, while
    //however, they are poor structures and are hard to read and follow, use only when absolutely necessary
    //use a boolean flag instead: [isPrime = false] in your if statement
    
    int errorCount, errorCount2;
    cout << "Enter errorCount" << endl;
    cin >> errorCount; 
    cout << "Enter errorCount2" << endl;
    cin >> errorCount2; 

    if (errorCount > 10) {
        cout << "too many errors" << endl;
        exit(-1); // -1 indicates abnormal termination, or abort()
    }

    else if (errorCount2 > 10)
    {
        cout << "another way to exit" << endl;
        return -1;   
    } 
    return 0;
    
}

void ntu_basics_7(){
    string str1("Hello");
    string str2 = "world";
    string str3 = ("Hello");
    string str4(str1);

    cout << str2 <<endl;
    // as shown in stringtest.cpp, for multiple arguments, use getline for whole line
    // if you use cin, you need to flush cin buffer unless you wanna parse every argument
    cout << str1.length() << endl;
    cout << str1.size() << endl; // similar to previous
    cout << str1.empty() << endl; //check if empty
    str3 = str1 + " "+ str2 ; // concatenated
    cout << str3 << endl;
    cout << str1.at(0) << endl;
    cout << str1[0] << endl; //similar to previous
    cout << str1.at(str1.length()-1) << endl;
    cout << str1[str1.length()-1] << endl; //similar
    cout << str1.substr(2,4) << endl; //index including last one
    
    cout << str1 + str2 << endl;
    cout << "str1 compared with str3: " << str1.compare(str3) << endl; 
    if (str1 < str3){
        cout << "str1 is less than str3" << endl;
    }
    
    char c1= 'H', c2 = 'h';
    printf("c1 is: %d, c2 is: %d", c1, c2);
}

void ntu_basics_8(){
    //formatting input/output using IO manipulators <iomanip>
    
    //output formatting
    double pi = 3.14159265;
    cout << fixed << setprecision(4);
    cout << pi << endl;
    cout << "|" << setw(8) << pi << "|" << setw(10) << pi << "|" << endl;
    cout << setfill('-');
    cout << "|" << setw(8) << pi << "|" << setw(10) << pi << "|" << endl;
    // setw is not sticky, setfill replaces the empty characters
    cout << scientific; //e power of ...
    cout << pi << endl;


    //input formatting
    string areaCode, phoneCode, inStr;
    cout << "Enter your phone number in this format (XXX)XXX-XXXX" ;
    cin.ignore(); // skip (
    cin >> setw(4) >> areaCode; // indicates it looks for the next 4 characters
    cout << areaCode << endl;

}

void ntu_basics_9(){
    // array declaration
    int marks[5]; // note: values are undefined after declaration
    double numbers[10];
    const int SIZE = 4;
    float temps[SIZE]; //using const int as array length

    cout << marks[0] << endl; // gives a random number coz undefined

    int numbers1[] = {11,33,44} ;// if undefined, compiler counts the elements
    int numbers2[6] = {11,33,44}; // the rest of the array is 0
    cout << numbers2[4] <<endl;
    //printing an array

    int example_array[SIZE] = {1,2,3,4};
    for (int i = 0 ; i<SIZE; ++i) cout << example_array[i] << " ";
    cout << endl;

    int numbers3[5] = {}; // all elements = 0
    cout << "size of numbers3: " << sizeof(numbers3)/sizeof(numbers3[0]) << endl;
    // count number of elements by diving sizeof(array)/sizeof(array[0])
    
    // note that you cannot change the array size at runtime, you need to use vector<int> instead
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    cout << array[1] << endl; 

    cout << endl;
    cout << "testing lambda array:" <<endl; 

    auto lambdaArray = [=](const int array[][3], int rows){
        for (int i = 0; i < rows; ++i){
            for (int j = 0 ; j < 3; ++j){
                cout << array [i][j] << " ";
            }
            cout << endl;
        }
    };
    int myArray[][3] = {{8,2,4},{7,5,2}};
    lambdaArray(myArray,2);
    

    char message[256]; //Declare a char array holding up to 255 characters
    char str1[] = "Hello"; //Declare and initialise a "string literal", length of array is characters + 1 '\0
    char str1char[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    string str2 = "Hello";
    // cout << sizeof
    cout << sizeof(str1) << endl;
    cout << sizeof(str2) << endl; // prints the actual bytes
    cout << str2.size() << endl; // use for string
    cout << strcmp(str1, str1char) << endl; // returns 0, c-strings are equal
}


    

int main(){
    // learn_cout_cin();
    // variables();
    // learn_printf();
    // learn_pointers();
    // test();
    // ntu_basics_4();
    // ntu_basics_5();
    // ntu_basics_7();
    // ntu_basics_8();
    ntu_basics_9();
    return 0;
}