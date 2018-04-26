//
// Created by wojciechsalapatek on 23.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

using std::string;

namespace academia {
    class Pesel {
    public:
        Pesel(const string &pesel);
        void ValidatePesel(const string &pesel);

    private:
        string  pesel_;


    };

    class AcademiaDataValidationError : public std::runtime_error{
    public:
        AcademiaDataValidationError(string what);

    };

    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const string &pesel, int checksum);
    };

    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength(const string &pesel, int length);

    };

    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(const string &pesel);
    };


}



#endif //JIMP_EXERCISES_PESEL_H
