#1
#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter n : " << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j < n - 1)
				cout << 0;
			else if (i + j == n - 1)
				cout << 1;
			else
				cout << 2;

		}
		cout << endl;
	}
	return 0;

}
#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter n : " << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i-1; j++)
			cout << 0;

		cout << 1;

		for (int j = 0; j < i; j++)
			cout << 2;

		cout << endl;

	}

	return 0;
}

#2
#include <iostream> 
using namespace std; 

int main() { 
    int n, m, w; 
    cin >> n >> m >> w; 

    char a[32][32]; 

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            a[i][j] = '0'; 
        }
    }

    for (int i = 0; i < w; i++) { 
        int x, y; 
        cin >> x >> y;
        a[x - 1][y - 1] = '*'; 
    }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (a[i][j] == '*') { 
                cout << '*';
            }
            else { 
                int k = 0; 

                for (int x = i - 1; x <= i + 1; x++) { 
                    for (int y = j - 1; y <= j + 1; y++) { 
                        if (x >= 0 && x < n && y >= 0 && y < m) { 
                            if (a[x][y] == '*') { 
                                k++; 
                            }
                        }
                    }
                }

                cout << k; 
            }
        }
        cout << endl; 
    }

    return 0; 
}


#3
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    string x; 
    int n; 
    cin >> x >> n; 

    for (int k = 1; k < n; k++) { 
        string s = ""; 
        for (int i = 0; i < x.size(); i++) { 
            int count = 1; 

            while (i + 1 < x.size() && x[i] == x[i + 1]) { 
                count++;
                i++; 
            }

            s += to_string(count); 
            s += x[i]; 
        }

        x = s; 
    }

    cout << x; 
    return 0;
}