#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) 
{
    int n = arr.size();
    std::sort (arr.begin(), arr.begin()+n);
    int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) {
        std::cout<<"Array i: "<<arr[i]<<std::endl;
        std::cout<<"Array i-1: "<<arr[i-1]<<std::endl; 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else {
            // std::cout<< "Current count is: "<<curr_count<<std::endl;
            // std::cout<<"===================="<<std::endl;
            // std::cout<< "Max count is: "<<max_count<<std::endl;
            // std::cout<<"////////////////////"<<std::endl; 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1];
                // std::cout<<"Result: "<<res<<std::endl; 
            } 
            curr_count = 1; 
        } 
    } 

    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[n - 1]; 
    } 
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
