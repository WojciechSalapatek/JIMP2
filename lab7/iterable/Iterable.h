//
// Created by wojciechsalapatek on 26.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <memory>
#include <string>

using std::string;

namespace utility {
    class IterableIterator {
    public:
        virtual ~IterableIterator() = default;
        virtual std::pair<int, std::string> Dereference() const = 0;
        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const = 0;

    };

    class ZipperIterator : public IterableIterator{
    public:
        ~ZipperIterator() = default ;
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        std::pair<int, std::string> Dereference() const override ;
        ZipperIterator &Next() override ;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override ;

    private:
        std::vector<int> ::const_iterator begin1_;
        std::vector<string> ::const_iterator begin2_;
        std::vector<int> ::const_iterator end1_;
        std::vector<string> ::const_iterator end2_;
    };

    class Zipper{

    };
}

#endif //JIMP_EXERCISES_ITERABLE_H
