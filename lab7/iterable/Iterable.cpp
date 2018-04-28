//
// Created by wojciechsalapatek on 26.04.18.
//

#include <iostream>
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
    if(begin1_ == end1_ && begin2_ == end2_) return std::pair<int, string>(0,"");
    if (begin2_ == end2_) return std::pair<int, string>(begin1_.operator*()," ");
    return std::pair<int, string>(begin1_.operator*(),begin2_.operator*());
}

utility::ZipperIterator &utility::ZipperIterator::Next() {
    if(begin1_ != end1_) begin1_ += 1;
    if(begin2_  != end2_) begin2_ +=1;
    if(begin1_ == end1_ && begin2_ != end2_) begin1_--;
    if(begin2_ == end2_ && begin1_ != end1_) begin2_--;
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    return (other->Dereference().first != this->Dereference().first) || (other->Dereference().second != this->Dereference().second);
}


utility::IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator1) {iterator = std::move(iterator1);}

bool utility::IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) const{
    return iterator->NotEquals(other.iterator);
}

std::pair<int, std::string> utility::IterableIteratorWrapper::operator*() {
    return iterator->Dereference();
}

utility::IterableIteratorWrapper &utility::IterableIteratorWrapper::operator++() {
    *iterator = iterator->Next();
    return *this;
}

const unique_ptr<utility::IterableIterator> &utility::IterableIteratorWrapper::getIterator() const {
    return iterator;
}


utility::IterableIteratorWrapper utility::Iterable::cbegin() const {
    unique_ptr<IterableIterator> iterator = ConstBegin();
    IterableIteratorWrapper result = IterableIteratorWrapper(std::move(iterator));
    return result;
}

utility::IterableIteratorWrapper utility::Iterable::cend() const {
    unique_ptr<IterableIterator> iterator = ConstEnd();
    IterableIteratorWrapper result = IterableIteratorWrapper(std::move(iterator));
    return result;
}

utility::IterableIteratorWrapper utility::Iterable::begin() const {
    return cbegin();
}

utility::IterableIteratorWrapper utility::Iterable::end() const {
    return cend();
}

utility::Zipper::Zipper(const std::vector<int> &one, const std::vector<string> &two) : iterator(one.begin(), two.begin(), one.end(), two.end()){
    this->one = one;
    this->two = two;
}

unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    return std::make_unique<ZipperIterator>(one.begin(), two.begin(), one.end(), two.end());
}

unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    return std::make_unique<ZipperIterator>(one.end(), two.end(), one.end(), two.end());
}

std::vector<int> utility::Enumerate::initalizeVecotr(int size){
    std::vector<int> result;
    for(int i = 1; i<=size; i++) result.push_back(i);
    return result;
}

utility::Enumerate::Enumerate(const std::vector<string> &elements) : Zipper(initalizeVecotr((int) elements.size()), elements) {}


std::pair<std::vector<int>, std::vector<string>> utility::Product::setup(std::vector<int> ints, std::vector<string> strings) {
    std::vector<int> resultInts;
    std::vector<string> resultStrings;
    for (int i = 0; i < ints.size(); ++i) {
        for (int j = 0; j < strings.size(); ++j) {
            resultInts.push_back(ints[i]);
        }
    }
    for (int k = 0; k < ints.size(); ++k) {
        for (int i = 0; i < strings.size(); ++i) {
            resultStrings.push_back(strings[i]);
        }
    }
    return std::pair<std::vector<int>, std::vector<string>>(resultInts, resultStrings);
}

utility::Product::Product(const std::vector<int> &one, const std::vector<string> &two) : Zipper(setup(one,two).first, setup(one,two).second){}
