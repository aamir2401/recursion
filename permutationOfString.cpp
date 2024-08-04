#include <iostream>
#include <string>
using namespace std;
void permutationOfstr(string str, int i)
{
    if(i >= str.length())
    {
        cout<<str<<" ";
        return;
    }
    for(int j=i; j<=str.length()-1; j++)
    {
        swap(str[i], str[j]);
        permutationOfstr(str, i+1);
        //here we are again re swapping the string to make its previous state;
        swap(str[i], str[j]);
    }
}
int main()
{
    string str = "abc";
    int i = 0;
    permutationOfstr(str,i);




    return 0;
}