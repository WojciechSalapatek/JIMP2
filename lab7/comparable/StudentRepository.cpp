//
// Created by wojciechsalapatek on 09.04.18.
//

#include "StudentRepository.h"
#include<istream>
namespace academia {
    StudyYear::StudyYear() : year(1){}

    StudyYear::StudyYear(int year) : year(year){}

    bool StudyYear::operator==(const StudyYear &other) const {
        if(year == other.year) return true;
        return false;
    }

    bool StudyYear::operator<(const StudyYear &other) const {
        if (year < other.year) return true;
        return false;
    }

    StudyYear::operator int() const {
        return year;
    }

    StudyYear StudyYear::operator++() {
        year++;
        return StudyYear(year);
    }

    StudyYear StudyYear::operator--() {
        year--;
        return StudyYear(year);
    }

    /*std::ostream &StudyYear::operator<<(std::ostream &out, const StudyYear &studyYear) {
        out<<std::to_string(year);
        return out;
    }

    std::istream &StudyYear::operator>>(std::istream &input, StudyYear &studyYear) {
        input >> year;
        return input;
    }*/

    Student::Student() : id(""), first_name(""), last_name(""), program(""), study_year(1){}

    Student::Student(string id, string first, string last, string program, int j) : id(id), first_name(first), last_name{last}, program{program}, study_year(j){}

    const string &Student::Id() const {
        return id;
    }

    const string &Student::FirstName() const {
        return first_name;
    }

    const string &Student::LastName() const {
        return last_name;
    }

    const string &Student::Program() const {
        return program;
    }

    const StudyYear &Student::Year() const {
        return study_year;
    }

    void Student::ChangeLastName(const string &last_name) {
        Student::last_name = last_name;
    }

    bool Student::operator==(const Student &other) const {
        return (first_name == other.first_name && last_name == other.last_name && program == other.program && study_year == other.study_year);

    }

    bool Student::operator!=(const Student &other) const {
        if(*this == other) return false;
        return true;
    }

    StudentRepository::StudentRepository() : studentCount(0){}

    StudentRepository::StudentRepository(std::initializer_list<Student> el): rep{el} {
        studentCount = (int) el.size();
    }

    int StudentRepository::StudentCount() const {
        return studentCount;
    }

    Student& StudentRepository::operator[](const string &id) {
        for(auto &i: rep){
           if(i.Id() == id) return i;
        }
        //TODO
        //TROW EXEPTION
    }

    bool StudentRepository::operator==(const StudentRepository &other) const{
        return (rep == other.rep);
    }
}