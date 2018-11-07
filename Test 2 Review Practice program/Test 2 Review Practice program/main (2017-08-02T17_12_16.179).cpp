#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

void fileCount( ifstream &, int &, double );
void radiusArray( ifstream &, int, int, double [] );
void calcVolume( int, int, double &, double, double [] );
void volumeArray( int, int, double &, double, double [], double [] );

int main( )
{
    const double PI = 3.141592;
    
    int size = 0,
    input = 0;
    
    double radius = 0,
    volume;
    
    char choice;
    
    string string_name;
    
    double radius_array[size];
    double volume_array[size];
    
    ifstream fin;
    fin.open("inputfile.txt");
    
    fileCount( fin, size, radius );
    
    radiusArray( fin, size, input, radius_array );
    
    //calcVolume( input, size, volume, PI, radius_array );
    
    volumeArray( input, size, volume, PI, radius_array, volume_array );
    

    cout << endl << endl;
    
    fin.close();
    
    return EXIT_SUCCESS;
}
/*
 This function counts the number of file inputs
 */
void fileCount( ifstream &fin, int &size, double radius )
{
    do
    {
        fin >> radius;
        
        cout << radius << " ";
        
        size++;
    }while( !fin.eof() );
    
    cout << endl << endl
         << "size after funtion fileCount's do while loop is: "
         << size << endl << endl;
}

/*
 This function builds an array to store radius in from an input data file.
 */
void radiusArray( ifstream &fin, int size, int input, double radius_array[] )
{
    input = 0;
    
    fin.close();
    fin.open("inputfile.txt");
    
    cout << "storing data to radius_array" << endl << endl;
    for( input = 0; input < size; input++ )
    {
        fin >> radius_array[input];
        cout << "Array storage location " << input << " radius: "
             << radius_array[input] << endl;
    }
    if( input = 3 )
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
    
    cout << "How many decimal places would you like volume to have?" << endl
         << "Enter an integer greater than or equal to 0: ";
    cin >> decimal_places;
    
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

void outputConstruct( )
{
    string string_name;
    char choice;
    
    cout << "Would you like an output data file?";
    
    do
    {
        cout << endl
        << "[Y or N] : ";
        cin >> choice;
    }while( choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n' );
    
    if( choice == 'Y' || choice == 'y' )
    {
        cout << "What file name would you like?" << endl;
        cin >> string_name;
        
        ofstream fout;
        fout.open(string_name);
        
        input = 0;
        
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
