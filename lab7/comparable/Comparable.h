//
// Created by wojciechsalapatek on 16.04.18.
//

#ifndef JIMP_EXERCISES_COMPARABLE_H
#define JIMP_EXERCISES_COMPARABLE_H

#include "StudentRepository.h"

using namespace academia;

namespace academia {
    class Comparator {
    public:
        static bool compare(const string & left, const string &right);
    };
    class Comparable {
    public:
        virtual bool IsLess(const Student &left, const Student &right)=0;

        bool operator()(const Student &left, const Student &right);

    };

    class ByFirstNameAscending : public Comparable{
    public:
        bool IsLess(const Student &left, const Student &right) override;

    };

    class ByFirstNameDescending : public Comparable{
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByLastNameAscending : public Comparable{
    public:
        bool IsLess(const Student &left, const Student &right) override;
    };

    class ByProgramAscendingEmptyFirst : public Comparable{
    public:
        bool IsLess(const Student &left, const Student &right) override;

    };

    class ByProgramAscendingEmptyLast : public Comparable{
    public:
        bool IsLess(const Student &left, const Student &right) override;

    };

}

#endif //JIMP_EXERCISES_COMPARABLE_H
