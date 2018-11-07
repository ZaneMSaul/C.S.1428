/*
 File: prog4_zms24_kr1388_als274.cpp  
 
 Author: Zane Saul, Kevin Rodriguez, Austin St. Clair      
 C.S.1428.751
 Lab Section: L52,L52,L51
 Program: #4
 Due Date: 07/28/17
 
 This program reads the sides of a triangle in inches (real) from an input
 file, calculates the perimeter and area of the triangle and prints the
 input values plus the calculated values to an output file. An additional
 note is included when the triangle is an equilateral triangle. After all
 calculations are performed, the user is informed of the filename to which
 the output has been written.
 
 Input:
 The first line on the input file contains one integer value indicating
 the number of records (triangles) to process. Each subsequent line
 (record) contains three real values separated by spaces (the sides of a
 triangle). A count loop is used to process each record.
 
 The program processes as follows:
 
 - The author's personal identifying information is printed to the output
 file.
 - The number of records (triangles) to be processed is read from the
 input file.
 - As long as there are more records to process:
 - The sides of a triangle are read from the input file using only
 one statement.
 - The perimeter of the triangle is calculated.
 - If the sides of the triangle are equal,
 - The area of the equilateral triangle is calculated.
 - An appropriate message indicating that the triangle
 processed is an equilateral triangle is written to the
 output file.
 otherwise,
 - Heron's formula is used to calculate the area of a triangle.
 (It is assumed that the angles are sufficiently large as
 not to cause instability.
 - The input values plus the calculated values are written to the
 output file.
 -	The author's personal identifying information is written to the screen.
 -	An appropriate message indicating to the user the name of the output
 file to which the results have been written is displayed on the screen.
 
 ================================================================================
 
 Area of an equilateral triangle:
 area = (s*s * sqrt(3)) / 4 ,
 here s represents the length of one side
 
 Heron's formula to calculate the area of a triangle, given three sides:
 s = perimeter / 2;
 area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
 
 Heron's formula as given above is numerically unstable for triangles
 with a very small angle. An alternative that is considered stable
 involves arranging the lengths of the sides so that: a >= b >= c and
 uses an entirely different method to compute area. However, this
 program assumes the angles are sufficiently large so that numerical
 instability is not an issue.
 
 Note:
 area = 1/2 * base * height works for a right triangle if it is known
 which of the three sides is the base and which of the three sides is
 the height. Since that is unknown for this program, Heron's formula
 must be used.
 
 Input (file - prog4_?inp.txt): num_of_records  (integer)
 side1           (double)
 side2           (double)
 side3           (double)
 
 Sample Output (file - prog4_?out.txt):
 
 Author's Name
 C.S.1428.?          // '?' represents student's lecture section number
 Lab Section: L?     // '?' represents student's lab section number
 --/--/--            // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 The triangle is an equilateral triangle. <if applicable>
 The sides of the triangle (in inches) are ?.?, ?.?, and ?.?.
 The perimeter of the triangle is ?.? inches.
 The area of the triangle is ?.? inches squared.
 <blank line>
 The sides of the triangle (in inches) are ?.?, ?.?, and ?.?.
 The perimeter of the triangle is ?.? inches.
 The area of the triangle is ?.? inches squared.
 ...
 
 Sample Output (console screen):
 
 Author's Name
 C.S.1428.?          // '?' represents student's lecture section number
 Lab Section: L?     // '?' represents student's lab section number
 --/--/--            // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 Appropriate message indicating the name of the output file.
 
 =================================================================
 
 <Output will vary based on input.>
 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main ( )
{
    int num_of_records;
    
    double side1,
           side2,
           side3,
           perimeter,
           area,
           semi_perimeter;
    
    ifstream fin;
    fin.open ("prog4_751in.txt");
    
    if ( !fin )
        {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;
        
        system("PAUSE>NUL");
        
        return 1;
        }
    
    ofstream fout;
    fout.open("prog4_751out.txt");
    
    if ( !fout )
        {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;
        
        fin.close();
        
        system("PAUSE>NUL");
        
        return 2;
        }
    fout << "Zane Saul, Kevin Rodriguez, Austin St. Clair" << endl
         << "C.S.1428.751" << endl
         << "Lab Section: L52, L52, L51" << endl
         << "07/28/17" << endl << endl << endl;
    
    fin >> num_of_records;
    
    for ( int record = 1; record <= num_of_records; record++)
        {
            fin >> side1 >> side2 >> side3;
            
            perimeter = side1 + side2 + side3;
            
            if ( side1 == side2 && side2 == side3)
                {
                    area = ( pow( side1, 2 ) * sqrt ( 3 ) ) / 4;
                    
                    fout << "The triangle is an equilateral triangle." << endl;
                }
            else
                {
                    semi_perimeter = perimeter / 2;
                    
                    area = sqrt ( semi_perimeter * ( semi_perimeter - side1) *
                                ( semi_perimeter - side2 ) * ( semi_perimeter -
                                side3 ) );
                }
            fout << fixed << setprecision(1);
            
            fout << "The sides of the triangle (in inches) are "
                 << side1 << ", " << side2 << ", and " << side3 << "."
                 << endl
                 << "The perimeter of the triangle is " << perimeter
                 << " inches." << endl
                 << "The area of the triangle is " << area << " inches "
                 << "squared." << endl << endl;
        }
    cout << "Zane Saul, Kevin Rodriguez, Austin St. Clair" << endl
         << "C.S.1428.751" << endl
         << "Lab Section: L52, L52, L51" << endl
         << "07/28/17" << endl << endl << endl;
    
    cout << "The triangle report has been written to prog4_751out.txt." << endl;
    
    fin.close();
    fout.close();
    
    cout << endl;
    
    system("PAUSE>NUL");
    
    return 1;
}
