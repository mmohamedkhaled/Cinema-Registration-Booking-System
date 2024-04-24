#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

using namespace std;


class EmptyText : public logic_error
{
public :
    EmptyText(string x): logic_error("Error : Empty "+ x){}
};

// /////////////////////////////////
class InvalidDate : public logic_error
{
public :
    InvalidDate(string msg): logic_error(msg){}
};
class InvalidDay : public InvalidDate
{
public:
    InvalidDay():InvalidDate("Invalid Day, choose a day between 1-31"){}
};
class InvalidYear : public InvalidDate
{
public:
    InvalidYear():InvalidDate("Invalid Year"){}
};

// /////////////////////////////////

class DuplicateUser : public logic_error
{
public:
    DuplicateUser(string x):logic_error(x +" user already exists"){}
};

// /////////////////////////////////
class PasswordMisMatch : public logic_error
{
public:
    PasswordMisMatch():logic_error("The Passwords don't match, try again"){}
};
#endif // EXCEPTIONS_H
