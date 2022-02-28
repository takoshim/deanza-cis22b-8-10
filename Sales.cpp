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