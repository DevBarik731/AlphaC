#include <bits/stdc++.h>
#include "neural_network.h"
#include "nn_weights.h"

using namespace std;

vector<double> dense(
    const vector<double>& x,
    const double* W,
    const double* B,
    int input_size,
    int output_size,
    bool use_relu
)
{
    vector<double> result(output_size);

    for(int i = 0; i < output_size; i++)
    {
        result[i] = B[i];

        for(int j = 0; j < input_size; j++)
        {
            result[i] += W[j * output_size + i] * x[j];
        }

        if(use_relu)
        {
            result[i] = max(0.0, result[i]);
        }
    }

    return result;
}

double neuralNetwork(vector<double> x)
{
    // StandardScaler
    for(int i = 0; i < 9; i++)
    {
        x[i] = (x[i] - SCALER_MEAN[i]) / SCALER_SCALE[i];
    }

    // Dense 1: 9 -> 32
    x = dense(
        x,
        &W1[0][0],
        B1,
        9,
        32,
        true
    );

    // Dense 2: 32 -> 20
    x = dense(
        x,
        &W2[0][0],
        B2,
        32,
        20,
        true
    );

    // Dense 3: 20 -> 16
    x = dense(
        x,
        &W3[0][0],
        B3,
        20,
        16,
        true
    );

    // Output layer: 16 -> 1
    x = dense(
        x,
        &W4[0][0],
        B4,
        16,
        1,
        false
    );

    return x[0];
}