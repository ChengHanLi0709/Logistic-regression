#include <vector>
#include <string>
#include <unordered_set>
#include "LabelEncoder.h"

void LabelEncoder::GetCategory(std::vector<std::vector<std::string>>& Matrix, int Column ){
    for(const auto & c: Matrix){
        Category.insert(c[Column]);
    }
}


void LabelEncoder:: printCategory(){
    for (const auto & element : Category){
        std::cout << element << std::endl;
    }
}

void LabelEncoder::mapConstruct(int header){
    int i = header;
    for (auto element : Category){
        categoryMap[element] = std::to_string(i);
        i++;
    }
}

void LabelEncoder::mapCustom(std::string key, std::string value){
    categoryMap[key] = value;
    Category.insert(key);
}


void LabelEncoder::printMap(){
    for (const auto & c:categoryMap){
        std::cout << c.first << " : " << c.second << std::endl; 
    }
}


void LabelEncoder::encoding( std::vector<std::vector<std::string>>& Matrix, int column, bool drop){
    if (drop){
        for (auto& row : Matrix){
            row[column] = categoryMap[row[column]];
        }
    }
    else{
        for (auto& row : Matrix){
            row.push_back(categoryMap[row[column]]);
        }
    }
}
