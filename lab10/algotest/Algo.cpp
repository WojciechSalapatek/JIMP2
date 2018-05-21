//
// Created by wojciechsalapatek on 15.05.18.
//

#include <map>
#include "Algo.h"

void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
    std::copy(v.begin(), v.begin() + n_elements, back_inserter(*out));
}

void algo::InitializeWith(int initial_value, std::vector<int> *v) {
    std::transform(v->begin(), v->end(), v->begin(),
                   [initial_value](auto v){ return initial_value;});
}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value) {
    std::vector<int> result (length);
    std::transform(result.begin(), result.end(), result.begin(),
                   [initial_value](auto v){ return initial_value;});
    return result;
}

std::vector<std::string> algo::MapToString(const std::vector<double> &v) {
    std::vector<std::string> result;
    std::transform(v.begin(), v.end(), back_inserter(result),
    [](double current){return std::to_string(current);});
    return result;
}

std::vector<int> algo::DivisableBy(const std::vector<int> &m, int divisor) {
    std::vector<int> result;
    std::copy_if(m.begin(),m.end(), back_inserter(result),
                 [divisor](int  current) { return (current%divisor==0);});
    return result;
}

int algo::Sum(const std::vector<int> &v) {
    return std::accumulate(v.begin(), v.end(), 0);
}

int algo::Product(const std::vector<int> &v) {
    return std::accumulate(v.begin(), v.end(), 1, std::multiplies<>());
}


