//
// Created by wojciechsalapatek on 22.03.18.
//

#include "SimpleTemplateEngine.h"
using namespace nets;
nets::View::View(string pat) {
    pattern = pat;
}

nets::View::~View() {

}

string View::GetPattern() const {
    return pattern;
}

void View::SetPattern(const string &pattern){
    this->pattern = pattern;
}

std::string nets::View::Render(const std::unordered_map <std::string, std::string> &model) const {
    std::smatch matches;
    string result = View::GetPattern();
    for (auto i: model){
        std::regex sub {"\\{\\{" + i.first + "\\}\\}"};
        while(std::regex_search(result, matches, sub)) result = matches.prefix().str() + i.second + matches.suffix().str();
    }
    std::regex missing("\\{\\{[^\\{\\}]*\\}\\}");
    if(std::regex_search(result, matches, missing)) result = matches.prefix().str() + matches.suffix().str();
    cout<<matches[0]<<endl;
    return result;
}
