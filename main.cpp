#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

int ConvertCharToInt(char s)
{
    if(s == '-')
        return 10;
    return atoi(&s);
}

int ConvertStringToInt(string s)
{
    int n = atoi(s.c_str());
    return n;
}

string ConvertIntToString(int s)
{
    stringstream st;
    st << s;
    string str;
    st >> str;
    return str;
}

long int fact(int n)
{
    if(n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

string Delete(string d, int index)
{
    string res;
    for(int i = 0;i < index;i++)
        res += d[i];
    for(int i = index +1 ;i < d.size();i++)
        res += d[i];
    return res;
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
        {
            string s = calc[i];
            if(s[0] == '!')
                n = fact(ConvertStringToInt(Delete(s, 0)));
            else if(s[0] == 's')
                n = sqrt(ConvertStringToInt(Delete(s, 0)));
            else if(s[0] == 'm')
                n = fabs(ConvertStringToInt(Delete(s, 0)));
            else
                n = ConvertStringToInt(s);
        }
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
