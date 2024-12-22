//
// Created by ebane on 12/22/2024.
//

#ifndef WRAPPERS_NUMBER_H
#define WRAPPERS_NUMBER_H


class Number{
public:
    auto byteValue() {
        #if __cplusplus < 201703L
                return static_cast<char>(this);
        #endif
    }

    virtual double doubleValue() = 0;
    virtual float floatValue() = 0;
    virtual int intValue() = 0;
    virtual long longValue() = 0;
    virtual short shortValue() = 0;

};



#endif //WRAPPERS_NUMBER_H
