#include <iostream>
#include<string>
using namespace std;
void findLastOcc(string s, int i, int &ans)
{
    i=0;
    int send=0;
    int n=s.length();
    if(i >= n)
    {
         return;
    }
    if(s[i] == 'z')
    {
        ans = i;
    }
      findLastOcc(s,i+1,ans);

}
void reverseUsingRec(string &s, int i, int j)
{
    if(i > j)
    {
        return;
    }
    // swap(s[i], s[j]);
    char ch = s[j];
    s[j] = s[i];
    s[i] = ch;
    reverseUsingRec(s,i+1,j-1);
}
int main()
{
    
    //we have to find the index of char ch which is last recursevily;
    //eg--> last 'd' is at 6th idx;
    // string s = "azbcdggdbcdggd";
    // int i=0;
    // int ans= -1;
    // findLastOcc(s,i,ans); 
    // cout<<"got ans: "<<ans;



    // we have to reverse a string using rec.;
    string s = "asgd";
    cout<<"Before reversing the string: "<<s<<endl;
    int i=0;
    int j=s.length()-1;
    reverseUsingRec(s,i,j);
    cout<<"After reversing the string: "<<s<<endl;

    return 0;
}