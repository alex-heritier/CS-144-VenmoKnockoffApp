
#ifndef ADD_FUNDS_DATA_HPP
#define ADD_FUNDS_DATA_HPP

#include <iostream>

#include "Serializable.hpp"

class AddFundsData : public Serializable {
public:
        AddFundsData(std::string &, std::string &, int);
        AddFundsData(const unsigned char *); // inflation constructor
        void inflate(const unsigned char *);
        void serialize(unsigned char *);
        int size();
	std::string getUsername();
        std::string getFundTag();
        int getAmount();
private:
	std::string username;
        std::string fundTag;
        int amount;
};

#endif

