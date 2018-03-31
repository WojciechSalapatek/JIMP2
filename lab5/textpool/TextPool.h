//
// Created by wojciechsalapatek on 31.03.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <experimental/string_view>
#include <set>

typedef std::experimental::string_view strv;
namespace pool {
    class TextPool {

    public:

        TextPool();


        ~TextPool();


        TextPool(TextPool &&other);


        TextPool &operator=(TextPool &&other);


        TextPool(std::initializer_list<std::string>);


        strv Intern(const std::string &str);


        size_t StoredStringCount() const;

    private:
        std::set<char*> data;
        int storedStrings;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
