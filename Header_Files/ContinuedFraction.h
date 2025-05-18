#ifndef CONTINUED_FRACTION_H
#define CONTINUED_FRACTION_H

#include <iostream>
#include <vector>
#include <utility>  // For std::pair

class ContinuedFraction {
private:
    int numerator;
    int denominator;
    std::vector<int> terms;

    void simplify();
    void compute();

public:
    //GCD
    static int gcd(int a, int b);

    // Constructors
    ContinuedFraction();
    ContinuedFraction(int num, int denom);

    // Copy constructor and assignment operator
    ContinuedFraction(const ContinuedFraction& other);
    ContinuedFraction& operator=(const ContinuedFraction& other);

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
    void fromFraction(int num, int denom);

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
    std::pair<int, int> toFraction() const;
    

    // Getter for terms
    std::vector<int> getTerms() const;

    // Operator overloads
    ContinuedFraction operator+(const ContinuedFraction& other) const;
    ContinuedFraction operator-(const ContinuedFraction& other) const;
    ContinuedFraction operator*(const ContinuedFraction& other) const;
    ContinuedFraction operator/(const ContinuedFraction& other) const;

    // Stream I/O overloads
    friend std::ostream& operator<<(std::ostream& os, const ContinuedFraction& cf);
    friend std::istream& operator>>(std::istream& is, ContinuedFraction& cf);
};

#endif // CONTINUED_FRACTION_H
