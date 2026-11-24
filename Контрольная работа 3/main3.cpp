#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    
    cout << "vvedite str: ";
    getline(cin, text);
    
    cout << "dlina str: " << text.length() << endl;
    
    return 0;
}