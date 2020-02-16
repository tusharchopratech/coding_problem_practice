//
// Created by Tushar on 27/12/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void P1S1(string s) {
    bool tmp[256] = {false};
    for (int i = 0; i < s.size(); i++) {
        int charASCII = s[i];
        charASCII -= 'a';
        if (tmp[charASCII]) {
            cout << "Not Unique" << endl;
            return;
        }
        tmp[charASCII] = true;
    }
    cout << "Unique" << endl;
}

void P1S2(string s) {
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        int charASCII = s[i];
        charASCII -= 'a';
        if ((tmp & (1 << charASCII)) > 0) {
            cout << "Not Unique" << endl;
            return;
        }
        tmp |= 1 << charASCII;
//        cout<<tmp<<endl;
    }
    cout << "Unique" << endl;
}

void P1Test() {
    P1S1("abcde");
    P1S1("ab&&");
    P1S2("abcde");
    P1S2("abqwertyy");
}

void P2S1(char *str) {

    int size = 0;
    char ch;
    ch = str[0];
    while (ch != '\0') {
        size++;
        ch = str[size];
    }
    int i = 0, j = size - 1;
    while (i < j) {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    for (int i = 0; i < size; i++) {
        cout << str[i];
    }
}

void P2Test() {
    string s = "Hello";
    P2S1(&s[0]);
}

void P3S1(string s1, string s2) {
    map<char, int> m, m2;
    for (int i = 0; i < s1.size(); i++) {
        m[s1[i]]++;
        m2[s2[i]]++;
    }
    for (auto t:m) {
        if (m[t.first] != m2[t.first]) {
            cout << "No Permutation";
            return;
        }
    }
    cout << "Yes Permutation";
}

void P3Test() {
    P3S1("abaa", "aaba");
}

void shift(string &basicString, int i) {
    int end = basicString.size() - 1;
    while (end - 2 >= i) {
        basicString[end] = basicString[end - 2];
        end--;
    }
}

void P4S1(string basicString) {
    cout << basicString << endl;
    for (int i = 0; i < basicString.size(); i++) {
        if (basicString[i] == ' ') {
            basicString[i] = '%';
            shift(basicString, i + 1);
            basicString[++i] = '2';
            basicString[++i] = '0';
        }
    }
    cout << basicString << endl;
}

void P4Test() {
    string s = "Mr John Smith    ";
    P4S1(s);
}

void P5S1(string basicString) {
    int rep = 1;
    string output = "";
    char last = basicString[0];
    for (int i = 1; i < basicString.size(); i++) {
        if (last == basicString[i]) {
            rep++;
        } else {
            output += last;
            output += to_string(rep);
            last = basicString[i];
            rep = 1;
        }
        if (i == basicString.size() - 1) {
            output += last + to_string(rep);
        }
    }

    cout << output;
}

void P5Test() {
    P5S1("abbcccccaaa");
}

void spiralMatrixTest() {

    vector<vector<int>> vec = {{1,  2,  3,  4,  1},
                               {5,  6,  7,  8,  1},
                               {9,  10, 11, 12, 1},
                               {13, 14, 15, 16, 1}};

    int k = 0, m = 4, l = 0, n = 5;
    int i;

    while (k < m && l < n) {

        for (i = k; i < n; i++) {
            cout << vec[k][i] << " ";
        }
        k++;

        for (i = k; i < m; i++) {
            cout << vec[i][n - 1] << " ";
        }
        n--;

        for (i = n - 1; i >= l; i--) {
            cout << vec[m - 1][i] << " ";
        }
        m--;
        for (i = m - 1; i >= k; i--) {
            cout << vec[i][l] << " ";
        }
        l++;
    }

}

void P6S1() {
    vector<vector<int>> a = {{1,  2,  3,  4},
                             {5,  6,  7,  8},
                             {9,  10, 11, 12},
                             {13, 14, 15, 16}};

    int f = 0, l = 3, i;
    while (f < l) {
        for (i = f; i < l; i++) {
            int of = i - f;
            int top = a[f][i];
            a[f][i] = a[i][l];
//            a[f][i] = a[f+of][l];
//            a[f+of][l] = a[l][l - of];
            a[i][l] = a[l][l - of];
            a[l][l - of] = a[l - of][f];
            a[l - of][f] = top;
        }
        f++;
        l--;
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void P6Test() {
    P6S1();
}

void zeroRowAndCol(vector<vector<int>> &a, int i, int j) {
    for (int k = 0; k < a.at(0).size(); k++) {
        a[i][k] = 0;
    }
    for (int k = 0; k < a.size(); k++) {
        a[k][j] = 0;
    }
}

void P7Test() {
    vector<vector<int>> a = {{1,  2,  3,  4,  1},
                             {5,  0,  7,  8,  1},
                             {9,  10, 11, 12, 1},
                             {13, 14, 15, 16, 1}};

    int flag = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.at(0).size(); j++) {
            if (a[i][j] == 0) {
                zeroRowAndCol(a, i, j);
                flag = 1;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.at(0).size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void P8S1() {
    string s1 = "waterbottle", s2 = "erbottlewat";
    swap(s1, s2);
    int i = 0;

    while (1) {
        if (s1[i] == s2[0]) {
            int tmp = 0;
            while ((i + tmp) < s1.size() && s1[i + tmp] == s2[tmp]) {
                tmp++;
            }
            if (tmp + i == s1.size()) {
                //half found
                bool isRotation = true;
                for (int k = 0; k < i; k++) {
                    if (s1[k] != s2[tmp + k]) {
                        isRotation = false;
                        break;
                    }
                }
                if (isRotation) {
                    cout << "Rotation";
                } else {
                    cout << "No Rotation";
                }
                break;
            }
        }
        i++;
    }
}

bool P8S2(string s1, string s2) {
    if (s1.size() != s2.size() && s1.size() == 0) {
        return false;
    }
    s1 = s1 + s1;
    if (s1.find(s2) != string::npos) {
        return true;
    }
    return false;
}

void P8Test() {
    P8S1();
    string s1 = "waterbottle", s2 = "erbottlewat";
    if (P8S2(s1, s2)) {
        cout << "Rotation";
    } else {
        cout << "No Rotation";
    }
}


void chapter1_run() {
    P1Test();
    P2Test();
    P3Test();
    P4Test();
    P5Test();
    spiralMatrixTest();
    P6Test();
    P7Test();
    P8Test();
}







































