#include <cmath>
#include "step.h"
using namespace std;

double g(double a, double b) {
    double r = step(a);
    double d = step(b);
    return sqrt(r + d);
}
