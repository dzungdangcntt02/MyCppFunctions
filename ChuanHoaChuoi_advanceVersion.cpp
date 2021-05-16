#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    Tao mang moi
*/
string* allocateArray(int newLength) {
    string *p_temp = new string[newLength];
    return p_temp;
}

/*
    Cap phat lai bo nho cho mang
*/
void resizeArray(string * &p, int oldLength, int newLength) {
    string *p_temp = p;
    p = allocateArray(newLength);
    if (oldLength < newLength) {
        for(int i = 0; i < oldLength; i++) {
			p[i] = p_temp[i];
		}
    } else {
		for(int i = 0; i < newLength; i++) {
			p[i] = p_temp[i];
		}
	}
    delete[] p_temp;
}

/*  
    Kiem tra xem mang co size bang bao nhieu
    Phuc vu Tester
*/
void fullFill(string* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = "x";
        cout << a[i] << " ";
    }
}

/*
    Xoa khoang trang cuoi xau
*/
void removeBlankSpace_tail(string* &ptr) {
    while (ptr->back() == ' ') {
        ptr->pop_back();
    }
}

/*
    Dao nguoc xau
*/ 
void reverseStr(string* &ptr) {
    string tmp = "";
    string ori = *ptr;
    for (int i = ori.length() - 1; i >= 0; i--) {
        tmp += ori[i];
    }
    *ptr = tmp;
}

/*
    Xoa khoang trang dau xau
*/
void removeBlankSpace_head(string* &ptr) {
    string* tmp = ptr;
    reverseStr(tmp);
    removeBlankSpace_tail(tmp);
    reverseStr(tmp);
    ptr = tmp;
    tmp = NULL;
}

/*
    Xoa mot ki tu o vi tri idx trong xau
*/
void remove_one_char(string& s, int& location) {
    bool check = false;
    for (int i = location; i < s.length() - 1; i++) {
        s[i] = s[i + 1];
    }
    s.pop_back();
}

/*
    Xoa tat ca cac chu so xuat hien trong xau
*/
void removeNumber(string* &ptr) {
    string tmp_str = *ptr;
    for (int i = 0; i < tmp_str.length(); i++) {
        if (tmp_str[i] >= 48 && tmp_str[i] <= 57) {    
            remove_one_char(tmp_str, i);
            i--;
        }
    }
    *ptr = tmp_str;
}

/*
    Xoa hai khoang trang lien nhau
*/
void removeBlankSpace_middle(string* &ptr) {
    string tmp_str = *ptr;
    for (int i = 0; i < tmp_str.length() - 1; i++) {
		if (tmp_str[i] == ' ' && tmp_str[i + 1] == ' ') {
			remove_one_char(tmp_str, i);
            if (tmp_str[i] == ' ') i--;
		}
	}
    *ptr = tmp_str;
}

/*
    Viet thuong tat ca ki tu trong xau
*/
void toLowercaseString(string* ptr) {
    string tmp = *ptr;
    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] >= 65 && tmp[i] <= 90) tmp[i] += 32;
    }
    *ptr = tmp;
}

/*
    Viet hoa chu cai dau moi tu trong xau
*/
void toUppercaseFirstCharName(string* ptr) {
    string s = *ptr;
	if (s[0] > 96 && s[0] < 123) s[0] -= 32;
    for (int i = 1; i < s.length() - 1; i++) {
		bool check = false;
		if (s[i + 1] > 96 && s[i + 1] < 123) check = true;
		if (s[i] == ' ' && s[i + 1] != ' ' && check == true) {
			s[i + 1] -= 32;
		}
	}
    *ptr = s;
}

/*
    Chuẩn hóa chuỗi với tên riêng (tên riêng không chứa số, khi xóa yêu cầu cấp phát lại bộ nhớ)
*/
void ChuanHoa(string* p_str) {
    removeBlankSpace_tail(p_str);
    removeBlankSpace_head(p_str);
    removeNumber(p_str);
    removeBlankSpace_middle(p_str);
    toLowercaseString(p_str);
    toUppercaseFirstCharName(p_str);
}

int main() {
    
    
    string* p_str = new string[10000];
    getline(cin, *p_str);


    ChuanHoa(p_str);
    resizeArray(p_str, 10000, p_str->length());
    cout << *p_str;
    delete[] p_str;
    p_str = NULL; 

    return 0;
}
