#include <iostream>
#include "ContinuedFraction.h"

int main() {
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

        ContinuedFraction simplifyThisPlease(354834, 43254);
        std::cout << simplifyThisPlease << std::endl;
        simplifyThisPlease.simplify();
        std::cout << simplifyThisPlease;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
