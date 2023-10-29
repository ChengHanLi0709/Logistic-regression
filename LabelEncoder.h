#ifndef _LABELENCODER_H_
#define _LABELENCODER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
class LabelEncoder{
private:
    std::unordered_set<std::string> Category;
    std:: unordered_map <std::string, std::string> categoryMap;

public:

    LabelEncoder(){}

    void GetCategory(std::vector<std::vector<std::string>>& Matrix, int Column );
    void printCategory();
    void mapConstruct(int header=1);
    void mapCustom(std::string key, std::string value);
    void printMap();
    void encoding( std::vector<std::vector<std::string>>& Matrix, int column, bool drop =1);

};






#endif