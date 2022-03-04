/*
  Implementation file for the Sales class.
*/

#include "Sales.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*~*~*~*~*~*~
 This is the default constructor; it sets everything to 0 or "".
 */
Sales::Sales(){
    id = "";
    year = 0;
    name = "";
    amountSold = 0;
}

/*~*~*~*~*~*~
 These are overloaded constructors.
 They set the variables according to the parameters.
*/
Sales::Sales (string id_val) {
    id = id_val;
    year = 0;
    name = "";
    amountSold = 0;
}

Sales::Sales (string id_val, int year_val) {
    id = id_val;
    year = year_val;
    name = "";
    amountSold = 0;
}

Sales::Sales (string id_val, int year_val, string name_val) {
    id = id_val;
    year = year_val;
    name = name_val;
    amountSold = 0;
}

Sales::Sales (string id_val, int year_val, string name_val, int amountSold_val) {
    id = id_val;
    year = year_val;
    name = name_val;
    amountSold = amountSold_val;   
}

/*~*~*~*~*~*~
This function displays the member variables,
 the commision percent and amount earned
 in a neat format.
*/
void Sales::display() const{

    cout << "           ID: " << id << endl;
    cout << "         Year: " << year << endl;
    cout << "         Name: " << name << endl;
    cout << "  Amount Sold: $" << amountSold << endl;
    cout << "   Commission: " << detCommissionPercent(getAmountSold()) << "%" << endl;
    cout << "Amount Earned: $" << detAmountEarned(getAmountSold()) << endl;
}

/*~*~*~*~*~*~
 This function determines the commision percent based on the following table:
    Sales        Commission
   $0 - 1000        3%
 1001 - 5000        4.5%
 5001 - 10,000      5.25%
 over 10,000        6%
*/
double Sales::detCommissionPercent (int amountSold) const {

    double commission = 0;    
    if      (amountSold <= 0)
        commission = 0;
    else if (amountSold >= 1    && amountSold <= 1000)
        commission = 3.0;
    else if (amountSold >= 1001 && amountSold <= 5000)
        commission = 4.5;
    else if (amountSold >= 5001 && amountSold <= 10000)
        commission = 5.25;
    else if (amountSold >= 10001)
        commission = 6;
    return commission; 
}

/*~*~*~*~*~*~
 This function determines the amount earned:
 it calls the detCommisionPercent) function.
 */
double Sales::detAmountEarned (int amountSold) const{
    double amountEarned = 0;
    amountEarned = amountSold * detCommissionPercent(amountSold) * 0.01;
    return amountEarned;
}

/***********************************************
 Overloaded operator <
 ************************************************/
bool Sales::operator < (const Sales right) const {
    return name < right.name;
}

bool Sales::operator < (const string right) const {
    return name < right;
}

/***********************************************
 Overloaded operator ==
 ************************************************/
bool Sales::operator == (const Sales right) const {
    return name == right.name;
}

bool Sales::operator == (const string right) const {
    return name == right;
}

/************************************************
 Overloaded operator >
************************************************/
bool Sales::operator > (const Sales right) const {
    return name > right.name;
}

bool Sales::operator > (const string right) const {
    return name > right;
}

/************************************************
 Overloaded operator >=
************************************************/
bool Sales::operator >= (const Sales right) const {
    return name >= right.name;
}

bool Sales::operator >= (const string right) const {
    return name >= right;
}

/************************************************
 Overloaded operator <=
************************************************/
bool Sales::operator <= (const Sales right) const {
    return name <= right.name;
}

bool Sales::operator <= (const string right) const {
    return name <= right;
}

/***********************************************
 Overloaded operator !=
 ************************************************/
bool Sales::operator != (const Sales right) const {
    return name != right.name;
}

bool Sales::operator != (const string right) const {
    return name != right;
}

/***********************************************
 Overloaded operator <<
 ************************************************/
ostream &operator << (ostream &strm, Sales &obj) {
    strm    << setw( 5) << left  << obj.year
            << setw(21) << left  << obj.name
            << setw( 9) << right << setprecision(2) << fixed << obj.detAmountEarned(obj.getAmountSold());
    return strm;
} 