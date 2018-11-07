// PreLab 5 Assignment

// The following is an extremely scientific personality test that can predict
// how well you will do in this course.
// Fill in the area below with the requested code.

#include <iostream>

using namespace std;

int main()
{
     char answer;
     string message;

     cout << "Is Star Trek better than Star Wars? ('Y' or 'N')" << endl;
     cin >> answer;

     // TODO - Change the following IF-ELSE statement to an
     // equivalent switch statement.

     if (answer == 'y' || answer == 'Y')
     {
          cout << "You think Star Trek is better than Star Wars..." << endl;
          message = "Wrong! You are likely to fail this class...";
     }
     else if (answer == 'n' || answer == 'N')
     {
          cout << "You do not think think Star Trek is better than Star Wars..." << endl;
          message = "Correct! You will undoubtedly ace this class!!!!" ;
     }
     else
     {
          message = "Invalid Input. This does not bode well for you.";
     }

     cout << message << endl;

     return 0;
}

/* 
State of Texas | Texas State University | College of Science and Engineering | Computer Science Department
Contact Us | Disclaimer

Copyright @ 2017 Department of Computer Science - Texas State University

*/




