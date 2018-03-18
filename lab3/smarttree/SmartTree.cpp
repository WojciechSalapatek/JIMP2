//
// Created by wojciechsalapatek on 18.03.18.
//

#include <iostream>
#include "SmartTree.h"
#include <cmath>


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

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){

    }
}

