//2. c++ program to convert from celcius to fahrenheit and vice versa
#include <iostream>
using namespace std;


int main()
{
    float fahrenheit, celcius;
    int choice;
    cout << "Enter 1 : Fahrenheit to celcius \nEnter 2 : Celcius to Fahrenheit" << endl; cin >> choice;

    if (choice == 1)
    {
        cout << "Enter the Fahrenheit value :" << endl; cin >> fahrenheit;

        celcius = (fahrenheit - 32) / 1.8;
        cout << "It is " << celcius << " degree celcius" << endl;
    }
    else if (choice == 2)
    {
        cout << "Enter the Celcius value :" << endl; cin >> celcius;

        fahrenheit = (1.8 * celcius) + 32;
        cout << "It is " << fahrenheit << " degree Fahrenheit" << endl;
    }
    else
    {
        cout << "Please enter a valid input" << endl;
    }
    return 0;
}
