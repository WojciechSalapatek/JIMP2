//
// Created by wojciechsalapatek on 22.03.18.
//

#include "SimpleTemplateEngine.h"
using namespace nets;
namespace nets {
    View::View(string pat) {
        pattern = pat;
    }

    nets::View::~View() {

    }

    string View::GetPattern() const {
        return pattern;
    }

    void View::SetPattern(const string &pattern) {
        this->pattern = pattern;
    }

    std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::smatch matches;
        std::string result = "";
        string sketch = View::GetPattern();
        std::regex sub{"\\{\\{([^\\{\\}]*)\\}\\}"};
        while (std::regex_search(sketch, matches, sub)) {
            auto find = model.find(matches[1]);
            if (find != model.end()) {
                result += matches.prefix().str() + find->second;
            } else result += matches.prefix().str();

            sketch = matches.suffix().str();
        }
        result += sketch;

        return result;
    }
}
