//
// Created by wojciechsalapatek on 09.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <vector>
#include "StudentRepositoryQueries.h"
#include <memory>
using std::string;

namespace academia {
    class Query;
    class StudyYear{
    public:
        StudyYear();
        StudyYear(int year);
        bool operator==(const StudyYear& other) const;
        operator int() const ;
        bool operator<(const StudyYear& other) const;
        StudyYear operator++();
        StudyYear operator--();

    private:
        int year;
    };

    class Student {
    public:
        Student();
        Student(string id, string first, string lastst, string program, int year);

        const string &Id() const;
        const string &FirstName() const;
        const string &LastName() const;
        const string &Program() const;
        const StudyYear &Year() const;

        void ChangeLastName(const string &last_name);

        bool operator==(const Student& other) const;
        bool operator!=(const Student& other) const;

    private:
        string id;
        string first_name;
        string last_name;
        string program;
        StudyYear study_year;
    };

    class StudentRepository{
    public:
        StudentRepository();

        StudentRepository(std::initializer_list<Student>);

        int StudentCount() const;
        Student & operator[](const string &id) ;
        bool operator==(const StudentRepository &other) const;

        std::vector<Student> FindByQuery(std::unique_ptr<Query> query);

    private:
        int studentCount;
        std::vector<Student> rep;
    };
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
