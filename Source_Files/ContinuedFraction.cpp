#include <iostream>
#include "ContinuedFraction.h"
using namespace std;

ContinuedFraction::ContinuedFraction()
{
    numerator = 1;
    denominator = 1;
}

ContinuedFraction::ContinuedFraction(int num, int denom)
{
    this->numerator = num;
    this->denominator = denom;
}

ContinuedFraction::ContinuedFraction(const ContinuedFraction& other)
{
    numerator = other.numerator;
    denominator = other.denominator;
}

ContinuedFraction& ContinuedFraction::operator=(const ContinuedFraction& other)
{

}

vector<int> ContinuedFraction::getTerms() const
{
    return this->terms;
}