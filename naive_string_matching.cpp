#include <iostream>
using namespace std;
void navie_string_matcher(string &text, string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int s = 0; s <= n - m; s++)
    {
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (text[s + j] != pattern[j])
            {
                match = false;
                break;
            }
        }
        if (match == true)
        {
            cout << "Pattern occurs at index" << s << endl;
        }
    }
}
int main()
{
    string text;     = "abbabcdacabc";
    string pattern;  = "abc";
    cout << "Enter text:";
    getline(cin, text);
    cout << "Enter pattern";
    getline(cin, pattern);
    navie_string_matcher(text, pattern);
    return 0;
}