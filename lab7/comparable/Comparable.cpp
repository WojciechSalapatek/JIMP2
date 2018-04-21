//
// Created by wojciechsalapatek on 16.04.18.
//

#include "Comparable.h"
namespace academia {
    bool Comparator::compare(const string &left, const string &right) {
        for (int i = 0; i < std::min(left.length(), right.length()); ++i) {
            if (left[i] != right[i]) return (left[i] < right[i]);
        }
        return (right.length() > left.length());
    }

    bool Comparable::operator()(const Student &left, const Student &right) {
        return IsLess(left, right);
    }

    bool ByFirstNameAscending::IsLess(const Student &left, const Student &right) {
        return Comparator::compare(left.FirstName(), right.FirstName());

    }

    bool ByFirstNameDescending::IsLess(const Student &left, const Student &right) {
        return Comparator::compare(right.FirstName(), left.FirstName());
    }

    bool ByLastNameAscending::IsLess(const Student &left, const Student &right) {
        return Comparator::compare(left.LastName(), right.LastName());
    }

    bool ByProgramAscendingEmptyFirst::IsLess(const Student &left, const Student &right) {
        return Comparator::compare(left.Program(), right.Program());
    }

    bool ByProgramAscendingEmptyLast::IsLess(const Student &left, const Student &right) {
        if(left.Program().empty()) return false;
        return Comparator::compare(left.Program(), right.Program());
    }
}