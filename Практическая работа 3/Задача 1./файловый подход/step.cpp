#include <cmath>
#include "stepenb.h"
using namespace std;

double gipo(double a, double b) {
    double r = stepenb(a);
    double d = stepenb(b);
    return sqrt(r + d);
}
