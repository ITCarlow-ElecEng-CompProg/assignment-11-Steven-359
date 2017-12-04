 /*
    Steven O' Brien
    13/11/17
    Exercise 11
     Date Structure
  */


#include <iostream>
#include <iomanip>
/** allows getchar() */
#include <cstdio>
/** allows system(cls) */
#include <windows.h>
#include <cmath>

using namespace std;

// structure definition
struct date
{
	int month;
	int day;
	int year;
};
// sub functions declarations
int checkLeapYear(int);
void getCurrentDate(struct date &);

int main()
{
    // print heading
    cout << " Date Structure" << endl;

    //variables declaired type struct and int
    struct date today, tomorrow;
    int monthlength [12] = {31, 28, 31, 30, 30, 30, 31, 31, 30, 31, 30, 31};

    // calling funtion current date
    getCurrentDate(today);

    // displays todays date
    cout << "\n\nToday's date is " << today.day  << "/" << today.month<< "/" << today.year << endl;

    // how to increment date by a day, keeping the same month and year
    tomorrow.day=today.day+1;
    tomorrow.month = today.month;
    tomorrow.year = today.year;

    // calling function checkleapyear
    monthlength[1] = checkLeapYear(today.year);

    // if statement to increment date for a new month
    if(tomorrow.day > monthlength[today.month-1])
    {
        tomorrow.day = 1;
        tomorrow.month = today.month +1;
        tomorrow.year = today.year;
    }
    // if statement to increment date for a new year
    if (today.month >= 12)
    {
        tomorrow.month = 01;
        tomorrow.year = today.year + 1;
    }

    // displays tomorrows date
    cout << "\n\nTomorrows Date is :" << tomorrow.day << "/" << tomorrow.month << "/" << tomorrow.year << endl;

    return 0;
}

// function to get current date
void getCurrentDate(struct date &today)
{
    // allows user input todays date
    cout<< "Enter todays day (dd)" <<endl;
    cin>> today.day ;

    cout<< "Enter todays month (mm)" <<endl;
    cin>> today.month ;

    cout<< "Enter todays year (yyyy) " <<endl;
    cin>> today.year ;

    return;
}

// function to check leap year
int checkLeapYear(int year)
{
    int days = 28;

    // if statement to check if today.year is a leap year
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                days = 29;
            }

        }
        else
        { //only by 4, not by 100
            days = 29;
        }
    }

    return days;
}
