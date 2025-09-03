
#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <algorithm>
#include <cctype>

namespace StringUtils {
    
    /**
     * Convert string to uppercase
     * @param str Input string
     * @return Uppercase version of the string
     */
    std::string toUpper(const std::string& str);
    
    /**
     * Convert string to lowercase
     * @param str Input string
     * @return Lowercase version of the string
     */
    std::string toLower(const std::string& str);
    
    /**
     * Check if a string is a palindrome
     * @param str Input string
     * @return True if string is palindrome, false otherwise
     */
    bool isPalindrome(const std::string& str);
}

namespace StringUtils {
    
    std::string toUpper(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), 
                      [](unsigned char c) { return std::toupper(c); });
        return result;
    }
    
    std::string toLower(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), 
                      [](unsigned char c) { return std::tolower(c); });
        return result;
    }
    
    bool isPalindrome(const std::string& str) {
        if (str.empty()) return true;
        
        // Convert to lowercase and remove spaces for better comparison
        std::string cleaned;
        for (char c : str) {
            if (std::isalnum(c)) {
                cleaned += std::tolower(c);
            }
        }
        
        int left = 0;
        int right = cleaned.length() - 1;
        
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
}

#endif