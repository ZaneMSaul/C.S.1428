#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

void filePrompt( ifstream &fin, bool &);
void fileCount( ifstream &, double [ ], int &, double );
void buildInput( int &, double [ ] );
void radiusArray( double [ ], int, int, double [ ] );
void calcVolume( int, int, double &, double, double [ ] );
void volumeArray( int, int, double &, double, double [ ], double [ ] );
void outputConstruct( int, double [ ] );

int main( )
{
    const double PI = 3.141592;
    
    int size = 0,
        input = 0;
    
    double radius = 0,
           volume;
    
    bool file_in = false;
    
    double input_array[size];
    double radius_array[size];
    double volume_array[size];
    
    ifstream fin;
    
    filePrompt( fin, file_in );
    if( file_in )
        fileCount( fin, input_array, size, radius );
    if( !file_in )
        buildInput( size, input_array );
    radiusArray( input_array, size, input, radius_array );
    //calcVolume( input, size, volume, PI, radius_array );
    volumeArray( input, size, volume, PI, radius_array, volume_array );
    outputConstruct( size, volume_array );
    
    cout << endl << endl;
    
    fin.close();
    
    return EXIT_SUCCESS;
}
/*
 */
void filePrompt( ifstream &fin, bool &file_in )
{
    char choice;
    
    string file_name;
    do
    {
        cout << "Would you like to extract data from a file?" << endl
         << "Enter [Y or N] : ";
        cin >> choice;
        cout << endl;
        
        if( choice != 'y' && choice != 'Y' && choice != 'N' && choice != 'n' )
            cout << "It seems there was a mistake." << endl << endl;
        
        fin.open(file_name);
        
        if( choice == 'y' || choice == 'Y' )
        {
            cout << "Enter file directory name: ";
            cin >> file_name;
            cout << endl;

            fin.open(file_name);
            file_in = true;
            
            if( !fin )
            {
                cout << "Sorry That file was not detected." << endl << endl;
                file_in = false;
            }
        }
    }while( !fin && choice != 'n' && choice != 'N' );
}
/*
 This function counts the number of file inputs
 */
void fileCount( ifstream &fin, double input_array[], int &size, double radius )
{
    do
    {
        fin >> input_array[size];
        
        cout << input_array[size] << " ";
        
        size++;
    }while( !fin.eof() );
    
    cout << endl << endl
         << "size after funtion fileCount's do while loop is: "
         << size << endl << endl;
}
/*
 */
void buildInput( int &size, double input_array[ ] )
{
    do
    {
        cout << "How many radi would like to process?" << endl;
        cin >> size;
        cout << endl;
        
        while( cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "It seems there was a mistake!" << endl << endl
                 << "How many radi would like to process?" << endl;
            cin >> size;
            
        }
        
        if( size > 0 )
        {
            cout << "Enter values: " << endl;
    
            for( int i = 0; i < size; i ++)
                cin >> input_array[i];
        }
        else
            cout << "It seems there was a mistake!" << endl << endl;

    }while( size < 0 );
}
/*
 This function builds an array to store radius in from an input data file.
 */
void radiusArray( double input_array[ ], int size, int input, double radius_array[] )
{
    input = 0;
    
    cout << "storing data to radius_array" << endl << endl;
    for( input = 0; input < size; input++ )
    {
        radius_array[input] = input_array[input];
        cout << "Array storage location " << input << " radius: "
             << radius_array[input] << endl;
    }
    if( input == size )
        cout << endl
             << "radiusArray construct complete" << endl << endl;
    cout << "input after funtion buildArray's for loop: " << input << endl
         << endl;
    

}
/*
 This funtion calculates volume based on data stored in an array
 */
void calcVolume( int input, int size, double &volume, double PI,
                double radius_array[] )
{
    input = 0;
    
    while( input < size )
    {
        volume = 4 / 3.0 * PI * pow( radius_array[input], 3.0);
        cout << "volume of a sphere with the radius " << radius_array[input++]
             << " is " << volume << endl;
    }
    cout << endl;
}

void volumeArray( int input, int size, double &volume, double PI,
                 double radius_array[], double volume_array[] )
{
    int decimal_places;
    
    input = 0;
    
    do
    {
        cout << "How many decimal places would you like volume to have?" << endl
             << "Enter an integer greater than or equal to 0: ";
        cin >> decimal_places;
        cout << endl;
        
        while( cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "It seems there was a mistake!" << endl << endl
                 << "How many decimal places would you like volume to have?" << endl
                 << "Enter an integer greater than or equal to 0: ";
            cin >> decimal_places;
        }
        if( decimal_places >= 0)
        {
            cout << fixed << setprecision(decimal_places) << endl;
    
            cout << "storing data to volume_array " << endl << endl;
    
            while( input < size )
            {
                volume = 4 / 3.0 * PI * pow( radius_array[input], 3.0);
                volume_array[input] = volume;
                cout << "Array storage location " << input << " volume: "
                     << volume_array[input++] << endl;
            }
            cout << endl
                 << "volumeArray construct complete" << endl << endl << endl;
    }
    else
        cout << "It seems there was a mistake!" << endl << endl;
    }while( decimal_places < 0 );
}

void outputConstruct( int size, double volume_array [] )
{
    int input = 0;
    
    string string_name;
    
    char choice;
    do
    {
        cout << "Would you like an output data file?" << endl
             << "[Y or N] : ";
        cin >> choice;
        cout << endl;
        
        if( choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n' )
            cout << "It seems there was a mistake!" << endl << endl;
    }while( choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n' );
    
    cout << endl;
    
    if( choice == 'Y' || choice == 'y' )
    {
        cout << "What file name would you like?" << endl;
        cin >> string_name;
        
        ofstream fout;
        fout.open(string_name);
        
        cout << endl
        << "storing data to file" << endl;
        while( input < size )
        {
            fout << volume_array[input] << endl;
            cout << volume_array[input++] << endl;
        }
        cout << "data stored to " << string_name;
        
        fout.close();
    }
}
