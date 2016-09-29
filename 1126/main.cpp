#include <iostream>

using namespace std;

bool checkChar(char ch) {
    return ch >= 'p' && ch <= 'z';
}

bool checkSyntax(string word) {
    if(word.size() == 0) {
        return false;
    }
    if(word.size() == 1 && checkChar(word[0])) {
        return true;
    }
    else if(word[0] == 'N') {
        return checkSyntax(word.substr(1));
    }
    else if(word[0] == 'C' || word[0] == 'D' || word[0] == 'E' || word[0] == 'I') {
        string subWord = word.substr(1);
        for(int i = 1; i < subWord.size(); i++) {
            if(checkSyntax(subWord.substr(0, i)) && checkSyntax(subWord.substr(i))) {
                return true;
            }
        }
        return false;
    }
    else {
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

