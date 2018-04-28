//
// Created by wojciechsalapatek on 26.04.18.
//

#include <vector>
#include "Iterable.h"

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {
    begin1_ = left_begin;
    begin2_ = right_begin;
    end1_ = left_end;
    end2_ = right_end;
}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    return std::pair<int, string>(*begin1_,*begin2_);
}

utility::ZipperIterator &utility::ZipperIterator::Next() {
    begin1_ += 1;
    begin2_ += 1;
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    return other->Dereference() != this->Dereference();
}


