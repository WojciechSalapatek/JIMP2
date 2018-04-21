//
// Created by wojciechsalapatek on 17.04.18.
//

#include "StudentRepositoryQueries.h"

bool academia::ByFirstName::Accept(const academia::Student &student) const{
    return Query::Accept(student);
}

academia::ByFirstName::ByFirstName(const string &name_) : name_(name_) {}

bool academia::ByLastName::Accept(const academia::Student &student) const{
    return Query::Accept(student);
}

academia::ByLastName::ByLastName(const string &name_) : name_(name_) {}

bool academia::ByOneOfPrograms::Accept(const academia::Student &student) const{
    return Query::Accept(student);
}

academia::ByOneOfPrograms::ByOneOfPrograms(const string &name_) : name_(name_) {}

bool academia::ByYearLowerOrEqualTo::Accept(const academia::Student &student) const{
    return Query::Accept(student);
}

bool academia::OrQuery::Accept(const academia::Student &student) const {
    return Query::Accept(student);
}

bool academia::AndQuery::Accept(const academia::Student &student) const {
    return Query::Accept(student);
}
