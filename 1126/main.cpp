#include <iostream>

using namespace std;

bool checkChar(char ch) {
    return ch >= 'p' && ch <= 'z';
}

bool checkSyntax(string word) {
   if(word.size() == 0) {
       return false;
   }
   
}

int main()
{
    string word;
    while(cin >> word) {
        if(checkSyntax(word)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

