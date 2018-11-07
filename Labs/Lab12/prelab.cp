//You may not have covered this material in your lecture sections.
//Complete as best as you are able.  Refer to the prelab reading for assistance.

//Add code where requested to complete the program.

#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

struct Dog
{
    string name;
    string breed;
    char sex;
    int age;
};

int main()
{
	// TODO - Create a Dog object named "dog1", and initialize its name to
	//        "Sparky", sex to 'M', age to 5, and breed to "Collie".
	Dog dog1;

	dog1.name = "Sparky";
	dog1.sex = 'M';
	dog1.age = 5;
	dog1.breed = "Collie";

        // TODO - Create a Dog object named "dog2".
	Dog dog2;

	// TODO - Prompt the user to enter the dog's name, age, sex, and breed,
	//        and assign them to the "dog2" object.
        //        Assume the dog name and breed are entered as a single word
        //        so that both will work with cin statements.

	cout << "What is your dogs name? " << endl;
	cin >> dog2.name;

	cout << "What gender is your dog? " << endl;
	cin >> dog2.sex;

	cout << "What age is your dog? " << endl;
	cin >> dog2.age;

	cout << "What is your dogs breed " << endl;
	cin >> dog2.breed;

	// TODO - Print "dog1" and "dog2" objects to the console. E.g.
	//        "Name: Sparky, Sex: M, Age: 5, Breed: Collie"

	cout << "My dogs name is " << dog1.name << " who is a " << dog1.sex
         << " it is " << dog1.age << " years old and is a " << dog1.breed
         << "." << endl;

    cout << "Your dogs name is " << dog2.name << " who is a " << dog2.sex
         << " it is " << dog2.age << " years old and is a " << dog2.breed
         << "." << endl << endl;

    cout << "It was nice getting to know you!" << endl;
    system("PAUSE>NUL");

    return 0;
}
