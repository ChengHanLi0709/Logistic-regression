#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cmath>
#include <vector>
#include "LogisticRegression.h"

float LogisticRegression::CrossEntropy(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta){
    
}
Eigen::MatrixXd LogisticRegression:: Sigmoid(Eigen::MatrixXd Z){
        return 1/ (1+ ((-Z.array()).exp()));
}
double LogisticRegression ::LossFunction(){

}

std::tuple <Eigen::MatrixXd, double, double> LogisticRegression::Propagation(Eigen::MatrixXd W, double b, Eigen::MatrixXd X, Eigen::MatrixXd y, double lambda){
        int m = y.rows();
        Eigen::MatrixXd Z = (W.transpose() * X.transpose()).array() +b;
        Eigen::MatrixXd A = Sigmoid(Z);

}





