#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

//A Vector to Save Previous Attempts
vector<string> Saved_Attempt;

//Repeat Checker
bool NoRepeats(const string& input) {
    for (const auto& attempt : Saved_Attempt) {
        if (attempt == input) {
            return true; // Found a repeat
        }
    }
    return false;
}


int main()
{
    //Limit Before The Security Check
    const int Limit = 10;
    string UserInput;
    string Password = "Password";

    
    while (true) {

        
        //A Loop That Asks The User For Their Input
        for (int Attempt = 0; Attempt <= Limit; ++Attempt)
        {

            int Remaining = (Attempt - Limit) * (-1);

            cout << "Please Enter A Password: ";
            cin >> UserInput;

            //Run A Code That'll Check If The User's Input Has Been Done Before
            if (NoRepeats(UserInput))
            {
                --Attempt;
                continue;
            } 

            //Makes The Saved_Attempt Vector Increase Size Based on How Many Inputs
            Saved_Attempt.push_back(UserInput);

            //If No Repeats Save The Attempt
            UserInput = Saved_Attempt[Attempt];

            if (Attempt != Limit && UserInput == Password)
            {
                cout << "Password Accepted. Access Granted";
                return false;
            }
            else
            {
                cout << "Password Denied. Access Denied! " << Remaining << " Attempts Remaining!" << endl;
            }
    }
}
    cout << "Attempt Limit Reached! System Is Now Locked.\n";
    return 0;    
}


