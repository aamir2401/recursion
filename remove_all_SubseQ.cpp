#include <iostream>
#include<string>
using namespace std;
void removeAllSub(string &s, string &part)
{
    //base case;
    int poss = s.find(part);
    if(poss != string::npos)
    {
        string left_part = s.substr(0,poss);
        string right_part = s.substr(poss+part.length(), s.size());
        s = left_part + right_part;
        // cout<<"sss: -->"<<s<<endl;
        removeAllSub(s,part);
    }
    else
    {
        return;
    }

}
int main()
{
        string s = "daabcbaabcbc";
        string part = "abc";
        cout<<"Before removal of subsequence: "<<s<<endl;
        removeAllSub(s,part);
        cout<<"after removal of subsequence: "<<s<<endl;
        return 0;
}