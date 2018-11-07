/*
 File: prog6_jhd35_jae90_zms24.cpp
 
 Author: Joseph Dillard, Justin Eccles, Zane Saul
 C.S.1428.751
 Lab Section: L52, L51, L52
 Program: #6
 Due Date: 08/07/17
 
 =======================================================================
 
 Two common temperature scales are the Fahrenheit and Celsius scales.
 The boiling point of water is 212 degrees on the Fahrenheit scale and
 100 degrees on the Celsius scale. The freezing point of water is
 32 degrees on the Fahrenheit scale and 0 degrees on the Celsius scale.
 The relationship between the two temperature scales is C = 5/9 * (F - 32).
 
 Rankine [rang-kin] is an absolute temperature scale used by engineers.
 The Rankine degree intervals are equal to those of the Fahrenheit
 temperature scale where 0 degrees Rankine is equal to -459.67 degrees
 Fahrenheit. The two reference temperatures for Fahrenheit, the freezing
 point of water (32 degrees Fahrenheit) and the boiling point of water
 (212 degrees Fahrenheit), correspond to 491.67 degrees Rankine and
 671.67 degrees Rankine, respectively. Add 459.67 to a Fahrenheit
 temperature to get the corresponding Rankine temperature.
 
 Kelvin is another absolute temperature scale more commonly used for
 scientific measure. The Kelvin degree intervals are equal to those of
 the Celsius degree. The two reference temperatures for Celsius, the
 freezing point of water (0 degrees Celsius) and the boiling point of
 water (100 degrees Celsius), correspond to 273.15K and 373.15K,
 respectively. (Note: When writing temperatures in the Kelvin scale, it
 is convention to omit the degree symbol and use the letter K instead.)
 Add 273.15 to a Celsius temperature to get the corresponding Kelvin
 temperature.
 
 =======================================================================
 
 This program uses two parallel arrays, a 1-D array that holds at most
 five integer Fahrenheit temperatures & a 2-D array that holds the
 corresponding Celsius, Rankine, and Kelvin temperatures (reals).
 
 The Fahrenheit temperatures are read from an input file into a 1-D
 array. The corresponding Celsius temperature for each Fahrenheit
 temperature is calculated, and each Celsius temperature is stored
 in the first column of the 2-D array. The corresponding Rankine
 temperature for each Fahrenheit temperature is calculated, and each
 Rankine temperature is stored in the second column of the 2-D array.
 The Kelvin temperature corresponding to each calculated Celsius
 temperature is calculated, and each Kelvin temperature is stored in
 the third column of the 2-D array.
 
 A table with a title and appropriate column headers is printed to the
 output file displaing the Fahrenheit, Celsius, Rankine, and Kelvin
 temperatures, in this order.
 
 An appropriate message is written to the screen informing the user
 of the output file name to which the results have been written. The
 layout and content of the output are shown in the samples below.
 
 Note: An appropriate message is displayed to the screen if either
 the input file or the output file fails to open.
 
 Input:
 prog6_751inp.txt contains an unknown number of Fahrenheit temperatures,
 one per line. The input file is assumed to contain valid input values.
 
 Processing: (If possible, arrays are "protected" when passed to
 functions.)
 
 Function definitions included are described below:
 
 - A function printIdInfo is called to print the authors' personal information
 (names, class/section number, lab section number, due date) on the first,
 second, third and fourth lines of output. printIdInfo prints two blank lines
 after the due date. The output is directed to a file or to the screen
 depending on the call.
 e.g  Authors' Names
 C.S.1428.?         // '?' represents three digit lecture section #
 Lab Section: L?    // '?' represents two digit lab section #
 --/--/--           // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 - A function printReportHeader is called to print to the output file
 an appropriate title and column headers for a temperature conversion
 report.
 - A function readFahrenheitTemperatures is called to read five
 Fahrenheit temperatures from the input file into a 1-D array.
 - A function convertFahrenheit2Celsius is called to convert the
 Fahrenheit temperatures in the integer array to the corresponding
 Celsius temperatures, storing the Celsius temperatures in the first
 column of the 2-D array.
 - A function convertFahrenheit2Rankine is called to convert the
 Fahrenheit temperatures in the integer array to the corresponding
 Rankine temperatures, storing the Rankine temperatures in the second
 column of the 2-D array.
 - A function convertCelsius2Kelvin is called to convert the calculated
 Celsius temperatures in the 2-D array to the corresponding Kelvin
 temperatures, storing the Kelvin temperatures in the third column
 of the 2-D array.
 - A function printTemperatureConversionTable is called to print to the
 output file the Fahrenheit, Celsius, Rankine, and Kelvin temperatures
 under the appropriate column headers.
 - A function printFileNotification is called to print an appropriate
 message to the screen indicating to the user the name of the output
 file to which the results have been written.
 
 =======================================================================
 
 Input (file - prog6_?inp.txt): fahrenheit temperatures (integer)
 
 Constants: Global:
 ROWS(number of rows in parallel arrays)
 COLS(number of columns in the 2-D array)
 CEL (column in which Celsius temperatures are stored)
 RAN (column in which Rankine temperatures are stored)
 KEL (column in which Kelvin temperatures are stored)
 KELVIN(conversion value used)
 RANKINE(conversion value used)
 Local:
 PLACES(display calculated results to this many places)
 
 Sample Output (file - prog6_?out.txt):
 File output template (spacing between columns may vary slightly):
 
 Authors' Names
 C.S.1428.?         // '?' represents current lecture section #
 Lab Section: L?    // '?' represents two digit lab section #
 --/--/--           // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 Temperature Conversion Table
 
 Fahrenheit      Celsius        Rankine      Kelvin
 --------------------------------------------------
 212          100.00         671.67      373.15
 32            0.00           ?.??        ?.??
 ...
 
 (Calculated results are formatted to two decimal places.)
 
 Output (screen):
 
 Authors' Names
 C.S.1428.?         // '?' represents current lecture section #
 Lab Section: L?    // '?' represents two digit lab section #
 --/--/--           // dashes represent due date, month/day/year
 <blank line>
 <blank line>
 <Appropriate message indicating the name of the output file.>
 
 ==================================================================
 
 <Output will vary based on input values.>
 
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int ROWS = 5,      // number of Fahrenheit temperatures
          COLS = 3;      // number of converted temperature scales

const int CEL = 0,       // column in which Celsius temperatures are stored
          RAN = 1,       // column in which Rankine temperatures are stored
          KEL = 2;       // column in which Kelvin temperatures are stored

const double KELVIN = 273.15,
             RANKINE = 459.67;

void printIdInfo( ostream &, const string, const int, const string );
void printReportHeader( ofstream & );
void readFahrenheitTemperatures( ifstream &, int [ ] );
void convertFahrenheit2Celsius( int[ ], double[ ][COLS] );
void convertFahrenheit2Rankine( int[ ], double[ ][COLS] );
void convertCelsius2Kelvin( double[ ][COLS] );
void printTemperatureConversionTable( ofstream &, int[ ], double[ ][COLS],
                                     const int );
void printIdInfo( const string, const int, const string );
void printFileNotification( char[ ] );


int main( )
{
    const string AUTHORS = "Joseph Dillard, Justin Eccles, Zane Saul",
                 DUE_DATE = "08/07/17";
    
    const int SECTION = 751,
              MAX_LENGTH_FN = 20;
    
    char input_filename[MAX_LENGTH_FN + 1] = "prog6_751inp.txt",
         output_filename[MAX_LENGTH_FN + 1] = "prog6_751out.txt";
    
    const int PLACES = 2;            // number of decimal places to display
    
    int fahrenheit[ROWS];            // Fahrenheit temperatures
    double conversions[ROWS][COLS];  // stores Celsius, Rankine, Kelvin
    
    ifstream fin;
    fin.open( input_filename );
    
    if( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;
        
        return 1;
    }
    
    ofstream fout;
    fout.open( output_filename );
    
    if( !fout )
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;
        
        fin.close( );
        
        return 2;
    }
    
    printIdInfo( fout, AUTHORS, SECTION, DUE_DATE );
    printReportHeader( fout );
    readFahrenheitTemperatures( fin, fahrenheit );
    convertFahrenheit2Celsius( fahrenheit, conversions );
    convertFahrenheit2Rankine( fahrenheit, conversions );
    convertCelsius2Kelvin( conversions );
    printTemperatureConversionTable( fout, fahrenheit, conversions, PLACES );
    printIdInfo( cout, AUTHORS, SECTION, DUE_DATE );
    printFileNotification( output_filename );
    
    fin.close( );
    fout.close( );
    
    system("PAUSE>NUL");
    
    return EXIT_SUCCESS;
}

/*
    Function: printIdInfo
 
    Author: Joseph Dillard, Justin Eccles, Zane Saul
    C.S.1428.751
    Lab Section: L52, L51, L52
    Program: #6 Function
    Due Date: 08/07/17
 
    The function, functionname, prints the authors’ personal information (name,
    class/section number, lab section number, due date) on the first, second, 
    third and fourth lines of output. printIdInfo should print two blank lines 
    after the due date.
 
    Receives: ostream &out, const string AUTHORS, const int SECTION, const 
              string DUE_DATE
    Constants: AUTHORS, SECTION, DUE_DATE
    Returns: Nothing. Prints to the output source.
 
 */

void printIdInfo( ostream &out, const string AUTHORS, const int SECTION,
                 const string DUE_DATE )
{
    out << AUTHORS << endl
        << "C.S.1428." << SECTION << endl
        << "Lab Section: L52, L51, L52" << endl
        << DUE_DATE << endl << endl << endl;
}

/*
    Function: printReportHeader
 
    Author: Joseph Dillard, Justin Eccles, Zane Saul
    C.S.1428.751
    Lab Section: L52, L51, L52
    Program: #6 Function
    Due Date: 08/07/17
 
            Temperature Conversion Table
 
    Fahrenheit      Celsius        Rankine      Kelvin
    --------------------------------------------------
        212          100.00         671.67      373.15
         32            0.00           ?.??        ?.??
    ...
 
    (Calculated results are formatted to two decimal places.)
 
    The function, printReportHeader, is called to print to the output file
    an appropriate title and column headers for a temperature conversion
    report.
 
    Receives: ofstream &fout
    Constants: None.
    Returns: Nothing. Prints to the output file.
 */

void printReportHeader( ofstream &fout )
{
    fout << "        Temperature Conversion Table" << endl << endl
         << "Fahrenheit  Celsius     Rankine      Kelvin" << endl
         << "-------------------------------------------" << endl;
}

/*
    Function: readFahrenheitTemperatures
 
    Author: Joseph Dillard, Justin Eccles, Zane Saul
    C.S.1428.751
    Lab Section: L52, L51, L52
    Program: #6 Function
    Due Date: 08/07/17
 
    The function, readFahrenheitTemperatures, is called to read five
    Fahrenheit temperatures from the input file into a 1-D array.
 
    Receives: ifstream &fin, int fahrenheit[ ]
    Constants: global const int ROWS
    Returns: fahrenheit[ ]
 */

void readFahrenheitTemperatures( ifstream &fin, int fahrenheit[ ] )
{
    for( int i = 0; i < ROWS; ++i )
        fin >> fahrenheit[i];
}

/*
    Function: convertFahrenheit2Celsius
    
    Author: Joseph Dillard, Justin Eccles, Zane Saul
    C.S.1428.751
    Lab Section: L52, L51, L52
    Program: #6 Function
    Due Date: 08/07/17
 
    The function, convertFahrenheit2Celsius, is called to convert the
    Fahrenheit temperatures in the integer array to the corresponding
    Celsius temperatures, storing the Celsius temperatures in the first
    column of the 2-D array.
 
    Receives: int fahrenheit[ ], double conversions[ ][COLS]
    Constants: global const int COLS, global const int ROWS, global const int 
               CEL
    Returns: conversions[ ][CEL]
 */

void convertFahrenheit2Celsius( int fahrenheit[ ], double conversions[ ][COLS] )
{
    for( int i = 0; i < ROWS; ++i )
        conversions[i][CEL] = ( 5.0 / 9.0 ) * ( fahrenheit[i] - 32 );
}

/*
    Function: convertFahrenheit2Rankine
 
    Author: Joseph Dillard, Justin Eccles, Zane Saul
    C.S.1428.751
    Lab Section: L52, L51, L52
    Program: #6 Function
    Due Date: 08/07/17
 
    The function, convertFahrenheit2Rankine,  is called to convert the
    Fahrenheit temperatures in the integer array to the corresponding
    Rankine temperatures, storing the Rankine temperatures in the second
    column of the 2-D array.
 
    Receives: int fahrenheit[ ], double conversions[ ][COLS]
    Constants: global const int COLS, global const int ROWS, global const int 
               RAN, global const double RANKINE
    Returns: conversions[ ][RAN]
 */

void convertFahrenheit2Rankine( int fahrenheit[ ], double conversions[ ][COLS] )
{
    for( int i = 0; i < ROWS; ++i )
        conversions[i][RAN] = fahrenheit[i] + RANKINE;
}

/*
    Function: convertCelsius2Kelvin
 
    Author: Joseph Dillard, Justin Eccles, Zane Saul
    C.S.1428.751
    Lab Section: L52, L51, L52
    Program: #6 Function
    Due Date: 08/07/17
 
    The function, convertCelsius2Kelvin, is called to convert the calculated
    Celsius temperatures in the 2-D array to the corresponding Kelvin
    temperatures, storing the Kelvin temperatures in the third column
    of the 2-D array.
 
    Receives: double conversions[ ][COLS]
    Constants: global const int COLS, global const int ROWS, global const int 
               KEL, global const double KELVIN
    Returns: conversions[ ][KEL]
 */

void convertCelsius2Kelvin( double conversions[ ][COLS] )
{
    for( int i = 0; i < ROWS; ++i )
        conversions[i][KEL] = conversions[i][1] + KELVIN;
}

/*
    Function: printTemperatureConversionTable
 
    Author: Joseph Dillard, Justin Eccles, Zane Saul
    C.S.1428.751
    Lab Section: L52, L51, L52
    Program: #6 Function
    Due Date: 08/07/17
 
    Temperature Conversion Table
 
    Fahrenheit      Celsius        Rankine      Kelvin
    --------------------------------------------------
        212          100.00         671.67      373.15
         32            0.00           ?.??        ?.??
    ...
 
    (Calculated results are formatted to two decimal places.)
 
    The function, printTemperatureConversionTable, is called to print to the
    output file the Fahrenheit, Celsius, Rankine, and Kelvin temperatures
    under the appropriate column headers.
 
    Receives: ofstream &fout, int fahrenheit[ ], double conversions[ ][COLS], 
    const int PLACES
    Constants: global const int COLS, const int PLACES, global const int ROWS,
               global const int CEL, global const int RAN, global const int KEL
    Returns: Nothing. Prints to output file.
 */

void printTemperatureConversionTable( ofstream &fout, int fahrenheit[ ],
                                     double conversions[ ][COLS],
                                     const int PLACES )
{
    fout << fixed << setprecision(PLACES);
    
    for( int i = 0; i < ROWS; ++i )
        fout << setw(7) << fahrenheit[i] << setw(12) << conversions[i][CEL]
             << setw(12) << conversions[i][RAN]
             << setw(12) << conversions[i][KEL] << endl;
}

/*
    Function: printFileNotification
 
    Author: Joseph Dillard, Justin Eccles, Zane Saul
    C.S.1428.751
    Lab Section: L52, L51, L52
    Program: #6 Function
    Due Date: 08/07/17
 
    "The processed array data has been written to prog6_?out.txt."
 
    The function, printFileNotification, is called to print an appropriate
    message to the screen indicating to the user the name of the output
    file to which the results have been written.
 
    Receives: const char output_filename[ ]
    Constants: None
    Returns: Nothing. Prints to output console.
 */

void printFileNotification( char output_filename[ ] )
{
    cout << "The processed array data has been written to " << output_filename
         << "." << endl;
}
