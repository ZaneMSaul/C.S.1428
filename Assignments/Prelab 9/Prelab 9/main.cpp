// Lab 10 Pre-Lab Assignment

// Add the following functions:

// 1. 'getRadius' asks the user to enter the radius of a circle
//     and returns the given value. (should return a double)

// 2. 'calcArea' takes the radius and returns the area of a circle.

// 3. 'printResults' void type function that should print the results to
//    console.

// Your function needs to have a local variable called 'PI' which holds the
// value '3.14159'.

// The function call is provided, you just need to implement the
// function prototype and function definition.

#include <iostream>
using namespace std;

// TODO - write the prototypes here
void getRadius( double & );
double calcArea( double );
void printResults( double area );

int main()
{
    double radius = 0.0,
           area = 0.0;
    
    // TODO - call 'getRadius' function and assign the
    //        returned value to radius.
    getRadius( radius );
    
    area = calcArea(radius);
    
    // TODO - move the following cout to the 'printResults' function
    //        and call that function here instead.
    printResults( area );
    
    return 0;
}

// TODO - write the functions here
void getRadius( double &radius )
{
    cout << "Enter radius: ";
    cin >> radius;
}

double calcArea( double radius )
{
    const double PI = 3.14159;
    
    double area;
    
    area = 2 * PI * radius;
    
    return area;
}

void printResults( double area )
{
    cout << "The area of your circle is " << area << " units squared."
    << endl;
}
