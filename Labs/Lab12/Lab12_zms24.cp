/*
Zane Saul
C.S.1428.751
Lab Section: L52
08/07/2017
*/

 #include <iostream>
 #include <cstdlib>

 using namespace std;

 struct item
 {
    string name;
    double cost;
    int quantity;
 };

 int main( )
 {
    int total = 0;

    double value = 0,
           cheapest = 10000;

    string cheap;

    item data[3];

    for( int i = 0; i < 3; i++)
    {
        cout << "Product #" << i + 1 << endl
             << "Enter name: ";
        cin >> data[i].name;

        cout << "Enter cost: ";
        cin >> data[i].cost;

        cout << "Enter quatity: ";
        cin >> data[i].quantity;

        cout << endl << endl;
    }

    for( int i = 0; i < 3; i++ )
    {
        total = total + data[i].quantity;
        value = value + ( data[i].cost * data[i].quantity );
    }

    for( int i = 0; i < 3; i++ )
    {
        if( data[i].cost < cheapest)
        {
            cheapest = data[i].cost;
            cheap = data[i].name;
        }
    }

    cout << "Total number of items   : " << total << endl
         << "Total value of inventory: $" << value << endl
         << "Cheapest item           : " << cheap << endl;

    system("PAUSE>NUL");

    return 0;
 }




