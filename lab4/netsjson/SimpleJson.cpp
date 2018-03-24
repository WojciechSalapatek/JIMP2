//
// Created by wojciechsalapatek on 24.03.18.
//

#include <iostream>
#include "SimpleJson.h"

namespace nets{
    JsonValue::JsonValue(){
        theCase = 0;
    }

    JsonValue::~JsonValue() {

    }

    JsonValue::JsonValue(int value){
        theCase = 1;
        this->intV = value;
    }

    JsonValue::JsonValue(double value){
        theCase = 2;
        this->doubleV = value;
    }

    JsonValue::JsonValue(const std::string value){
        theCase = 3;
        this->stringV = value;
    }

    JsonValue::JsonValue(bool value){
        theCase = 4;
        this->boolV = value;
    }

    JsonValue::JsonValue(std::vector<JsonValue> values){
        theCase = 5;
        this->array = values;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> map){
        theCase = 6;
        this->map = map;
    }

    int JsonValue::GetTheCase() const {
        return theCase;
    }

    int JsonValue::GetIntV() const {
        return intV;
    }

    double JsonValue::GetDoubleV() const {
        return doubleV;
    }

    const std::string &JsonValue::GetStringV() const {
        return stringV;
    }

    bool JsonValue::GetBoolV() const {
        return boolV;
    }

    const std::vector<JsonValue> &JsonValue::GetArray() const {
        return array;
    }

    const std::map<std::string, JsonValue> &JsonValue::GetMap() const {
        return map;
    }

    std::string JsonValue::ToString() const{
        if(GetTheCase() == 1) return std::to_string(GetIntV());
        else if(GetTheCase() == 2) {
            std::string result =  std::to_string(GetDoubleV());
            for (int i = result.length() -1 ; i > 0 ; --i) if(result[i] != '0') return result.substr(0,i+1);
        }
        else if(GetTheCase() == 3) {
            std::string result = "";
            std::string str = GetStringV();
            for (int i = 0; i < str.length(); ++i) {
                if(str[i] == '"' || str[i] == '\\') result += R"(\)";
                result += str[i];
            }
            return "\"" + result + "\"";
        }
        else if(GetTheCase() == 4) {
            if (GetBoolV() == false) return "false";
            else if (GetBoolV() == true) return "true";
            else return "";
        }
        else if(GetTheCase() == 5){
            std::string result = "[";
            for(auto i : GetArray()) result += i.ToString()+ ", ";
            result = result.substr(0,result.length()-2) + "]";
            return result;
        }
        else if(GetTheCase() == 6){
            std::string result = "{";
            for(auto i : GetMap()) {
                result += R"(")";
                for (auto j : i.first){
                    if(j == '"' || j== '\\') result += R"(\)";
                    result += j;
                }
                result += R"(": )" + i.second.ToString() + R"(, )";
            }
            result = result.substr(0,result.length()-2) + "}";
            return result;
        }
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        return GetMap().find("a")->second;

    }


}