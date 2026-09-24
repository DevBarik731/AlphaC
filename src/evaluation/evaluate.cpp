#include "evaluate.hpp"
#include "features.hpp"
#include "../../Neural_Network/neural_network.h"
#include <vector>

using namespace std;

double evaluate(Board &board)
{
    vector<double> features = getFeatures(board);

    return neuralNetwork(features);
}