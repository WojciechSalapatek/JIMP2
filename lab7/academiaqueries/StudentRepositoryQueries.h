//
// Created by wojciechsalapatek on 17.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H


#include "StudentRepository.h"

namespace academia {
    class Student;
    class Query {
    public:
       virtual bool Accept(const Student &student) const {}
    };

    class ByFirstName : public Query{
    public:
        bool Accept(const Student &student) const override;

    private:
        std::string name_;
    public:
        ByFirstName(const std::string &name_);
    };




    class ByLastName : public Query{
    public:
        ByLastName(const std::string &name_);

        bool Accept(const Student &student) const override;
    private:
        std::string name_;
    };


    class ByOneOfPrograms : public Query{
    public:
        bool Accept(const Student &student)const override;
    private:
        std::string name_;
    public:
        ByOneOfPrograms(const std::string &name_);
    };

    class ByYearLowerOrEqualTo : public Query{
    public:
        bool Accept(const Student &student)const override;
    };

    class OrQuery : public Query{
    public:
        bool Accept(const Student &student)const override;
    };

    class AndQuery : public Query{
        bool Accept(const Student &student)const override;
    };
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
