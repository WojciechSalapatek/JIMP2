//
// Created by wojciechsalapatek on 18.03.18.
//

#include <iostream>
#include "SmartTree.h"
#include <vector>;


namespace datastructures{
    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value = value;
        leaf->left = nullptr;
        leaf->right = nullptr;
        return leaf;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left = std::move(left_subtree);
        return tree;
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right = std::move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if (unique_ptr->left != nullptr) PrintTreeInOrder(unique_ptr->left, out);
        *out<<unique_ptr->value<<", ";
        if (unique_ptr->right != nullptr) PrintTreeInOrder(unique_ptr->right, out);
    }

    int PrintTreeFromRoot(const std::unique_ptr<SmartTree> &unique_ptr, std::string &out){
        out += " [" + std::to_string(unique_ptr->value);
        if (unique_ptr->left != nullptr) PrintTreeFromRoot(unique_ptr->left, out);
        else out += " [none]";
        if (unique_ptr->right != nullptr) PrintTreeFromRoot(unique_ptr->right, out);
        else out += " [none]";
        out += "]";
    }


    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        std::string result="";
        std::string output="";
        PrintTreeFromRoot(tree, result);
        for (int i = 1; i < result.length(); ++i) output += result[i];
        return output;
    }

    std::string Reverse(std::string str) {
        int length = str.length();
        std::string result = str;
        for (int i=0;i<length;i++) result[length-i-1] = str[i];
        return result;
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){
        if (tree == "[none]") return nullptr;
        int nones = 0;
        int noNones = 0;
        bool startNumber = false;
        bool isNegative = false;
        int value = 0;
        std::string number = "";
        std::vector<std::unique_ptr <SmartTree>> list;
        std::unique_ptr <SmartTree> leaf;
        std::unique_ptr <SmartTree> tmp;
        for (int i = tree.length()-1; i >=0; --i) {
            if (tree[i] > 47 && tree[i] < 58) {
                startNumber = true;
                number += tree[i];
            }
            else if(tree[i] == 'e') nones++;
            else if(tree[i] == '-') isNegative = true;
            else {
                number = Reverse(number);
                if(startNumber){
                    if (isNegative) value = - std::stoi(number);
                    else value = std::stoi(number);

                    if(nones==2) {
                        leaf = CreateLeaf(value);
                        list.insert(list.begin(), CreateLeaf(value));
                        nones=0;
                        noNones = 0;

                    }
                    else if (nones==0) {
                        noNones++;
                        leaf = CreateLeaf(value);
                        if (noNones == 2){
                            leaf = InsertLeftChild(std::move(leaf), std::move(list[1]));
                            leaf = InsertRightChild(std::move(leaf), std::move(list[3]));
                        }
                        else{
                            list.insert(list.begin() + 2,InsertLeftChild(std::move(leaf), move(list[0])));
                            list.insert(list.begin() + 3, InsertRightChild(std::move(list[2]), move(list[1])));
                            list.erase(list.begin());
                            list.erase(list.begin());

                        }
                    }
                    else {
                        leaf = CreateLeaf(value);
                        list.insert(list.begin(), CreateLeaf(value));
                        if (list.size() == 3){
                            list[1] = InsertRightChild(std::move(list[1]), std::move(list[2]));
                            leaf = InsertLeftChild(std::move(leaf), std::move(list[1]));
                            list.clear();
                        }
                    }
                }
                startNumber = false;
                number = "";
                isNegative = false;
            }
        }
        std::cout<<DumpTree(leaf)<<std::endl;
        return leaf;
    }
}
