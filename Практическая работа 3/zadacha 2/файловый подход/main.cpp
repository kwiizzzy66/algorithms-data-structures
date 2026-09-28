#include <iostream>
#include <fstream>
#include "f.h"
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;
    out << Next(n);

    in.close();
    out.close();
    return 0;
}
