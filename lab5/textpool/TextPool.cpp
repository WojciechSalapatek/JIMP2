//
// Created by wojciechsalapatek on 31.03.18.
//

#include <iostream>
#include <cstring>
#include "TextPool.h"

typedef std::experimental::string_view strv;

namespace pool{
    TextPool::TextPool() {
        storedStrings = 0;
    }

    TextPool::TextPool(std::initializer_list<std::string> elements) {
        storedStrings = 0;
        bool find;
        char *tmp;
        for (auto i : elements){
            find = false;
            for(auto j:data) if(!strcmp(j,i.c_str())) find = true;
            if(!find) {
                tmp = new char[i.length()];
                strcpy(tmp, i.c_str());
                data.insert(tmp);
                storedStrings++;
            }
        }
    }

    TextPool::~TextPool() {
        for (auto i:data) delete [] i;
    }

    TextPool::TextPool(TextPool &&other) {
        char *tmp;
        storedStrings = other.storedStrings;
        for(auto i:other.data){
            tmp = new char[strlen(i)];
            strcpy(tmp,i);
            data.insert(tmp);
            other.data.erase(i);
            other.storedStrings--;
            delete [] i;
        }
    }

    TextPool& TextPool::operator=(TextPool &&other) {
        if (this == &other) return other;
        storedStrings = other.storedStrings;
        for (auto i:data) {
            data.erase(i);
            delete [] i;
        }
        char *tmp;
        for(auto i:other.data){
            tmp = new char[strlen(i)];
            strcpy(tmp,i);
            data.insert(tmp);
            other.data.erase(i);
            other.storedStrings--;
            delete [] i;
        }
    }

    size_t TextPool::StoredStringCount() const {
        return (size_t) storedStrings;
    }

    strv TextPool::Intern(const std::string &str) {
        for(auto j:data) if(!strcmp(j,str.c_str())) return j;
        char *tmp = new char[str.length()];
        strcpy(tmp,str.c_str());
        data.insert(tmp);
        storedStrings++;
        return tmp;
    }
}