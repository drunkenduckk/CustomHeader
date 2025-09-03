#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <stdexcept>
namespace MathUtils {
    
    /**
     * Add two integers
     * @param a First integer
     * @param b Second integer
     * @return Sum of a and b
     */
    int add(int a, int b);
    
    /**
     * Subtract two integers
     * @param a First integer
     * @param b Second integer
     * @return Difference of a and b
     */
    int subtract(int a, int b);
    
    /**
     * Multiply two integers
     * @param a First integer
     * @param b Second integer
     * @return Product of a and b
     */
    int multiply(int a, int b);
    
    /**
     * Divide two integers
     * @param a Dividend
     * @param b Divisor
     * @return Quotient of a divided by b
     * @throws std::invalid_argument if divisor is zero
     */
    int divide(int a, int b);
}

namespace MathUtils {
    
    int add(int a, int b) {
        return a + b;
    }
    
    int subtract(int a, int b) {
        return a - b;
    }
    
    int multiply(int a, int b) {
        return a * b;
    }
    
    int divide(int a, int b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero is not allowed!");
        }
        return a / b;
    }
}

#endif
