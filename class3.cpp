#include <iostream>
#include<string>
using namespace std;
void printSubs(string str, int i, string ans)
{
    if(i >= str.length())
    {
        cout<<ans<<" ";
        return;
    }
  
    //excluding
    printSubs(str,i+1,ans);
      //including
    ans.push_back(str[i]);
    printSubs(str,i+1, ans);
}
int main()
{
    string str = "abcd";
    int i=0;
    string ans ="";
    printSubs(str,i,ans);
    return 0;
}