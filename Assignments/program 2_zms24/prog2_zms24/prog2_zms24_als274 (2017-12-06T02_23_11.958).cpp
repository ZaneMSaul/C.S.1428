/*
 File: prog2_zms24_als274.cpp

 Author: Zane Saul, Austin St. Clair
 C.S.1428.751
 Lab Section: L52, L51
 Program: #2
 Due Date: 07/18/17

 This program uses one statement to read the radius of a sphere and the
 height of a cylinder (in inches) from an input file, allowing for real
 input data. It then calculates the surface area of the sphere and the
 surface area of the cylinder.

 The author's identifying information plus the radius of the sphere and
 the height of the cylinder along with the calculated surface areas are
 written to an output file in sentence form. Numeric output values are
 displayed to two decimal places. Layout and content of the output file
 are shown in the sample below.

 The author's identifying information plus an appropriate message
 informing the user of the output file name to which the results have
 been written are displayed on the console screen. Layout and content
 of the screen output are shown in the sample below.

 An appropriate message is displayed to the screen if there is a problem
 opening either the input file or the output file.

 Input (file - prog2_751inp.txt):
 radius in inches (same value used for sphere & cylinder), double
 height (cylinder) in inches, double

 Constants: PI = 3.141592 (double)

 Sample Console Output:

 Output (screen):
 Author's Name
 C.S.1428.?          // '?' represents student's lecture section #
 Lab Section: L?     // '?' represents student's lab section #
 --/--/--            // dashes represent due date, month/day/year
 <blank line>
 <Appropriate message indicating the name of the output file.>

 Sample File Output;

 Output (file - prog2_751out.txt):
 Author's Name
 C.S.1428.?          // '?' represents student's lecture section #
 Lab Section: L?     // '?' represents student's lab section #
 --/--/--            // dashes represent due date, month/day/year
 <blank line>
 The surface area of a sphere with a radius
 of ?.?? inches is ?.?? inches squared.
 <blank line>
 The surface area of a cylinder with
 a radius of ?.?? inches and a height
 of ?.?? inches is ?.?? inches squared.

 ================================================

 <Output will vary based on actual input values.>

 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main ( )
{
    const double PI = 3.141592;

    double radius,
           height,
           sphere_surface_area,
           cylinder_surface_area;

    ifstream fin;
    fin.open("prog2_751inp.txt");

    if ( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        return 1;
    }

    ofstream fout;
    fout.open("prog2_751out.txt");

    if ( !fout )
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;

        fin.close();

        return 2;
    }

    fin >> radius >> height;

    sphere_surface_area = 4 * PI * pow(radius,2);
    cylinder_surface_area = ( 2 * PI * pow(radius, 2) )
            + ( 2 * PI * radius * height );

    fout << "Zane Saul, Austin St. Clair" << endl
         << "C.S.1428.751" << endl
         << "Lab Section: L52, L51" << endl
         << "07/20/17" << endl << endl;

    fout << fixed << setprecision(2)
         << "The surface area of a sphere with a radius" << endl
         << "of " << radius << " inches is " << sphere_surface_area
         << " inches squared." << endl << endl
         << "The surface area of a cylinder with" << endl
         << "a radius of " << radius << " inches and a height" << endl
         << "of " << height << " inches is " << cylinder_surface_area
         << " inches squared.";

    cout << "Zane Saul, Austin St. Clair" << endl
         << "C.S.1428.751" << endl
         << "Lab Section: L52, L51" << endl
         << "07/20/17" << endl << endl;

    cout << "The surface area report has been written to prog2_751out.txt."
         << endl;

    fin.close();
    fout.close();

    system("PAUSE>NUL");

    return 0;
}
