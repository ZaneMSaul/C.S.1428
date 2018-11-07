/*
 File: prog3_zms24_als274.cpp
 
 Author: Zane Saul, Austin St. Clair
 C.S.1428.751
 Lab Section: L52, 51
 Program: #3
 Due Date: 07/20/17
 
 This program displays a menu of four geometry calculator options along
 with a prompt for the user to enter his/her menu choice. (See layout
 below.)
 
 Geometry Calculator
 1.  Calculate the surface area of a cube.
 2.  Calculate the surface area of a sphere.
 3.  Calculate the surface area of a cylinder.
 4.  Calculate the surface area of a rectangular prism.
 5.  Quit
 
 Enter your choice ( 1 - 5 ):
 
 ==========================================================================
 If the user enters 1, the program prompts for the length of one side of
 a cube. The length and the calculated surface area of the cube are then
 displayed on the screen.
 surface area of a cube = 6aa,
 where a is the length of the side of each edge of the cube.
 
 If the user enters 2, the program prompts for the radius of a sphere.
 The radius and the calculated surface area of the sphere are then
 displayed on the screen.
 surface area of a sphere = 4PIrr,
 where r is the radius of the sphere.
 
 If the user enters 3, the program prompts for the radius of the base
 of a cylinder and the height of the cylinder. The radius, height and
 calculated surface area of the cylinder are then displayed on the screen.
 surface area of a cylinder = 2PIrr + 2PIrh,
 where r is the radius of the base of the cylinder and
 h is the height of the cylinder.
 
 If the user enters 4, the program prompts for the lengths of the three
 sides of a rectangular prism. The three input values and the calculated
 surface area of the rectangular prism are then displayed on the screen.
 surface area of a rectangular prism = 2ab + 2bc + 2ac,
 where a, b, and c are the lengths of the 3 sides.
 
 If the user enters the maximum menu choice, the program will terminate
 after displaying an appropriate message on the screen.
 
 Notes:
 - With the exception of the menu choices, all input data are real and
 measured in inches.
 - The order of operands in all standard formulas is maintained.
 - No single letter variable names are used in standard formulas.
 - 3.14159 is used for the value of PI.
 - The pow function is used for calculations involving exponentiation.
 - A named constant is used to represent the maximum menu choice to
 allow expansion of the menu options.
 - The author's identifying information is displayed on the first four
 lines of the console screen followed by two blank lines and the
 display of the geometric calculator menu.
 - Two blank lines are left before the first prompt in each case and
 again before any output message displayed on the screen.
 - All output values are appropriately labeled either by use of
 descriptive terms or by including them in complete sentence form.
 - Calculated results are displayed to two decimal places.
 
 Input validation is limited to the following situations:
 1) If the user enters a number outside the range of 1-MAX_CHOICE when
 selecting a menu item, an appropriate error message is displayed on
 the screen.
 2) If the user fails to enter a value greater than zero for the
 requested input values (length(s), radius, height), an appropriate
 error message is displayed on the screen.
 3) In the event that erroneous input is entered as in #1 or #2 above,
 the user is not prompted again to enter correct input. The program
 simply terminates after a message appropriate to the situation is
 displayed on the screen.
 
 Input (keyboard): menu choice - integer
 side length (cube) - double
 radius (sphere or cylinder base) - double
 height (cylinder) - double
 length, width, height (rectangular prism) - double
 
 Constants: PI = 3.14159 (double)
 MAX_CHOICE (integer)       // last menu choice
 
 Sample Console Screen:
 
 Author's Name
 C.S.1428.?          // '?' represents student's lecture section number
 Lab Section: L?     // '?' represents student's lab section number
 --/--/--            // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 Geometry Calculator
 1.	Calculate the surface area of a cube.
 2.	Calculate the surface area of a sphere.
 3.	Calculate the surface area of a cylinder.
 4.	Calculate the surface area of a rectangular prism.
 5.	Quit
 <blank line>
 Enter your choice ( 1 - 5 ):
 <blank line>
 <blank line>
 Prompt(s)...
 <blank line>
 <blank line>
 Display of the input value(s) needed to determine the surface area
 of the geometric figure and the calculated surface area of the figure
 either appropriately labeled or in sentence form.
 
 =================================================================
 
 <Output will vary based on input.>
 
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main ( )
{
    const int MAX_CHOICE = 5;
    
    const double PI = 3.14159;
    
    int menu_choice;
    
    double surface_area,
           length,
           height,
           width,
           radius;
    
    cout << "Zane Saul, Austin St. Clair" << endl
         << "C.S.1428.751" << endl
         << "Lab Section: 52, 51" << endl
         << "07/20/17" << endl << endl << endl;
    
    cout << "Geometry Calculator" << endl
         << right << setw(45) << "1. Calculate the surface area of a cube."
         << endl
         << right << setw(47) << "2. Calculate the surface area of a sphere."
         << endl
         << right << setw(49) << "3. Calculate the surface area of a cylinder."
         << endl
         << right << setw(40) << "4. Calculate the surface area of a "
         << "rectangular prism." << endl
         << right << setw(6) << MAX_CHOICE << ". Quit" << endl << endl
         << "Enter your choice ( 1 - 5 ): ";
    
    cin >> menu_choice;
    
    cout << endl << endl;
    if ( menu_choice < 1 || menu_choice > MAX_CHOICE )
        cout << "You entered, enter a value 1 through " << MAX_CHOICE
             << ", program terminated.";
    else
        {
        switch ( menu_choice )
            {
                case 1:
                    cout << "Enter the length of one side of a cube"
                         << " <in inches>: ";
                    cin >> length;
            
                    if( length <= 0 )
                        cout << endl << endl
                             << "You entered " << length << ", enter a value "
                             << "greater than 0, program terminated.";
                    else
                        {
                            surface_area = 6 * pow ( length, 2 );
                
                            cout << endl << endl
                                 << "A cube whose length is "
                                 << length << " inch(es) has a surface area of "
                                 << fixed << setprecision(2) << surface_area
                                 << " inch(es) squared.";
                        }
                        break;
                case 2:
                    cout << "Enter the radius for a sphere <in inches>: ";
                    cin >> radius;
                    if( radius <= 0 )
                        cout << endl << endl
                             << "You entered " << radius << ", enter a value"
                             << " greater than 0, Program terminated";
                    else
                        {
                            surface_area = 4 * PI * pow ( radius, 2 );
                
                            cout << endl << endl
                                 << "The surface area of a sphere whose radius "
                                 << "is " << radius << " inch(es) is " <<  fixed
                                 << setprecision(2) << surface_area
                                 << " inch(es) squared.";
                        }
                    break;
                case 3:
                    cout << "Enter the radius of a cylinder's base"
                         << " <in inches>: ";
                    cin >> radius;
            
                    if( radius <= 0 )
                        cout << endl << endl
                             << "You entered " << radius << ", enter a value"
                             << " greater than 0, Program terminated";
                    else
                        {
                            cout << endl
                                 << "Enter the height of the cylinder "
                                 << "<in inches>: ";
                            cin >> height;
                
                            if( height <= 0 )
                                cout << endl << endl
                                     << "You entered " << height << ", enter a"
                                     << " value greater than 0, Program "
                                     << "terminated";
                            else
                                {
                                    surface_area = ( 2 * PI * pow ( radius, 2 )
                                                   ) + ( 2 * PI * radius *
                                                   height );
                
                                    cout << endl << endl
                                         << "The surface area of a cylinder"
                                         << " whose base has a radius of "
                                         << radius << " inch(es) and a height"
                                         << " of " << height << " inch(es) is "
                                         <<  fixed << setprecision(2)
                                         << surface_area
                                         << " inch(es) squared.";
                                }
                        }
                    break;
                case 4:
                    cout << "Enter the length of a rectangular prism"
                         << " <in inches>: ";
                    cin >> length;
            
                    cout << endl
                         << "Enter the width of a rectangular prism "
                         << "<in inches>: ";
                    cin >> width;
            
                    cout << endl
                         << "Enter the height of a rectangular prism "
                         << "<in inches>: ";
                    cin >> height;
            
                    if( length <= 0 || width <= 0 || height <= 0 )
                        cout << endl << endl
                             << "You entered " << length << " for length, "
                             << width << " for width and " << height << " for "
                             << "height. Enter values greater than 0, "
                             << "Program terminated";
                    else
                    {
                        surface_area = ( 2 * length * width ) + ( 2 * length *
                                       height ) + ( 2 * width * height );
                
                        cout << endl << endl
                             << "A rectangle whose length is " << length
                             << " inch(es), width is " << width << " inch(es), "
                             << "and height is " << height << " inch(es) has a"
                             << " surface" << " area of " <<  fixed
                             << setprecision(2) << surface_area
                             << " inch(es) squared.";
                    }
                    break;
            
                case MAX_CHOICE:
                    cout << "Program terminated";
            }
        }
    cout << endl;
    
    system("PAUSE>NUL");
    
    return 0;
}
