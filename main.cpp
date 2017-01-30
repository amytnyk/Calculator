#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>


using namespace std;

int ConvertCharToInt(char s)
{
    if(s == '0')
        return 0;
    if(s == '1')
        return 1;
    if(s == '2')
        return 2;
    if(s == '3')
        return 3;
    if(s == '4')
        return 4;
    if(s == '5')
        return 5;
    if(s == '6')
        return 6;
    if(s == '7')
        return 7;
    if(s == '8')
        return 8;
    if(s == '9')
        return 9;
}

int ConvertStringToInt(string s)
{
    int n = 0;
    for(int i = 0;i < s.size();i++)
    {
        n *= 10;
        n += ConvertCharToInt(s[i]);
    }
    return n;
}

int Calculate(vector<string> calc)
{
    int result;
    int Znak;
    vector<int> a;
    bool k = false;
    int j = 0;
    a.push_back(ConvertStringToInt(calc[0]));
    for(int i = 1;i < calc.size();i++)
    {
        string Zn = calc[i];
        j++;
        i++;
        int n = ConvertStringToInt(calc[i]);
        if(Zn == "*")
            a[j - 1] *= n;
        else if(Zn == ":")
            a[j - 1] /= n;
        else
        {
            if(Zn == "+")
            {
                k = true;
                a.push_back(-1);
                j++;
            }
            if(Zn == "-")
            {
                k = true;
                a.push_back(-2);
                j++;
            }
            a.push_back(n);
        }
    }
    result = a[0];
    if(k)
    {
        for(int i = 1;i < a.size();i++)
        {
            Znak = a[i];
            i++;
            switch (Znak)
            {
            case -1:
                result += a[i];
                break;
            case -2:
                result -= a[i];
                break;
            }
        }
    }
    return result;
}

int main()
{
    vector<string> str;
    string h;
    while(cin >> h, h != ";")
        str.push_back(h);
    cout << Calculate(str) << endl;
    /*int result;
    vector<string> all;
    vector<int> a;
    cout << "Enter string" << endl;
    string h;
    int Znak;
    bool k = false;
    int j = 0;
    while(cin >> h, h != ";")
        all.push_back(h);
    a.push_back(ConvertStringToInt(all[0]));
    for(int i = 1;i < all.size();i++)
    {
        string Zn = all[i];
        j++;
        i++;
        int n = ConvertStringToInt(all[i]);
        if(Zn == "*")
            a[j - 1] *= n;
        else if(Zn == ":")
            a[j - 1] /= n;
        else
        {
            if(Zn == "+")
            {
                k = true;
                a.push_back(-1);
                j++;
            }
            if(Zn == "-")
            {
                k = true;
                a.push_back(-2);
                j++;
            }
            a.push_back(n);
        }
    }
    result = a[0];
    if(k)
    {
        for(int i = 1;i < a.size();i++)
        {
            Znak = a[i];
            i++;
            switch (Znak)
            {
            case -1:
                result += a[i];
                break;
            case -2:
                result -= a[i];
                break;
            }
        }
    }
    cout << result << endl;*/
    return 0;
}
