#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
using namespace std;

vector<double> dense(
    const vector<double>& x,
    const double* W,
    const double* B,
    int input_size,
    int output_size,
    bool use_relu
);

double neuralNetwork(vector<double> x);

#endif