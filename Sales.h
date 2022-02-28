
/*
 Specification file for the Sales class
  - Overloaded stream insertion operator (<<)
  - Overloaded relational operator (<)
 */

#ifndef SALES_H
#define SALES_H
#include <string>

using std::ostream;
using std::string;


class Sales
{
private:
    string id;
    int year;
    string name;
    int amountSold;

public:
    // constructors
    Sales (string id_val, int year_val, string name_val, int amountSold_val);
    Sales (string id_val, int year_val, string name_val);
    Sales (string id_val, int year_val);
    Sales (string id_val);
    Sales ();

    // setters
    void setId          (string id_val)          {id = id_val;};
    void setYear        (int    year_val)        {year = year_val;};
    void setName        (string name_val)        {name = name_val;};
    void setAmountSold  (int    amountSold_val)  {amountSold = amountSold_val;};
    
    // getters
    string  getId()         const {return id;};
    int     getYear()       const {return year;};
    string  getName()       const {return name;};
    int     getAmountSold() const {return amountSold;};

    // other functions
    void    display () const;
    double  detCommissionPercent (int amountSold) const;
    double  detAmountEarned (int amountSold) const;

    // overloaded operators
    bool operator <   (const Sales right) const;
    bool operator ==  (const Sales right) const;
    bool operator >   (const Sales right) const;
    bool operator >=  (const Sales right) const;
    bool operator <=  (const Sales right) const;
    bool operator !=  (const Sales right) const;

    // friends
    friend ostream &operator << (ostream &strm, Sales &obj); 
};

#endif
