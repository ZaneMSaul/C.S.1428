/*
File: lab7_zms24.cpp

Zane Saul
C.S.1428.751
Lab Section: L52
07/26/2017
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main( )
{
    int computer_roll,
        user_roll;

    double user_cash = 0,
           start_cash = 1000,
           bet_amount;

    char choice;
    
    ifstream fin;
    fin.open ("game_save.txt");

    cout << "Created by: Zane Saul" << endl << endl
         << "Gambling is an addiction..." << endl << endl;
    if ( fin )
    {
        cout << "Game Save detected would you like to use game save? "
             << "(Y or N) : ";
        do
        {
        cin >> choice;
        }while( choice != 'Y' && choice != 'y'
               && choice != 'N' && choice != 'n');
        if ( choice == 'y' || choice == 'Y' )
        {
            fin >> user_cash;
            if ( user_cash == 0 )
            {
                user_cash = start_cash;
                cout << "Your game save was empty, heres " << user_cash << ".";
            }
        }
        else
            user_cash = start_cash;
    }
    else
        user_cash = start_cash;
    
    ofstream fout;
    fout.open("game_save.txt");
    
    do
    {
        
        cout << endl << endl
             << "You currently have $" << user_cash << endl
             << "How much would you like to bet?" << endl;
        cin >> bet_amount;

        while ( bet_amount < 1 || bet_amount > user_cash )
        {
            cout << "Error: Invalid bet amount." << endl
                 << "Enter the amount you would like to bet: $";
            cin >> bet_amount;
        }
        srand(time(NULL));
        
        computer_roll = rand ( ) % 6 + 1;
        user_roll = rand ( ) % 6 + 1;

        cout << endl
             << "You rolled " << user_roll << endl
             << "Your opponent rolled " << computer_roll << endl;

        if ( user_roll > computer_roll )
        {
            user_cash = user_cash + bet_amount;

            cout << "You win $" << bet_amount << endl << endl
                 << "Would you like to continue? (Y or N) : ";
            cin >> choice;
        }
        else if ( user_roll < computer_roll )
        {
            user_cash = user_cash - bet_amount;

            cout << "You lose $" << bet_amount << endl << endl
                 << "Would you like to continue? (Y or N) : ";
            cin >> choice;
        }
        else
        {
            cout << "No one wins. Its a tie!" << endl << endl
                 << "Would you like to continue? (Y or N) : ";
            cin >> choice;
        }
        while( choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            cout << "Error: Invalid choice. Enter (Y or N)";
            cin >> choice;
        }
        while  ( user_cash < 1 && ( choice == 'y' || choice == 'Y' ) )
        {
                cout << endl
                << "Your out of money. You can't play anymore." << endl
                << "Do you need to borrow more money? (Y or N) ";
                cin >> choice;
                if ( choice == 'y' || choice == 'Y' )
                    user_cash = user_cash + start_cash;
        }
    }while ( choice == 'y' || choice == 'Y' );
    
    cout << endl
         << "You ended with $" << user_cash << endl << endl;
    
    fin.close();
    
    if ( user_cash > 1 )
    {
        cout << "Would you like to deposite your cash in the bank? (Y or N) : ";
        do
        {
        cin >> choice;
        }while( choice != 'Y' && choice != 'y'
               && choice != 'N' && choice != 'n');
        if ( choice == 'y' || choice == 'Y' )
        {
            fout << user_cash;
            cout << "You stored $" << user_cash << " in the bank!"
                 << endl << endl << endl;
            
            fout.close();
        }
    }
    
    system("PAUSE>NUL");

    return 0;
}
