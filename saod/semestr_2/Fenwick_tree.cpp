#include <iostream>
#include <string.h>

// #include <bits/stdc++.h>
using namespace std;

int n;
int m;
int a[100000];  //массив
int f[100000];  //дерево Фенвика

//сумма элементов от 0 до x
int sum(int x) {
    int result = 0;

    for (; x >= 0; x = (x & (x + 1)) - 1) {
        result += f[x];
    }

    return result;
}

//сумма элементов от l до r
int sum(int l, int r) {
    if (l) {
        return sum(r) - sum(l - 1);
    } else {
        return sum(r);
    }
}

//увеличение a[idx] на delta
void increase(int idx, int delta) {
    a[idx] += delta;

    for (; idx < n; idx |= idx + 1) {
        f[idx] += delta;
    }
}

int main() {

    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {    //ввод массива и заполнение дерева Фенвика
        int t;
        cin >> t;
        increase(i, t);
    }

    //Можем обрабатывать запросы

    cout << "Enter count requests: ";
    cin >> m;

    if (m >= 1 && m <= 30000) {
        for (int i = 0; i < m; i++) {
            char c;
            cout << "Enter 's' for calculate sum or 'u' for update value: ";

            cin >> c;

            if (c != 's' && c != 'u') {
                cout << "ERROR!\n";
            } else {
                if (c == 's') {
                    int value_1, value_2;
                    // cout << "SUM: \n";
                    
                    
                    cout << "Enter range: \n";
                    
                    cout << "1 value: ";                    
                    cin >> value_1;

                    cout << "2 value: ";                    
                    cin >> value_2;

                    if (value_1 >= 0 && value_1 < (n - 1) && value_2 >= 0 && value_2 < n) {
                        int res = sum(value_1, value_2);
                        cout << "sum" << res << endl;

                    } else {
                        cout << "error!\n";
                    }



                } else {
                    // cout << "UPDATE: \n";
                    int index, value;


                    cout << "index: ";                    
                    cin >> index;

                    cout << "value: ";               
                    cin >> value;
                    if (index >= 0 && index < n) {
                        increase(index, value);
                    }
                }
            }
        }

    }


}

