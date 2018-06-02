//
// Created by wojciechsalapatek on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <iostream>
#include <strstream>

namespace factoryMethod {
    template  <typename T> T Create(){
      return T();
    }

    class MyType{
    public:
        std::string SayHello(){ return "hello";}
    };

    template <typename T> auto Value(T pointer){
        return pointer.operator*();
    }

    class Logger{
    public:
        Logger(){level_ = 0;}
        template <typename T, typename S> void Debug(T out, S msg){
            if (level_ == 0) *out<<msg;
        }

        template <typename T, typename S> void Info(T out, S msg){
            if (level_ < 2) *out<<msg;
        }

        template <typename T, typename S> void Warning(T out, S msg){
            if (level_ < 3 ) *out<<msg;
        }

        template <typename T, typename S> void Error(T out, S msg){
            *out<<msg;
        }
        void SetLevel(int level) {level_ = level;}
    private:
        int level_;

    };

    class Buffor{
    private:
        Logger logger_;
    public:
        Buffor(){logger_ = Logger();}
        void CheckLogger(){
            for (int i = 0; i < 4; ++i) {
                std::strstream str;
                logger_.SetLevel(i);
                logger_.Debug(&str, "Debug, ");
                logger_.Info(&str, "Info, ");
                logger_.Warning(&str, "Warning, ");
                logger_.Error(&str, "Error, ");
                std::cout<<"Level: "<<i<<" : "<<str.str()<<std::endl;
            }
        }
    };
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
