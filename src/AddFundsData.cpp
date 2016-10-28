
#include <iostream>

#include "AddFundsData.hpp"
#include "CommandData.hpp"

using namespace std;

AddFundsData::AddFundsData(string &fundTag, int amount): fundTag(fundTag), amount(amount) {}

AddFundsData::AddFundsData(const unsigned char *raw_data)
{
	inflate(raw_data);
}

void AddFundsData::inflate(const unsigned char *raw_data)
{
	fundTag = string(reinterpret_cast<const char *>(raw_data), FIELD_SIZE);
        raw_data += FIELD_SIZE;
        amount = deserialize_int(raw_data);
}

void AddFundsData::serialize(unsigned char *buf)
{
	char padded_field[FIELD_SIZE];
        
        // username
        memset(padded_field, 0, sizeof(padded_field));
        strncpy(padded_field, fundTag.c_str(), fundTag.length() + 1);
        buf = serialize_char_array(buf, padded_field, sizeof(padded_field));
        // amount
        buf = serialize_int(buf, amount);
}

int AddFundsData::size()
{
	return FIELD_SIZE + sizeof(int);
}

string AddFundsData::getFundTag()
{
	return fundTag;
}

int AddFundsData::getAmount()
{
	return amount;
}
