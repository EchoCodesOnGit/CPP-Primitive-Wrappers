//
// Created by ebane on 12/24/2024.
//

#ifndef WRAPPERS_BYTE_H
#define WRAPPERS_BYTE_H

#include "../../class_necessities.h"
class Byte{
private:
    #if __cplusplus < 201703L
        char* value;
    #elif __cplusplus >= 201703L
        std::byte* value;
    #endif
        size_t size{};
public:
    /*PUBLIC FIELDS*/
    static constexpr int BYTE = sizeof(
            #if __cplusplus < 201703L
                char
            #elif __cplusplus >= 201703L
                std::byte
            #endif
            );
    static constexpr int MAX_SIZE = 127;
    static constexpr int MIN_SIZE = -128;
    static constexpr int SIZE = sizeof(
            #if __cplusplus < 201703L
                        char
            #elif __cplusplus >= 201703L
                        std::byte
            #endif
            ) * 8;
    //static Class<Byte>
    /*END PUBLIC FIELDS*/

    /*CONSTRUCTORS*/
    #if __cplusplus < 201703L
        explicit Byte(char value){
            this->value = new char(value);
        }
    #elif __cplusplus >= 201703L
        explicit Byte(std::byte value){
            this->value = new std::byte(value);
        }
    #endif

    explicit Byte(const std::string& str) : size(str.size()) {
        #if __cplusplus < 201703L
            value = new char[size];
            for (size_t i = 0; i < size; ++i) {
                value[i] = str[i];
            }
        #elif __cplusplus >= 201703L
            value = new std::byte[size];
            for (size_t i = 0; i < size; ++i) {
                value[i] = static_cast<std::byte>(str[i]);
            }
        #endif
    }
    /*valueOf method is preferred to that of a constructor*/
    #if __cplusplus < 201703L
        static Byte valueOf(char value){
            return *new Byte(value);
        }
    #elif __cplusplus >= 201703L
        static Byte valueOf(std::byte value){
            return *new Byte(value);
        }
    #endif

    static Byte valueOf(const std::string& valueStr){
        try{
            int intVal = std::stoi(valueStr);
            if(intVal < 0 || intVal > 255){
                throw std::out_of_range("Value out of range for a byte variable");
            }
            return *new Byte(static_cast<std::byte>(intVal));
        } catch(const std::exception& e){
            throw std::invalid_argument("Invalid input for string for conversion to byte variable");
        }
    }
    static Byte valueOf(const std::string& valueStr, int radix){
        try{
            int intVal = std::stoi(valueStr, nullptr, radix);
            if(intVal < 0 || intVal > 255){
                throw std::out_of_range("Value out of range for a byte variable");
            }
            return *new Byte(static_cast<std::byte>(intVal));
        } catch(const std::exception& e){
            throw std::invalid_argument("Invalid input for string for conversion to byte variable");
        }
    }
    /*END CONSTRUCTORS*/
    /*METHODS*/

    /*these methods and inline if statements are dependent on what version of c++ you use*/
    #if __cplusplus < 201703L //use of char as byte
        char byteValue(){
            return static_cast<char>(*this->value);
        }
        static int compare(char x, char y){
            return x > y ? 1 : x < y ? -1 : 0;
        }
        static char parseByte(const std::string& s){
            return static_cast<char>(std::stoi(s));
        }
        static char parseByte(const std::string& s, int radix){
            return static_cast<char>(std::stoi(s. nullptr, radix));
        }
    #elif __cplusplus >= 201703L //use of std::byte
        std::byte byteValue(){
            return static_cast<std::byte>(*this->value);
        }
        static int compare(std::byte x, std::byte y){
            return x > y ? 1 : x < y ? -1 : 0;
        }
        static std::byte parseByte(const std::string& s) {
            return static_cast<std::byte>(std::stoi(s));
        }
        static std::byte parseByte(const std::string& s, int radix) {
            return static_cast<std::byte>(std::stoi(s, nullptr, radix));
        }
    #endif

    int compareTo(Byte* anotherByte){
        return *anotherByte->value > *this->value ? 1 : *anotherByte->value < *this->value ? -1 : 0;
    }
    static Byte decode(const std::string& nm){
        try {
            return *(new Byte(nm));
        } catch (const std::invalid_argument& iaExcept) {
            std::cerr << "Invalid argument - " << iaExcept.what() << '\n';
            return *(new Byte(static_cast<
                                            #if __cplusplus < 201703L
                                                char
                                            #elif __cplusplus >= 201703L
                                                std::byte
                                            #endif
                                >(std::stoi(nm))));
        } catch (const std::out_of_range& oorExcept) {
            std::cerr << "Out of range - " << oorExcept.what() << '\n';
            return *(new Byte(static_cast<
                                            #if __cplusplus < 201703L
                                                 char
                                            #elif __cplusplus >= 201703L
                                                 std::byte
                                            #endif
                                         >(std::stoi(nm))));
        }
    }

    double doubleValue(){
        return static_cast<double>(*this->value);
    }
    float floatValue(){
        return static_cast<float>(*this->value);
    }

    int hashCode(){
        return std::hash<int>()(static_cast<int>(*this->value));
    }
    static int hashCode(
                            #if __cplusplus < 201703L
                                char value
                            #elif __cplusplus >= 201703L
                                std::byte value
                            #endif
                        ){
        return std::hash<int>()(static_cast<int>(value));
    }

    int intValue(){
        return static_cast<int>(*this->value);
    }

    long longValue(){
        return static_cast<long>(*this->value);
    }

    short shortValue(){
        return static_cast<short>(*this->value);
    }

    std::string toString() {
        return std::to_string(static_cast<char>(*this->value));
    }

    static std::string toString(
                                    #if __cplusplus < 201703L
                                        char value
                                    #elif __cplusplus >= 201703L
                                        std::byte value
                                    #endif
                                ){
        return std::to_string(static_cast<char>(value));
    }

    static int toUnsignedInt(
                                #if __cplusplus < 201703L
                                            char value
                                #elif __cplusplus >= 201703L
                                            std::byte value
                                #endif
                            ){
        return static_cast<int>(value);
    }
    static int toUnsignedLong(
                                #if __cplusplus < 201703L
                                            char value
                                #elif __cplusplus >= 201703L
                                            std::byte value
                                #endif
                                    ){
        return static_cast<long>(value);
    }
    /*END METHODS*/

    /*DECONSTRUCTOR*/
    ~Byte(){
        delete[] value;
    }
    /*END DECONSTRUCTOR*/

    /*COPY CONSTRUCTOR*/
    Byte(const Byte& other) : size(other.size) {
        #if __cplusplus < 201703L
            value = new char[size];
            for (size_t i = 0; i < size; ++i) {
                value[i] = other.value[i];
            }
        #elif __cplusplus >= 201703L
            value = new std::byte[size];
            for (size_t i = 0; i < size; ++i) {
                value[i] = other.value[i];
            }
        #endif
    }
    /*END COPY CONSTRUCTOR*/
    /*OVERLOADS*/
    friend std::ostream& operator<<(std::ostream& os, const Byte* byteObj) {
        if (byteObj && byteObj->value) {
            os << "0b";
            #if __cplusplus < 201703L
                std::bitset<8> bs(*byteObj->value);
                os << bs;
            #elif __cplusplus >= 201703L
                std::bitset<8> bs(std::to_integer<int>(*byteObj->value));
                os << bs;
            #endif
        } else {
            os << "NULL";
        }
        return os;
    }
    /*END OVERLOADS*/

    /*ASSIGNMENT*/
    Byte& operator=(const Byte& other) {
        if (this == &other) {
            return *this;
        }
        delete[] value;
        size = other.size;
        #if __cplusplus < 201703L
            value = new char[size];
            for (size_t i = 0; i < size; ++i) {
                value[i] = other.value[i];
            }
        #elif __cplusplus >= 201703L
            value = new std::byte[size];
            for (size_t i = 0; i < size; ++i) {
                value[i] = other.value[i];
            }
        #endif
            return *this;
    }
    /*END ASSIGNMENT*/
};


#endif //WRAPPERS_BYTE_H
