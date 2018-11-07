/*
 File: prog5_jhd35_jae90_zms24.cpp
 
 Author: Joseph Dillard, Justin Eccles, Zane Saul
 C.S.1428.751
 Lab Section: L52, L51, L52
 Program: #5
 Due Date: 08/02/17
 
 This program reads the sides of a triangle in inches from an input file,
 allowing for real input. It then calculates the perimeter and area of the
 triangle. It prints the sides of the triangle and the calculated perimeter
 and area to an output file. It also indicates when the triangle being
 processed is an equilateral triangle.
 
 An appropriate message is written to the screen informing the user of
 the output file name to which the results have been written. The layout
 and content of the output are shown in the samples below.
 
 Note: An appropriate message is displayed to the screen if either the
 input file or the output file fails to open.
 
 Input:
 Each line (record) on the input file contains three real values separated
 by spaces (the sides of a triangle.) Once a negative value for any or all
 of the three sides is read, processing stops.
 
 Processing:
 A sentinel value read loop & functions are used to process the data as
 follows:
 
 A function is called to print to the output file the author's personal
 identifying information.
 A function is called to read from the input file the first record (triangle.)
 
 As long as there are records to process:
 A function is called to calculate the perimeter of the triangle
 currently being processed.
 If the sides of the triangle currently being processed are equal,
 A function is called to calculate the area of the equilateral
 triangle.
 A function is called to write a message to the output file
 indicating that the triangle being processed is equilateral.
 Otherwise,
 A function is called which uses Heron's formula to calculate
 the area of the triangle currently being processed.
 A function is called to print to the output file in sentence form
 the input values plus the calculated values.
 The read function is called to read from the input file the second
 and subsequent records (triangles.)
 
 A function is called to print to the screen the author's personal
 identifying information.
 A function is called to print to the screen an appropriate sentence letting
 the user know the name of the data file to which the triangle report has
 been written.
 
 Note: If the first record contains the sentinel value, only the author's
 personal identifying information will appear in the output file.
 
 ==============================================================================
 
 Function definitions included are described below:
 
 1) The void function printIdInfo prints the author's personal information
 (name, class/section number, lab section number, due date) on the first,
 second, third and fourth lines of the output location. printIdInfo prints
 two blank lines after the due date. The output is directed to the output
 file or to the screen depending on the call.
 e.g.   Author's Name
 C.S.1428.?          // '?' represents author's lecture section number
 Lab Section: L?     // '?' represents author's lab section number
 --/--/--            // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 2) The void function readData uses only one read statement to "get" the values
 on each record from an input file - the sides of a triangle.
 3) The typed function calcPerimeterTriangle calculates the perimeter of a
 triangle.
 4) The void function printIsEquilateralMsg writes a message to the output file
 indicating the triangle being processed is an equilateral triangle.
 5) The typed function calcAreaEquilateral calculates the area of an equilateral
 triangle.
 6) The typed function calcAreaTriangle using Heron's formula calculates the
 area of a triangle. (calcAreaTriangle calls calcPerimeterTriangle to
 calculate perimeter.)
 7) The void function printResults prints to the output file in sentence form
 the input values plus the calculated values. Numeric data is displayed to
 one decimal place.
 8) The void function printFileNotification prints to the screen a statement
 letting the user know the name of the data file to which the triangle
 report has been written.
 
 Note: Only the area of a triangle is calculated in the functions that
 calculate area.
 
 ==============================================================================
 
 Each function definition is properly documented.
 
 ==============================================================================
 
 Area of an equilateral triangle:
 area = (s^2 * sqrt(3)) / 4 , here s represents the length of 1 side
 
 Heron's formula to calculate the area of a triangle, given the three
 sides (here calcPerimeterTriangle is a function that calculates the
 perimeter of the triangle):
 
 s = calcPerimeterTriangle (side1, side2, side3) / 2;
 area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
 
 Note: Heron's formula as given above is numerically unstable for triangles
 with a very small angle. An alternative that is considered stable involves
 arranging the lengths of the sides so that: a >= b >= c and using a
 completely different formula than that given above. (See specifications.)
 
 Note: For the purpose of this assignment, the angles of the triangles are
 assumed to be sufficiently large so that numerical instability is not an
 issue. Therefore, the sides of the triangle as listed in the input file
 are NOT reordered, and the version of Heron's formula given above is
 used in calculation.
 
 Note: area = 1/2 * base * height works for a right triangle if you know
 which of the three sides is the base and which of the three sides is the
 height which is unknown for this programming assignment, and there is no
 guarantee input will be a right triangle.
 
 Input (file - prog5_751inp.txt): 3 sides of a triangle ( reals )
 
 Constants: none
 
 Output (screen):
 Author's Name
 C.S.1428.?        // '?' represents author's lecture section number
 Lab Section: L?   // '?' represents author's lab section number
 --/--/--          // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 <Appropriate message indicating the name of the output file.>
 
 Output (file - prog5_751out.txt):
 Sample file output:
 
 Author's Name
 C.S.1428.?        // '?' represents author's lecture section number
 Lab Section: L?   // '?' represents author's lab section number
 --/--/--          // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 The sides of the triangle (in inches) are ?.?, ?.?, and ?.?.
 The perimeter of the triangle is ?.? inches.
 The area of the triangle is ?.? inches squared.
 <blank line>
 The sides of the triangle (in inches) are ?.?, ?.?, and ?.?.
 The perimeter of the triangle is ?.? inches.
 The area of the triangle is ?.? inches squared.
 
 ...
 
 Note: If the first record contains the sentinel value, only the author's
 personal identifying information will appear in the output file.
 
 ==========================================================================
 
 <Output will vary based on input values.>
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void printIdInfo (ostream &);
void readData ( ifstream &, double &, double &, double &);
double calcPerimeterTriangle ( double , double , double );
double calcAreaEquilateral ( double );
void printIsEquilateralMsg ( ofstream & );
double calcAreaTriangle ( double, double, double, double );
void printResults ( ofstream &, double, double, double, double, double );
void printFileNotification ( );

int main( )
{
    double semi_perimeter = 0.0,              // semiperimeter
           side1,
           side2,
           side3,
           perimeter = 0,
           area = 0;
    
    ifstream fin;
    fin.open("prog5_751inp.txt");
    
    if ( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;
        
        system("PAUSE>NUL");
        
        return 1;
    }
    
    ofstream fout;
    fout.open("prog5_751out.txt");
    
    if ( !fout )
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;
        
        fin.close();
        
        system("PAUSE>NUL");
        
        return 2;
    }
    
    printIdInfo ( fout );
    
    readData ( fin, side1, side2, side3 );
    
    fout << fixed << setprecision(1);
    
    while ( side1 > 0 && side2 > 0 && side3 > 0 )
    {
        perimeter = calcPerimeterTriangle ( side1, side2, side3 );
        
        if ( side1 == side2 &&  side2 == side3 )
        {
            area = calcAreaEquilateral ( side1 );
            
            printIsEquilateralMsg ( fout );
        }
        else
        {
            area = calcAreaTriangle ( side1, side2, side3, semi_perimeter );
        }
        
        printResults ( fout, side1, side2, side3, perimeter, area );
        
        readData ( fin, side1, side2, side3 );
    }
    
    printIdInfo ( cout );
    
    printFileNotification ( );
    
    fin.close( );
    
    fout.close( );
    
    system("PAUSE>NUL");
    
    return EXIT_SUCCESS;
    
}

/*
 Function: printIdInfo
 
 The function, printIdInfo, prints the authorís personal information (name,
 class/section number, lab section number, due date) on the first, second, third
 and fourth lines of the output. printIdInfo prints two blank lines after the 
 due date. The output is directed to the output file or to the screen depending 
 on the call.
 
 Recieves: Nothing.
 Constants: None.
 Returns: Nothing; prints author's identifying information.
 */

void printIdInfo ( ostream &out)
{
    out << "Joseph Dillard, Justin Eccles, Zane Saul" << endl
        << "C.S.1428.751" << endl
        << "Lab Section: L52, L51, L52" << endl
        << "08/02/17" << endl << endl << endl;
}

/*
 Function: readData
 
 The function, readData, uses only one read statement to "get" the values on 
 each record from an input file - the sides of a triangle.
 
 Recieves: side1 (double), side2 (double), side3 (double)
 Constants: None.
 Returns: Nothing.
 double calcAreaEquilateral ( side1 )
 */
void readData ( ifstream &fin, double &side1, double &side2, double &side3)
{
    fin >> side1 >> side2 >> side3;
}

/*
 Function: calcPerimeterTriangle
 
 The function,
 
 Receives: side1 (double), side2 (double), side3 (double)
 Constants: None.
 Returns: perimter
 */

double calcPerimeterTriangle ( double side1, double side2, double side3)
{
    double perimeter,
           semi_perimeter;
    
    perimeter = side1 + side2 + side3;
    
    semi_perimeter = perimeter / 2;
    
    return perimeter;
    
    return semi_perimeter;
}

/*
 Function: calcAreaEquilateral
 
 The function,calcAreaEquilateral, calculates the area of an equilateral
 triangle.
 
 Receives: side1 (double)
 Constants: None.
 Returns: area
 */

double calcAreaEquilateral ( double side1 )
{
    double area;
    
    area = ( pow( side1, 2 ) * sqrt( 3 )) / 4;
    
    return area;
}

/*
 Function: printIsEquilateralMsg
 
 The function, printIsEquilateralMsg, writes a message to the output file
 indicating that the triangle being processed is an equilateral triangle.
 
 Receives: Nothing.
 Constants: None.
 Returns: Nothing; prints a message that the triangle is equilateral to the 
 file.
 */

void printIsEquilateralMsg ( ofstream &fout )
{
    fout << "The triangle is an equilateral triangle." << endl;
}

/*
 Function: calcAreaTriangle
 
 The function, calcAreaTriangle using Heronís formula calculates the area of a
 triangle.
 
 Receives: side1 (double), side2 (double), side3 (double)
 Constants: None.
 Returns: area
 */

double calcAreaTriangle ( double semi_perimeter, double side1, double side2,
                         double side3)
{
    double  area;
    
    area = sqrt(semi_perimeter * (semi_perimeter - side1) *
                (semi_perimeter - side2) * (semi_perimeter - side3));
    
    return area;
}

/*
 Function: printResults
 
 The function, printResults, prints to the output file in sentence form the 
 input values plus the calculated values.
 
 Recieves: side1 (double), side2 (double), side3 (double), perimeter (double)
 area (double)
 Constants: None.
 Returns: Nothing; prints results of trinagle report.
 */

void printResults ( ofstream &fout, double side1, double side2, double side3,
                   double perimeter, double area )
{
    fout << "The sides of the triangle (in inches) are " << side1 << ", "
         << side2 << ", and " << side3 << "." << endl
         << "The perimeter of the triangle is " << perimeter << " inches."
         << endl
         << "The area of the triangle is " << area << " inches squared."
         << endl << endl;
}

/*
 Function: printFileNotification
 
 The function, printFileNotification prints to the screen a statement letting
 the user know the name of the data file to which the triangle report has been
 written.
 
 Receives: Nothing.
 Constants: None.
 Returns: Nothing; prints the location of the triangle report.
 */

void printFileNotification ( )
{
    cout << "The triangle report has been written to prog5_751out.txt."
         << endl;
}
