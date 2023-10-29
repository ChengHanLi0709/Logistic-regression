#include "ETL.h"

#include <iostream>
#include <string>
#include <eigen3/Eigen/Dense>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "LabelEncoder.h"





int main(){

    // Load data
    ETL etl("census+income/adult.data", ",");
    std::vector<std::vector<std::string>> dataset = etl.readCSV();
    int rows = dataset.size();
    int cols = dataset[0].size();
    std::cout << "Number of data: " << rows << std::endl; 


    // Drop missing value
    for (int i =0; i< cols;i++){
        etl.drop(dataset, "?", i);
    }

    rows = dataset.size();
    cols = dataset[0].size();
    std::cout << "Number of data: " << rows << std::endl; 


    // Label encoding
    std::vector<int> column_index = {1,3,5,6,7,8,9,13}; 
    for (auto index : column_index){
        LabelEncoder L;
        L.GetCategory(dataset, index);
        L.mapConstruct();
        L.encoding(dataset, index);
    }

    // Encoding label
    LabelEncoder L;
    L.GetCategory(dataset, 14);
    L.mapConstruct(0);
    L.encoding(dataset, 14);
    L.printMap();

    // Convert vector to Eigen 
    Eigen::MatrixXd dataMat = etl.toEigen(dataset, rows, cols);






    return EXIT_SUCCESS;

}