//
// Created by wojciechsalapatek on 23.04.18.
//

#include "Pesel.h"
namespace academia {
    AcademiaDataValidationError::AcademiaDataValidationError(string what) : std::runtime_error(what) {}

    InvalidPeselLength::InvalidPeselLength(const string &pesel, int length) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") length: " + std::to_string(length)) {}

    InvalidPeselCharacter::InvalidPeselCharacter(const string &pesel) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") character set") {};

    InvalidPeselChecksum::InvalidPeselChecksum(const string &pesel, int checksum) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") checksum: " + std::to_string(checksum)) {}

    Pesel::Pesel(const string &pesel) {
        ValidatePesel(pesel);
        pesel_ = pesel;
    }

    void Pesel::ValidatePesel(const string &pesel) {
        int arrayOfChecksumVariables[] = {9, 7, 3, 1, 9, 7, 3, 1, 9, 7, 0};
        int checksum = 0;
        if (pesel.length() != 11) throw InvalidPeselLength(pesel, (int) pesel.length());
        for (int i = 0; i < pesel.length(); i++) {
                if(!isdigit(pesel[i])) throw InvalidPeselCharacter(pesel);
                checksum += (pesel[i] - '0') * arrayOfChecksumVariables[i];
            }
        checksum %= 10;
        if (pesel[10] - '0' != checksum) throw InvalidPeselChecksum(pesel, checksum);
    }


}
