/*
 File: prog1_zms24.cpp
 
 Zane Saul
 C.S.1428.751
 Program: 1
 Lab Section: L52
 Program: #1
 Due Date: 07/16/2017
 
 This program prompts the user for the diameter of a sphere (in inches)
 allowing for real input data. After reading the value entered at the
 keyboard, the program calculates the radius of the sphere. It then
 calculates the volume of the sphere. Two blank lines are displayed
 before the author's identifying information is written to the console.
 One blank line is written to the console before the diameter of the
 sphere along with the calculated radius and volume of the sphere are
 written in sentence form. Numeric values in the output statement are
 displayed to one decimal place. The layout and content of the output
 screen are shown below.
 
 Input (keyboard):  diameter  (double)
 Constants:         PI = 3.141592 (double)
 Output (console):
 Zane Saul
 C.S.1428.751
 Lab Section: L52   
 07/16/2017

 A sphere with a diameter of ? inches
 and a radius of ? inches has a volume
 of ? cubic inches.
 
 ================================================
 
 <Output will vary based on actual input values.>
 
 
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main( )
{
    const double PI = 3.141592;     //value for PI
    
    double diameter,    //value of a line between sides in a sphere
           radius,      //line value from the center to the outside of a sphere
           volume;      //value for the amount of space the sphere occupies
    
    cout << "Enter the diameter of the sphere in inches: ";
    cin >> diameter;
    cout << endl << endl;
    
    //Function documentation block?
    
    radius = diameter / 2.0;
    volume = 4 / 3.0 * PI * pow ( radius, 3.0 );
    
    cout << "Zane Saul" << endl
         << "C.S.1428.751" << endl
         << "Lab Section: L52" << endl
         << "07/17/2017" << endl << endl;
    
    cout << fixed << setprecision(1);
    
    cout << "A Sphere with a diameter of " << diameter <<
    " inches will have a radius of " << radius << " inches and a volume of "
    << volume << " inches cubed." << endl; //endl placed specificly for xcode
    
    system("PAUSE>NUL");
    return 0;
}
