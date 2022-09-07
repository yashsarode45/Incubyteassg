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
            //The string is empty thus sum is 0
            return 0;
        }
        int i = 0;
        while (i < numbers.length())
        {
            string t = "";
            if ((numbers[i] >= 'a' && numbers[i] <= 'z'))
            {
                //for letters in the string
                num.push_back((numbers[i] - 'a') + 1);
                i++;
            }
            else if ((numbers[i] >= '0' && numbers[i] <= '9') || (numbers[i] == '-'))
            {
                //for positive and negative numbers
                int j = i;
                while (numbers[j] != ',' && j < numbers.length())
                {
                    t += numbers[j];
                    j++;
                }
                int num1 = stoi(t);
                try
                {
                    //throw negative numbers 
                    if (num1 < 0)
                    {
                        throw num1;
                    }
                }
                catch (int e)
                {
                    //push negative numbers in a vector
                    negative.push_back(e);
                }

                if (num1 <= 1000 && num1 >= 0)
                {
                    //push positive and numbers <= 1000 in the vector, so that it can be added later.
                    num.push_back(num1);
                }
                i = j + 1;
            }
            else
            {
                //for ',' in the string we increment i
                i++;
            }
        }
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            //traverse the vector and take the sum
            sum += num[i];
        }
        if (!negative.empty())
        {
            //If the negative vector is not empty means there are negative numbers so we need to o/p those numbers and not take the sum.
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
            //we return -1 so that negative numbers are present in the string can be differentiated in the main function.
            return -1;
        }
        //If the negative vector empty that means no negative numbers present we return the sum calculated
        return sum;
    }
};
int main()
{
    StringCalculator a;
    string s;
    cout << "Enter a string:";
    //Taking input with getline function as we can also have an empty string as input
    getline(cin, s);
    int ans;
    ans = a.add(s);
    // ans=-1 means negative numbers are present
    if (ans != -1)
    {
        cout << ans;
    }

    return 0;
}
