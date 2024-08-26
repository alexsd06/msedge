#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char * argv[])
{
    // cout<<argc<<endl;
    bool open_url=false;
    for (int i=0; i<argc; i++) {
        // cout<<argv[i]<<endl;
        string str(argv[i]);
        if (str=="--single-argument") {
            open_url=true;
            break;
        }
    }

    if (!open_url) {
        string command_line="\"C:\\Program Files\\Mozilla Firefox\\firefox.exe\" -new-tab https://www.google.com/";
        system(command_line.c_str());
        return 0;
    }

    char *arg = argv[argc-1];
    string arg_str(arg);
    int bad_parts_count=1;
    string bad_parts[]={"microsoft-edge:"};
    for (int i=0; i<bad_parts_count; i++) {
         string to_erase = bad_parts[i];
         size_t pos = arg_str.find(to_erase);
         if (pos != std::string::npos) {
             arg_str.erase(pos, to_erase.length());
         }
    }
    string command_line="\"C:\\Program Files\\Mozilla Firefox\\firefox.exe\" -new-tab "+arg_str;
    system(command_line.c_str());
    return 0;
}
