//
// Created by wojciechsalapatek on 14.04.18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "WordCounter.h"

namespace datastructures{


    struct {
        bool operator()(std::pair<Word,Counts> a, std::pair<Word,Counts> b) const
        {
            return a.second.getCounts() < b.second.getCounts();
        }
    } Less;

    Counts::Counts(): counts(0) {}

    Counts::Counts(int counts): counts(counts) {}

    Counts Counts::operator++() {counts++;}

    bool Counts::operator==(const Counts &other) const {
        return (counts == other.counts);
    }

    bool Counts::operator==(int value) const {
        return (counts == value);
    }

    bool Counts::operator<(const Counts &other) const {
        return (counts < other.counts);
    }

    bool Counts::operator>(const Counts &other) const {
        return (counts > other.counts);
    }

    Counts::operator int() const {
        return counts;
    }

    int Counts::getCounts() const {
        return counts;
    }

    Word::Word(const string &word): word(word) {}


    string Word::getWord() const {
        return word;
    }

    bool Word::operator<(const Word &other) const {
        return  (other.getWord() < word);
    }

    bool Word::operator==(const Word &other) const {
        return (word == other.word);
    }

    WordCounter::WordCounter(){}

    std::ostream &WordCounter::operator<<(std::ostream &out) {
        std::vector<std::pair<Word,Counts>> tosort;
        for(auto i : data) tosort.push_back(i);
        std::sort(tosort.begin(), tosort.end(), Less);
        for(auto i : tosort) out<<i.first.getWord()<<" "<<i.second.getCounts()<<std::endl;
        return out;
    }


    Counts WordCounter::operator[](const string &index) {
        for(auto i : data) if (i.first.getWord() == index) return i.second;
        return 0;
    }

    void WordCounter::Add(const Word &word) {
        ++data[word];
    }

    WordCounter WordCounter::FromInputStream(istream &input) {
        WordCounter counter = WordCounter();
        string word;
        string parsedWord;
        while (input >> word) {
            parsedWord = "";
            for (auto i : word) if (isalnum(i) || i == '-') parsedWord += i;
            if (parsedWord != "") counter.Add(parsedWord);
        }
        return counter;
    }


        WordCounter::WordCounter(initializer_list <Word> elements){
        for(auto i : elements) Add(i);
    }

    int WordCounter::TotalWords() {
        int result = 0;
        for(auto i : data) result += i.second.getCounts();
        return result;
    }

    int WordCounter::DistinctWords() {
        return (int) data.size();
    }

    set<Word> WordCounter::Words() {
        set <Word> result {};
        for(auto i: data) result.insert(i.first);
        return result;
    }

}