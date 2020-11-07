#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) 
{   
    string s;
    int day_or_programmer = 256;
    int jan = 31, march = 31, april = 30, may = 31, june = 30, july = 31, august = 31;
    int total_days;
    int diff_days;
    int n = 9;
    int new_year;
    string res;
    if (year%400 != 0)
    {
        new_year = year;
    }
    if (year%4 ==0)
    {
        int feb = 29;
        std::cout<<year<<std::endl;
        total_days = jan + feb + march + april + may + june + july + august;
        diff_days = day_or_programmer - total_days;
        std::string days = std::to_string(diff_days);
        days.insert(days.end(),days.length()-1,'.');
        std::string month = std::to_string(n);
        month.insert(month.begin(),month.length(),'0');
        month.insert(month.end(),month.length()-1,'.');
        std::string years = std::to_string(year);
        res= days+month+years;
        std::cout<<res<<std::endl;
    }
    if (year%4 != 0 || year == 2100 || year == 2200 || year == 2300 || year == 2500 || year == 2600 || year == 2700)
    {
        int feb = 28;
        total_days = jan + feb + march + april + may + june + july + august;
        diff_days = day_or_programmer - total_days;
        std::string days = std::to_string(diff_days);
        days.insert(days.end(),days.length()-1,'.');
        std::string month = std::to_string(n);
        month.insert(month.begin(),month.length(),'0');
        month.insert(month.end(),month.length()-1,'.');
        std::string years = std::to_string(year);
        res= days+month+years;
    }
    if (year == 1918)
    {
        int feb = 15;
        total_days = jan + feb + march + april + may + june + july + august;
        diff_days = day_or_programmer - total_days;
        std::string days = std::to_string(diff_days);
        days.insert(days.end(),days.length()-1,'.');
        std::string month = std::to_string(n);
        month.insert(month.begin(),month.length(),'0');
        month.insert(month.end(),month.length()-1,'.');
        std::string years = std::to_string(year);
        res= days+month+years;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
