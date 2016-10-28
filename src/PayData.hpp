
#ifndef PAY_DATA_HPP
#define PAY_DATA_HPP

#include <iostream>

#include "Serializable.hpp"

class PayData : public Serializable {
public:
        PayData(std::string &, int);
        PayData(const unsigned char *); // inflation constructor
        void inflate(const unsigned char *);
        void serialize(unsigned char *);
        int size();
        std::string getUsername();
        int getAmount();
private:
        std::string username;
	int amount;
};

#endif
