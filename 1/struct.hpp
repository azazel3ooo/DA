#pragma once
#include <string>

const int KEY_LENGTH = 6;

struct TKeyValue{
    std::string value;
    unsigned int key;

    TKeyValue(){}
    TKeyValue(unsigned const key, const std::string &value) : key(key), value(value.substr(0, 64)){}
    TKeyValue(TKeyValue const &object){
        key = object.key;
        value = object.value;
    }
    TKeyValue & operator=(const TKeyValue & right){
            if (this == &right) {
                return *this;
            }
            value = right.value;
            key = right.key;
            return *this;
    }
};

std::ostream & operator<<(std::ostream &out, const TKeyValue &element){
    std::string string_key(KEY_LENGTH, '0');
    unsigned x = element.key;
    for (int i = 0; i < KEY_LENGTH; ++i){
        string_key[KEY_LENGTH - 1 - i] += x % 10;
        x /= 10;
    }
    out << string_key << "\t" << element.value;
    return out;
}
