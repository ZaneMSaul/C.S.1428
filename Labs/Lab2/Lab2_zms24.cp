/*
Zane Saul
C.S.1428.751
Lab Section: L52
07/14/2017
*/
#include<iostream>
using namespace std;
int main( )
{
  double height;
  double weight;
  double BMI;
  string name;

  cout << "Zane Saul" << endl
       << "C.S.1428.751" << endl
       << "Lab Section: L52" << endl
       << "07/14/2017" << endl << endl;

  cout << "What is your name?" << endl;
  cin >> name;
  cout << endl << "What is your total weight (lbs.)?" << endl;
  cin >> weight;
  cout << endl << "What is your height (inches) [1 foot = 12 inches]?" << endl;
  cin >> height;

  BMI = ( weight / ( height * height ) * 703 );

  cout << endl << name << "'s BMI is " << BMI << endl << endl;

  return 0;
}
