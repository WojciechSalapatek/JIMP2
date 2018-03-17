//
// Created by wojciechsalapatek on 16.03.18.
//

#include "TinyUrl.h"
using namespace std;
namespace tinyurl {
    std::unique_ptr<TinyUrlCodec> Init(){
        unique_ptr<TinyUrlCodec> point = make_unique<TinyUrlCodec>();
        for (int i = 0; i <5; ++i) {
            point->state[i] = '0';
        }
        return point;
    }

    void CheckEndValues(std::array<char, 6> *state, int it);

    void NextHash(std::array<char, 6> *state) {
        state[0][5]++;
        CheckEndValues(state, 5);
    }

    void CheckEndValues(std::array<char, 6> *state, int it) {
        if(it<0) return;
        if (state[0][it] == 58) {
            state[0][it] = 65;
        }
        else if (state[0][it] == 91) {
            state[0][it] = 97;
        }
        else if (state[0][it] == 123){
            state[0][it] = '0';
            state[0][it-1]++;
            CheckEndValues(state, it-1);
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        string result = "";
        NextHash(&(codec->get()->state));
        for (auto i :codec->get()->state) result+=i;
        codec->get()->conv.emplace(result, url);
        return result;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        return  codec.get()->conv[hash];

    }
}