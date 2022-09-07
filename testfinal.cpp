#include <bits/stdc++.h>
using namespace std;
class StringCalculator
{
public:
    int add(string numbers)
    {
        vector<int> negative;
        vector<int> num;
        if (numbers.empty())
        {
            // cout << "The string is empty thus sum is 0";
            return 0;
        }
        int i = 0;
        while (i < numbers.length())
        {
            string t = "";
            if ((numbers[i] >= 'a' && numbers[i] <= 'z'))
            {
                num.push_back((numbers[i] - 'a') + 1);
                i++;
            }
            else if ((numbers[i] >= '0' && numbers[i] <= '9') || (numbers[i] == '-'))
            {
                int j = i;
                while (numbers[j] != ',' && j < numbers.length())
                {
                    t += numbers[j];
                    j++;
                }
                int num1 = stoi(t);
                // cout << "Number is" << num1 << endl;
                try
                {
                    if (num1 < 0)
                    {
                        throw num1;
                    }
                }
                catch (int e)
                {
                    negative.push_back(e);
                }

                if (num1 <= 1000 && num1 >= 0)
                {
                    num.push_back(num1);
                }
                i = j + 1;
            }
            else
            {
                i++;
            }
        }
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            sum += num[i];
        }
        if (!negative.empty())
        {
            string ngt;
            for (int i = 0; i < negative.size(); i++)
            {
                ngt += to_string(negative[i]);
                if (i != negative.size() - 1)
                {
                    ngt += ',';
                }
            }
            cout << "Negatives not allowed ";
            cout << ngt;
            return -1;
        }
        return sum;
    }
};
int main()
{
    StringCalculator a;
    string s;
    cout << "Enter a string:";
    getline(cin, s);
    int ans;
    ans = a.add(s);
    if (ans != -1)
    {
        cout << ans;
    }

    return 0;
}