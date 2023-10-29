#ifndef LogisticRegression_H
#define LogisticRegression_H

#include <eigen3/Eigen/Dense>

class LogisticRegression {
    public:

    LogisticRegression(){

    }
    float LogisticRegression::CrossEntropy(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta){}


    Eigen::MatrixXd Sigmoid(Eigen::MatrixXd Z);

    std::tuple <Eigen::MatrixXd, double, double> Propagation(Eigen::MatrixXd W, double b, Eigen::MatrixXd Z, Eigen::MatrixXd y, double lambda);
    double LossFunction();
};

#endif