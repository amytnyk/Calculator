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

char ConvertIntToChar(int s)
{
    if(s == 0)
        return '0';
    if(s == 1)
        return '1';
    if(s == 2)
        return '2';
    if(s == 3)
        return '3';
    if(s == 4)
        return '4';
    if(s == 5)
        return '5';
    if(s == 6)
        return '6';
    if(s == 7)
        return '7';
    if(s == 8)
        return '8';
    if(s == 9)
        return '9';
}

string ConvertIntToString(int s)
{
    string n;
    while(s > 0)
    {
        int a = s % 10;
        n += ConvertIntToChar(a);
        s /= 10;
    }
    return n;
}
int Calculate(vector<string> calc)
{
    vector<string> dys;
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
        int n;
        if(calc[i] == "(")
        {
            i++;
            while(calc[i] != ")")
            {
                dys.push_back(calc[i]);
                i++;
            }
            n = Calculate(dys);
            dys.clear();
        }
        else
            n = ConvertStringToInt(calc[i]);
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

vector<string> Convert(string h)
{
    vector<string> str;
    for(int i = 0; i < h.size();i++)
    {
        if(h[i] == '+')
            str.push_back("+");
        else if(h[i] == '-')
            str.push_back("-");
        else if(h[i] == '*')
            str.push_back("*");
        else if(h[i] == ':')
            str.push_back(":");
        else if(h[i] == ';')
            break;
        else
        {
            int n = 0;
            while(h[i] != '+' && h[i] != '-' && h[i] != '*' && h[i] != ':' && h[i] != ';')
            {
                n *= 10;
                n += ConvertCharToInt(h[i]);
                i++;
            }
            if(n != 0)
                i--;
            str.push_back(ConvertIntToString(n));
        }
    }
    return str;
}

int main()
{
    int var;
    cin >> var;
    vector<string> str;
    if(var == 0)
    {
        string h;
        while(cin >> h, h != ";")
            str.push_back(h);
    }
    else
    {
        string h;
        cin >> h;
        str = Convert(h);
    }
    cout << Calculate(str) << endl;
    return 0;
}
