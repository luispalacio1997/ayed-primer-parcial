#ifndef VALIDATOR_H
#define VALIDATOR_H


#include <string>
#include <vector>
#include "IDataSource.h"


class Validator
{
private:
    IDataSource* dataSource;
    std::vector<std::string> errors;

    bool validateKey();
    bool validateValue();
    bool validateList();

public:
    Validator(IDataSource* source);
    bool validate();
    const std::vector<std::string>& getErrors() const;
};


#endif