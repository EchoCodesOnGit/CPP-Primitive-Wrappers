/*
 * This wrapper class was made to mimic the behavior of java-style wrapper classes. As of 12/21/24
 * it is still heavily a work-in-progress
 *
 * @author Ethan Smith
 * @version 0.1
*/
#include <iostream>
#include <string>
#include <cstddef>
#include <optional>
#include <cmath>
#include <bitset>
#include <sstream>
#include "../Number.h"
#ifndef WRAPPERS_INTEGER_H
#define WRAPPERS_INTEGER_H
class Integer : public Number{
private:
    int* value;
public:
    /*FIELDS*/
    static constexpr int BYTES = sizeof(int);
    static constexpr int MAX_VALUE = INT_MAX;
    static constexpr int MIN_VALUE = INT_MIN;
    static constexpr int SIZE = sizeof(int) * 8;
    //static Class<Integer> TYPE; //need to figure out how to implement this, will probably have to make own Class class
    /*END FIELDS*/

    /*CONSTRUCTORS*/
    explicit Integer(int value) {
        this->value = new int(value);
    }

    explicit Integer(const std::string& str) {
        try {
            this->value = new int(std::stoi(str));
        } catch (const std::invalid_argument &iaExcept) {
            std::cerr << "Invalid argument - " << iaExcept.what() << '\n';
        } catch (const std::out_of_range &oorExcept) {
            std::cerr << "Out of range - " << oorExcept.what() << '\n';
        }
    }
    /*END CONSTRUCTORS*/

    /*METHODS*/
    /*
     * Returns the number of active bits in a given value
     * @since 0.1
     */
    static int bitCount(int i) {
        int count = 0;
        while (i) {
            count += i & 1; //check if the least significant bit is 1
            i >>= 1;        //right shift the number
        }
        return count;
    }

    /*
     * The following # section does the same thing in both functions but has different implementations
     * @since 0.1
     */
    auto byteValue() {
        #if __cplusplus < 201703L
                return static_cast<char>(*this->value);
        #elif __cplusplus >= 201703L
                return static_cast<std::byte>(*this->value);
        #endif
    }

    static int compare(int x, int y){
        return x < y ? -1 : x > y ? 1 : 0;
    }

    int compareTo(Integer *anotherInteger){
        return *anotherInteger->value > *this->value ? 1 : *anotherInteger->value < *this->value  ? -1 : 0;
    }

    static int compareUnsigned(int x, int y){
        return (unsigned int)(x < y) ? -1 : (unsigned int)(x > y) ? 1 : 0;
    }

    static Integer decode(const std::string& nm) {
        try {
            return *(new Integer(nm));
        } catch (const std::invalid_argument& iaExcept) {
            std::cerr << "Invalid argument - " << iaExcept.what() << '\n';
            return *(new Integer(0));
        } catch (const std::out_of_range& oorExcept) {
            std::cerr << "Out of range - " << oorExcept.what() << '\n';
            return *(new Integer(0));
        }
    }

    static int divideUnsigned(int dividend, int divisor){
        return (unsigned int)(dividend / divisor);
    }

    double doubleValue(){
        return (double)*this->value;
    }

    float floatValue(){
        return (float)*this->value;
    }

    static Integer getInteger(const std::string& nm){
        const char* envVar = std::getenv(nm.c_str());
        if (envVar != nullptr) {
            try {
                return *(new Integer(std::stoi(envVar)));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Out of range: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Environment variable not found." << std::endl;
        }
        return *(new Integer(0));
    }

    int getInteger(const std::string& nm, int val) {
        const char *envVar = std::getenv(nm.c_str());
        if (envVar != nullptr) {
            try {
                return std::stoi(envVar);
            } catch (const std::invalid_argument &e) {
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            } catch (const std::out_of_range &e) {
                std::cerr << "Out of range: " << e.what() << std::endl;
            }
        }
        return val;
    }

    static std::optional<Integer> getInteger(const std::string& nm, std::optional<Integer> val = std::nullopt) {
        const char* envVar = std::getenv(nm.c_str());
        if (envVar != nullptr) {
            try {
                return *(new Integer(std::stoi(envVar)));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Out of range: " << e.what() << std::endl;
            }
        }
        return val;
    }

    int hashCode(){
        return std::hash<int>()(*this->value);
    }

    static int hashCode(int hashItem){
        return std::hash<int>()(hashItem);
    }

    static int highestOneBit(int i){
        if (i == 0) return 0;
        i |= (i >> 1);  // Step 1
        i |= (i >> 2);  // Step 2
        i |= (i >> 4);  // Step 3
        i |= (i >> 8);  // Step 4
        i |= (i >> 16); // Step 5
        return i - (i >> 1);
    }

    int intValue(){
        return *this->value;
    }

    long longValue(){
        return (long)*this->value;
    }

    static int lowestOneBit(int i){
        return i & -i;
    }

    static int max(int a, int b){
        return a > b ? a : b;
    }

    static int min(int a, int b){
        return a < b ? a : b;
    }

    static int numberOfLeadingZeros(int i){
        if (i == 0) return 32;
        int count = 0;
        for (int shift = 31; shift >= 0; --shift) {
            if ((i >> shift) & 1) break;
            count++;
        }
        return count;
    }

    static int numberOfTrailingZeros(int i){
        if (i == 0) return 32;
        int count = 0;
        while (i > 0 && (i & 1) == 0) {
            i >>= 1;
            count++;
        }
        return count;
    }

    static int parseInt(std::string str){
        return (int)std::stoi(str);
    }

    static int parseInt(std::string str, int radix){
        return (int)std::stoi(str, nullptr, radix);
    }

    static int parseUnsignedInt(std::string str){
        return (unsigned int)std::stoi(str);
    }

    static int parseUnsignedInt(std::string str, int radix){
        return (unsigned int)std::stoi(str, nullptr, radix);
    }

    static int remainderUnsigned(int dividend, int divisor){
        return (unsigned int)(dividend % divisor);
    }

    static int reverse(int i) {
        int result = 0;
        for (int j = 0; j < 32; ++j) {
            if (i & (1 << j)) {
                result |= (1 << (31 - j));
            }
        }
        return result;
    }

    static int reverseBytes(int i){
        int result = 0;
        for (int j = 0; j < 4; ++j) {
            result |= (i & 0xFF) << (24 - (j * 8));
            i >>= 8;
        }
        return result;
    }

    static int rotateLeft(int i, int distance) {
        const int BIT_SIZE = 32;
        distance %= BIT_SIZE;
        return (i << distance) | (i >> (BIT_SIZE - distance));
    }

    static int rotateRight(int i, int distance){
        const int BIT_SIZE = 32;
        distance %= BIT_SIZE;
        return (i >> distance) | (i << (BIT_SIZE - distance));
    }

    short shortValue(){
        return (short)(*this->value);
    }

    static int signum(int x) {
        return (x > 0) - (x < 0);
    }

    static int add(int a, int b){
        return a + b;
    }

    static std::string toBinaryString(int i){
        return std::bitset<SIZE>(i).to_string();
    }

    static std::string toHexString(int i){
        std::stringstream ss;
        ss << std::hex << i;
        return ss.str();
    }

    static std::string toOctalString(int i){
        std::stringstream ss;
        ss << std::oct << i;
        return ss.str();
    }

    std::string toString(){
        return std::to_string(*this->value);
    }

    static std::string toString(int i){
        return std::to_string(i);
    }

    static std::string toString(int i, int radix){
        if (radix < 2 || radix > 36) {
            throw std::invalid_argument("Radix must be between 2 and 36.");
        }

        const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
        bool isNegative = i < 0;
        unsigned int value = isNegative ? -i : i;
        std::string result;
        do {
            result = digits[value % radix] + result;
            value /= radix;
        } while (value > 0);
        if (isNegative && radix == 10) {
            result = '-' + result;
        }
        return result;
    }

    static long toUnsignedLong(int i){
        return (unsigned long)(i);
    }

    static std::string toUnsignedString(int i){
        std::to_string((unsigned long)i);
    }

    static std::string toUnsignedString(int i, int radix){
        if (radix < 2 || radix > 36) {
            throw std::invalid_argument("Radix must be between 2 and 36.");
        }
        const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
        unsigned int value = static_cast<unsigned int>(i);  // Treat the number as unsigned
        std::string result;
        do {
            result = digits[value % radix] + result;
            value /= radix;
        } while (value > 0);
        return result;
    }

    static Integer valueOf(int i){
        return *(new Integer(i));
    }

    static Integer valueOf(const std::string& str){
        return *(new Integer(str));
    }

    static Integer valueOf(const std::string& str, int radix) {
        if (radix < 2 || radix > 36) {
            throw std::invalid_argument("Radix must be between 2 and 36.");
        }

        const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
        bool isNegative = false;
        size_t startIdx = 0;

        if (str[0] == '-' && radix == 10) {
            isNegative = true;
            startIdx = 1;
        }

        unsigned int value = 0;

        for (size_t i = startIdx; i < str.length(); ++i) {
            char c = std::tolower(str[i]);
            int digit = -1;

            for (int j = 0; j < radix; ++j) {
                if (digits[j] == c) {
                    digit = j;
                    break;
                }
            }

            if (digit == -1) {
                throw std::invalid_argument("Invalid character for the specified radix.");
            }

            value = value * radix + digit;
        }

        if (isNegative) {
            return Integer(-static_cast<int>(value));
        } else {
            return Integer(static_cast<int>(value));
        }
    }


    /*
     * Works similar as to java.lang.Object.toString() in a way that you don't have to use a getter to obtain
     * the value(s) within the object when printing it out
     * @since 0.1
     */
    friend std::ostream& operator<<(std::ostream& os, const Integer* intObj) {
        if (intObj) {
            os << *intObj->value;
        } else {
            os << "NULL";
        }
        return os;
    }

    /*
     * Acts as the c++ equivalent of java's Object.equals() function when comparing objects
     * @since 0.1
     */
    bool operator==(const Integer* anotherInteger){
        return (*this->value == *anotherInteger->value) || (this == anotherInteger);
    }

    /*DECONSTRUCTOR*/
    ~Integer(){
        delete this->value;
    }
};
#endif //WRAPPERS_INTEGER_H
