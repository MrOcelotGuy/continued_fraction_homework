#include <iostream>
#include "ContinuedFraction.h"


//Unit test in order to test that it works
bool runTests() {
    ContinuedFraction cf1(43, 13);
    std::vector<int> expectedValue {3,3,4};
    if (cf1.getTerms()!=expectedValue) 
    {
        return false;
    }

    ContinuedFraction cf2(4, 1);
    std::vector<int> expectedValue2 {4};
    if (cf2.getTerms()!=expectedValue2) 
    {
        return false;
    }

    ContinuedFraction cf3(0, -5);
    std::vector<int> expectedValue3 {0};
    if (cf3.getTerms()!=expectedValue3) 
    {
        return false;
    }

    ContinuedFraction cf4(-2, 3);
    std::vector<int> expectedValue4 {0, -1, -2};
    if (cf4.getTerms()!=expectedValue4) 
    {
        return false;
    }

    ContinuedFraction cf5(-2, 3);
    std::pair<int, int> expectedValue5 {-2, 3};
    if ((cf5.toFraction().first != expectedValue5.first) || (cf5.toFraction().second != expectedValue5.second))
    {
        return false;
    }

    ContinuedFraction cf6(-2, 5);
    ContinuedFraction expectedValue6{-16, 15};
    ContinuedFraction actualValue = cf6+cf5;
    if (actualValue.getTerms() != expectedValue6.getTerms()) 
    {
        return false;
    }



    return true;
}


int main() {

    //Running the unit test, if it fails then it returns 1 and therefore exits the program
    if (!runTests()) 
    {
        std::cout << "Tests have failed" <<std::endl;
        return 1;
    } 
    else 
    {
        std::cout << "Tests have passed" << std::endl;
    }

    try {
        // Test 1: Convert a rational number to continued fraction
        ContinuedFraction cf1(355, 113);
        std::cout << "Continued Fraction of 355/113: " << cf1 << std::endl;

        // Test 2: Convert continued fraction back to rational number
        std::pair<int, int> fraction1 = cf1.toFraction();
        std::cout << "Converted back to fraction: " << fraction1.first << "/" << fraction1.second << std::endl;

        // Test 3: Operator Overloading (+, -, *, /)
        ContinuedFraction cf2(22, 7);
        std::cout << "cf2 (22/7): " << cf2 << std::endl;

        ContinuedFraction sum = cf1 + cf2;
        std::cout << "Sum: " << sum << std::endl;

        ContinuedFraction diff = cf1 - cf2;
        std::cout << "Difference: " << diff << std::endl;

        ContinuedFraction prod = cf1 * cf2;
        std::cout << "Product: " << prod << std::endl;

        ContinuedFraction quot = cf1 / cf2;
        std::cout << "Quotient: " << quot << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
