//
// Created by wojciechsalapatek on 24.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets {
    class JsonValue {
    public:

        JsonValue();

        JsonValue(int value);

        JsonValue(double value);

        JsonValue(const std::string value);

        JsonValue(bool value);

        JsonValue(std::vector<JsonValue> values);

        JsonValue(std::map<std::string, JsonValue> map);

        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

        int GetTheCase() const;

        int GetIntV() const;

        double GetDoubleV() const;

        const std::string &GetStringV() const;

        bool GetBoolV() const;

        const std::vector<JsonValue> &GetArray() const;


        const std::map<std::string, JsonValue> &GetMap() const;


    private:
        int theCase;
        int intV;
        double doubleV;
        std::string stringV;
        bool boolV;
        std::vector<JsonValue> array;
        std::map<std::string, JsonValue> map;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
