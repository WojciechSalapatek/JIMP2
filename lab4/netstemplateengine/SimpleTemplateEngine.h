//
// Created by wojciechsalapatek on 22.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <iostream>
#include <unordered_map>
#include <regex>
#include <regex.h>

using std::string;
using std::cout;
using std::endl;


namespace nets{
    class View {
    public:

        View(string pat);

        ~View();

        string GetPattern() const;


        void SetPattern(const string &pattern) ;

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    private:
        string pattern;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
