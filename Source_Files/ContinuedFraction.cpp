#include <iostream>
#include "ContinuedFraction.h"
using namespace std;

// This is the file to implement the class described in the header file ContinuedFraction.h


//Default Constructor
ContinuedFraction::ContinuedFraction()
{
    numerator = 0;
    denominator = 1;
}

//Constructor with values
ContinuedFraction::ContinuedFraction(int num, int denom)
{
    if(denom == 0)
    {
        throw invalid_argument("Denominator can't be 0");
    }
    // this->numerator = num;
    // this->denominator = denom;
    fromFraction(num, denom);
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
    int g = gcd(abs(this->numerator), abs(this->denominator));
    this->numerator /= g;
    this->denominator /= g;
}

int ContinuedFraction::gcd(int a, int b) {
    // int min;   //Temporary number that will hold the value of the smallest one of the two in order to subtract
    if(b == 0)
    {
        return a;
    }
    if(a == 0)
    {
        return b;
    }
    int min = a<b ? a : b;
    
  
    // The previous two if statements are to determine whether the denominator or numerator is smaller, the integer temp will take on the
    // value of the smallest one

    while((a%min != 0) || (b%min != 0)) //Calculate the GCD with the temporary number
    {
        min--;
    }
    return min;
}

// In the compute method, I must compute the continued fraction to enter
// into the vector terms 

void ContinuedFraction::compute()
{

    bool isNegative = (numerator < 0) != (denominator < 0); //checks if the fraction is negative
    int a = abs(numerator);   //a is the initial numerator
    int b = abs(denominator); //b is the initial denominator
    
    //the two above have to be with absolute value so that it doesn't break with negatives

    if(a%b == 0)
    {
        int sign = isNegative ? -1 : 1;
        terms.push_back(sign*(a/b));     //for continued fractions that only have 1 term, negating if it needs to be negated
    }
    else
    {
        int q; //declaring the quotient
        int r; //declaring the remainder

        while(b != 0) //this iteratively loops until the denominator, which is equivalent to the remainder, is 0
        {
            /* code */
            q = a/b;    //q is short for quotient, calculates the integer quotient of the numerator a and denominator b
            r = a%b;    //r is short for remainder, calculates the remainder of numerator a and denominator b
            terms.push_back(q);  //The algorithm provided of taking the quotient for the list

            a = b;  // the numerator becomes what was previously the denominator
            b = r;  // the denominator becomes what was previously the remainder
        }
        

        //Non-standard way of getting negative CF by simply negating each list member.
        //Usually only the first term can be negative, however the original algorithm doesn't work for
        //negatives and negating each member still is equivalent.

        if(isNegative)
        {
            for(int i = 0; i < terms.size(); i++)  
            {
                terms[i] = -terms[i];
            }
        }
    }
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
    terms.clear();
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
    if(terms.empty())
    {
        return {0,1};
    }
    pair<int, int> fraction = {1, terms.back()};

    for(int i = terms.size()-2; i >= 0; i--)
    { 
        swap(fraction.first, fraction.second);
        fraction.second = (fraction.second + (terms.at(i)*fraction.first));
    }
    swap(fraction.first, fraction.second);
    
    return fraction;
}



//Getter method to get vector called terms
vector<int> ContinuedFraction::getTerms() const
{
    return this->terms;
}

//Operator overload implementations
ContinuedFraction ContinuedFraction::operator+(const ContinuedFraction& other) const
{
    return ContinuedFraction( ( (this->numerator * other.denominator) + (other.numerator * this->denominator)), (this->denominator*other.denominator));
}

ContinuedFraction ContinuedFraction::operator-(const ContinuedFraction& other) const
{
    return ContinuedFraction( ( (this->numerator * other.denominator) - (other.numerator * this->denominator)), (this->denominator*other.denominator));
}

ContinuedFraction ContinuedFraction::operator*(const ContinuedFraction& other) const
{
    int newNum = this->numerator*other.numerator;
    int newDenom = this->denominator*other.denominator;
    return ContinuedFraction(newNum, newDenom);
}
ContinuedFraction ContinuedFraction::operator/(const ContinuedFraction& other) const
{
    if(other.numerator == 0)
    {
        throw invalid_argument("Don't divide by 0");
    }
    int newNum = this->numerator*other.denominator;
    int newDenom = this->denominator*other.numerator;
    return ContinuedFraction(newNum, newDenom);
}


// Stream I/O overloads
std::ostream& operator<<(std::ostream& os, const ContinuedFraction& cf)
{
    cout << "[";
    for(int i = 0; i < cf.getTerms().size()-1; i++)
    {
        cout << cf.getTerms().at(i) << ", ";
    }
    cout << cf.getTerms().back() << "]";
    return os;
}

std::istream& operator>>(std::istream& is, ContinuedFraction& cf)
{
    cout << "Enter the numerator: ";
    is >> cf.numerator;
    cout << "Enter the denominator: ";
    is >> cf.denominator;
    return is;
}