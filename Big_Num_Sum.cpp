#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    Kiem tra du lieu dau vao thoa man dieu kien 
    Tat ca la cac chu so nguyen duong voi do dai <= 500 chu so
*/
bool checkInput(string x) {
    for (int i = 0; i < x.length(); i++) {
        if (x[i] < 48 || x[i] > 57) {   // Bang ma ASCII 0 -> 9 : 48 -> 57
            return false;
        }
    }
    return true;
}

/*
    small: it hon 10 chu so
    big: nguoc lai
    Kiem tra xem 2 so co phai small hay big
    Neu ca 2 la small -> true
    1 trong 2 la big -> false
    Ca 2 la big -> false
    Return True -> small va nguoc lai
*/
bool checkAttribute(string a, string b) {
    if (a.length() < 10 && b.length() < 10) {
        return true;
    } else {
        return false;
    }
}

/*
    Chuyen doi kieu int sang kieu string
*/
string convertIntToChar(int x) {
    stringstream ss;
    ss << x;
    string str_x;
    ss >> str_x;
    ss.str("");
    ss.clear();
    return str_x;
}

/*
    Chuyen doi 1 ki tu char sang kieu int
*/
int convertCharToInt(char s) {
    stringstream ss;
    ss << s;
    int int_s;
    ss >> int_s;
    ss.str("");
    ss.clear();
    return int_s;
}

/*
    Chuyen doi 1 chuoi string sang kieu int
*/
int convertStringToInt(string s) {
    stringstream ss;
    ss << s;
    int int_s;
    ss >> int_s;
    ss.str("");
    ss.clear();
    return int_s;
}

/*
    Xu ly phep cong 2 so co so chu so khong lon hon 9 chu so
*/
string solveSmallNumber(string a, string b) {
    int int_a = convertStringToInt(a);
    int int_b = convertStringToInt(b);
    int res = int_a + int_b;
    return convertIntToChar(res);
}

/*
    Xu ly chuoi so truoc khi tinh toan bigNumber
    Ham chuyen doi sao cho hai chuoi a va b co cung kich thuoc
    Tra ve kich thuoc chung 
*/
int prepare(string& a, string& b) {
    if (a.length() == b.length()) return a.length();
    int tmp = 0;
    bool tag = true; // a > b -> true, and vice versa
    if (a.length() > b.length()) {
        tmp = a.length() - b.length();
        tag = true;
    } else {
        tmp = b.length() - a.length();
        tag = false;
    }
    string str_tmp = "";
    int res = tmp;
    while (tmp > 0) {
        str_tmp += "0";
        tmp--;
    }
    if (tag) {
        str_tmp += b;
        b = str_tmp;
        return res;
    } else {
        str_tmp += a;
        a = str_tmp;
        return res;
    }
}

/*
    Dao nguoc chuoi ki tu
*/
void reverseString(string& s) {
    string tmp = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        tmp += s[i];
    }
    s = tmp;
}

/*
    Xu ly phep cong 2 so co so chu so lon hon 9 chu so
*/
string solveBigNumber(string a, string b) {
    int res_prepare = prepare(a, b);
    string res = "";
    int accel = 0;  // phep cong hang don vi luon co accel = 0
    for (int i = a.length() - 1, j = b.length() - 1; i >= 1, j >= 1; i--, j--) {
        int getInt_a = convertCharToInt(a[i]);
        int getInt_b = convertCharToInt(b[i]);
        int sumOf_getIntA_getIntB = getInt_a + getInt_b + accel;
        int needyPush = sumOf_getIntA_getIntB % 10;
        res += convertIntToChar(needyPush);
        accel = sumOf_getIntA_getIntB / 10;
    }
    int getFinalInt_a = convertCharToInt(a[0]);
    int getFinalInt_b = convertCharToInt(b[0]);
    int sum_of_getFinalIntA_getFinalIntB = getFinalInt_a + getFinalInt_b + accel;
    int needyFinalPush = sum_of_getFinalIntA_getFinalIntB;
    string str_tmp = convertIntToChar(needyFinalPush);
    reverseString(str_tmp);
    res += str_tmp;
    reverseString(res);
    return res;
}

//  Extra: Truong hop nhap vao chuoi rong (Enter) -> Can fix
int main() {

    int n;
    cin >> n;
    string a[n], b[n];

    int count = 0;
    while (count < n) {
        cin >> a[count] >> b[count];
        count++;
    }

    for (int i = 0; i < n; i++) {
        if (checkInput(a[i]) && checkInput(b[i])) {
            if (checkAttribute(a[i], b[i])) {
                cout << solveSmallNumber(a[i], b[i]) << endl;
            } else {
                cout << solveBigNumber(a[i], b[i]) << endl;
            }
        }
    }

    return 0;
}