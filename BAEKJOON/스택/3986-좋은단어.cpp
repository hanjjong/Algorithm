#include <iostream>
using namespace std;
#include <stack>
#include <string>


int N;
string str;
int cnt;

int main()
{
    cin >> N;
    while (N--)
    {
        cin >> str;
        stack<char> st;
        for (int i = 0;i <str.size(); i++)
        {
            if (!st.empty() && st.top() == str.at(i))
            {
                st.pop();
            }
            else 
                st.push(str.at(i));
        }
        if (st.empty())
            cnt++;
    }
    cout << cnt;
}