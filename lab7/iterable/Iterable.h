//
// Created by wojciechsalapatek on 26.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <memory>
#include <string>
#include <vector>

using std::string;
using std::unique_ptr;

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

    class IterableIteratorWrapper{
    public:
        explicit IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other) const;
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();

        const unique_ptr<IterableIterator> &getIterator() const;

    private:
        unique_ptr<IterableIterator> iterator;
    };

    class Iterable{
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const = 0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const = 0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
    };

    class Zipper : public Iterable{
    public:
        Zipper(const std::vector<int> &one, const std::vector<string> &two);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        ZipperIterator iterator;
        std::vector<int> one;
        std::vector<string> two;
    };


    class Enumerate : public Zipper{
    public:
        explicit Enumerate(const std::vector<string> &elements);

    private:
        std::vector<int> initalizeVecotr(int size);

    };

    class Product : public Zipper{
    public:
        Product(const std::vector<int> &one, const std::vector<string> &two);
    private:
        std::pair<std::vector<int>, std::vector<string>> setup(std::vector<int>, std::vector<string>);
    };
}

#endif //JIMP_EXERCISES_ITERABLE_H
