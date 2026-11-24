#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream filein("input.txt"); 
    ofstream fileout("output.txt"); 

    int x, sum = 0, count = 0;

    while (filein >> x) {
        sum += x;
        count++;
    }

    if (count > 0) {
        fileout << (double)sum / count;
    } else {
        fileout << "file pust";
    }

    return 0;
}