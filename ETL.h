#ifndef _ETL_H_
#define _ETL_H_

#include <eigen3/Eigen/Dense>
#include <fstream>
#include <vector>
class ETL {
    std::string dataset;
    std::string delimeter;
    bool header;

public:
    ETL(std::string data, std::string separator, bool head=false) : dataset(data), delimeter(separator), header(head){}
    std::vector<std::vector<std::string>>readCSV();
    void drop(std::vector< std::vector<std::string>>& dataset, std::string target,int column);
    Eigen::MatrixXd toEigen(std::vector< std::vector<std::string>> dataset, int rows, int cols);
    

};


#endif