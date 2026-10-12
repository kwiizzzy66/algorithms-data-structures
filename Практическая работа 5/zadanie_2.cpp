//через циклы for
// #include <iostream>
// using namespace std;

// int main() {
//     int A, B;
//     cin >> A >> B;
    
//     int commands[10000];  // максимум шагов
//     int count = 0;
    
    
//     for (int i = 0; A > B; i++) {
//         if (A % 2 == 0 && A / 2 >= B) {
//             commands[count++] = 2;  // команда ":2"
//             A /= 2;
//         } else {
//             commands[count++] = 1;  // команда "-1"
//             A -= 1;
//         }
//     }

//     for (int i = 0; i < count; i++) {
//         if (commands[i] == 1) {
//             cout << "-1" << endl;
//         } else {
//             cout << ":2" << endl;
//         }
//     }
    
//     return 0;
// }


//через цикл while
// #include <iostream>
// using namespace std;

// int main() {
//     int A, B;
//     cin >> A >> B;

//     int n = A;
    
//     while (n > B) {
//         if (n % 2 == 0 && n / 2 >= B) {
//             cout << ":2" << endl;
//             n /= 2;
//         } else {
//             cout << "-1" << endl;
//             n -= 1;
//         }
//     }
    
//     return 0;
// }

// while и for вместе
// #include <iostream>
// using namespace std;

// int main() {
//     int A, B;
//     cin >> A >> B;

//     int commands[10000];
//     int count = 0;
    
//     while (A > B) {
//         if (A % 2 == 0 && A / 2 >= B) {
//             commands[count] = 2;  // ":2"
//             A /= 2;
//         } else {
//             commands[count] = 1;  // "-1"
//             A -= 1;
//         }
//         count++;
//     }
    
//     for (int i = 0; i < count; i++) {
//         if (commands[i] == 1) {
//             cout << "-1" << endl;
//         } else {
//             cout << ":2" << endl;
//         }
//     }
    
//     return 0;
// }