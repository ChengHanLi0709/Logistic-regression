#include <eigen3/Eigen/Dense>
#include "ETL.h"

#include <vector>
#include <stdlib.h>
#include <cmath>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::vector<std::string>> ETL:: readCSV(){
    std::ifstream file(dataset);
    std::vector<std::vector<std::string>> dataString;

    std::string line = "";

    while(getline(file, line)){
        std::vector <std::string> vec;
        
        // split by delimeter
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
        
        // strip string   str.erase(remove(str.begin(), str.end(), ' '), str.end());
        for (auto& s: vec){
            boost::trim(s);
        } 

        dataString.push_back(vec);
    }

    file.close();

    return dataString;

}


void ETL:: drop(std::vector< std::vector<std::string>>& Matrix, std::string target,int column){
    for (auto iter = Matrix.begin(); iter!=Matrix.end();){
        if (*(iter->begin()+column) == target){
            iter = Matrix.erase(iter);

        }
        else {
            iter++;
        }
    }
}



Eigen::MatrixXd ETL::toEigen(std::vector< std::vector<std::string>> dataset, int rows, int cols){
    if (header == true) {
        rows = rows-1;
    }

    Eigen::MatrixXd matrix(cols, rows);

    for(int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            matrix(j, i) = atof(dataset[i][j].c_str());
        }
    }
    return matrix.transpose();
}
