//
// Created by wojciechsalapatek on 14.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <map>
#include <set>
#include <istream>

using std::string;
using std::map;
using std::pair;
using std::initializer_list;
using std::set;
using std::istream;

namespace datastructures {
    class Counts{
    public:
        Counts();
        Counts(int counts);

        int getCounts () const;
        Counts operator++();
        bool operator==(const Counts &other) const;
        bool operator==(int value) const;
        bool operator<(const Counts &other) const;
        bool operator>(const Counts &other) const ;
        operator int() const;

    private:
        int counts;
    };

    class Word{
    public:
        Word(const string &word);

        bool operator<(const Word &other) const;
        bool operator==(const Word &other) const;

        string getWord() const;
    private:
        string word;
    };

    class WordCounter {
    public:
        WordCounter();

        std::ostream &operator<<(std::ostream & out);

        Counts operator[](const string &index);

        static WordCounter FromInputStream(istream &input);

        void Add(const Word &word);

        WordCounter(initializer_list<Word> elements);

        int DistinctWords();

        int TotalWords();

        set<Word> Words();

    private:
        map<Word, Counts> data;
    };

}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
