#include <iostream>
#include "ContinuedFraction.h"
using namespace std;

// This is the file to implement the class described in the header file ContinuedFraction.h


//Default Constructor
ContinuedFraction::ContinuedFraction()
{
    cout << "Entering default value of 1/1";
    numerator = 1;
    denominator = 1;
}

//Constructor with values
ContinuedFraction::ContinuedFraction(int num, int denom)
{
    this->numerator = num;
    this->denominator = denom;
}

//Copy constructor
ContinuedFraction::ContinuedFraction(const ContinuedFraction& other)
{
    numerator = other.numerator;
    denominator = other.denominator;
}

// equal operator overlord
ContinuedFraction& ContinuedFraction::operator=(const ContinuedFraction& other)
{
    numerator = other.numerator;
    denominator = other.denominator;

    return *this;
}


//The MAIN attraction:
//The simplify and the compute methods
// These 2 methods are doing most of the heavy lifting

//In the simplify method, I must use the greatest common denominator of the numerator
//and denominator in order to reduce the fraction to its minimal form

void ContinuedFraction::simplify()
{

    int temp = denominator;

    while(!((numerator%temp == 0) && (denominator%temp ==0)))
    {
        temp--;
    }
    numerator /= temp;
    denominator /= temp;
}

// In the compute method, I must compute the continued fraction to enter
// into the vector terms 

void ContinuedFraction::compute()
{
    
}



//Implementation for fromFraction method
//I copy pasted the description

// Conversion methods
//Purpose: This method takes a rational number(numerator and denominator) and converts it into a continued fraction representation.
//Step - by - step :
//    Storing the fraction : The method assigns the given num(numerator) and denom(denominator) to the corresponding member variables 
//    of the class (numerator and denominator).
//    Validation : It checks if the denominator is zero, and if so, throws an exception(std::invalid_argument) because a fraction with a 
//    zero denominator is invalid.
//    Simplifying : After storing the values, it calls simplify() to reduce the fraction to its simplest form by dividing both the 
//    numerator and denominator by their greatest common divisor(gcd).
//    Generating the Continued Fraction : It calls compute() to generate the continued fraction representation of the given fraction.
//    So, the purpose of this method is to take a rational number, ensure it's valid(non - zero denominator), simplify it, and then 
//    compute its continued fraction representation.
void ContinuedFraction::fromFraction(int num, int denom)
{
    if(denom == 0)
    {
        throw std::invalid_argument("Do not set the denominator to 0");
    }

    numerator = num;
    denominator = denom;

    simplify();   //this should reduce the fraction to its simplest form when put into the class variables

    compute(); //this should compute the class variables in order to convert it into a class
}

//Implementation for toFraction method
//I copy pasted the description

//Purpose: This method converts the continued fraction(which is represented by the terms vector) back into a simple fraction(numerator and denominator)
//Step - by - step :
//Edge case check: It first checks if the terms vector is empty.If it is, it returns a default fraction 0 / 1 (representing 0).
//Reversing the continued fraction :
//The continued fraction is stored as a list of "partial quotients" in the terms vector.
//The algorithm starts with the last term in the continued fraction(this is typically the first term in the fraction expansion) 
//and works backwards to reconstruct the rational number.

//How :
//    It initializes num = 1 and denom = terms[n - 1](the last term).
//    Then, it iterates over the remaining terms(starting from the second - to - last) and 
//    reconstructs the fraction by repeatedly swapping num and denom and updating denom as denom + terms[i] * num.
//    Swapping : After the loop, it swaps num and denom one more time to get the final fraction.
//    Simplification : It calculates the gcd of the numerator(num) and denominator(denom), and divides both by this gcd to reduce the fraction 
//    to its simplest form.
//    Return : Finally, the method returns the fraction as a std::pair<int, int>.This pair contains the simplified numerator and denominator.
pair<int, int> ContinuedFraction::toFraction() const
{

    return {1, 1};
}



//Getter method to get vector called terms
vector<int> ContinuedFraction::getTerms() const
{
    return this->terms;
}

//Operator overload implementations
ContinuedFraction ContinuedFraction::operator+(const ContinuedFraction& other) const
{
    return ContinuedFraction(1, 1);
}

ContinuedFraction ContinuedFraction::operator-(const ContinuedFraction& other) const
{
    return ContinuedFraction(1, 1);
}

ContinuedFraction ContinuedFraction::operator*(const ContinuedFraction& other) const
{
    int newNum = this->numerator*other.numerator;
    int newDenom = this->denominator*other.denominator;
    return ContinuedFraction(newNum, newDenom);
}
ContinuedFraction ContinuedFraction::operator/(const ContinuedFraction& other) const
{
    int newNum = this->numerator*other.denominator;
    int newDenom = this->denominator*other.numerator;
    return ContinuedFraction(newNum, newDenom);
}


// Stream I/O overloads
std::ostream& operator<<(std::ostream& os, const ContinuedFraction& cf)
{
    os << cf.numerator << "/" << cf.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, ContinuedFraction& cf)
{
    return is >> cf;
}