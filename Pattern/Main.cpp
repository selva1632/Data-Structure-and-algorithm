#include <iostream>
using namespace std;

void pattern1(int n)
{
    // *
    // **
    // ***
    // ****
    // *****

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    /*
     *****
     ****
     ***
     **
     *
     */

    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i + 1; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern3(int n)
{
    /*
     *
     ***
     *****
     *******
     *********
     */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < i * 2 + 1; k++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern4(int n)
{
    /*
         *********
          *******
           *****
            ***
             *

    */
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < i * 2 - 1; k++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern5(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }

    for (int j = n; j > 0; j--)
    {
        for (int i = 0; i < n - j; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < 2 * j - 1; i++)
        {
            cout << "*";
        }
        for (int i = 0; i < n - j; i++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern6(int n)
{
    // *
    // **
    // ***
    // ****
    // *****
    // ****
    // ***
    // **
    // *
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < n - abs(n - i - 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern7(int n)
{
    // *****
    // ****
    // ***
    // **
    // *
    // **
    // ***
    // ****
    // *****

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j <= abs(n - i - 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern8(int n)
{
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15

    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void pattern9(int n)
{

    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < i * 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n)
{

    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << " ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n - i); j++)
        {
            cout << " ";
        }

        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

    int evenlyDivides(int N){
        //code here
        int temp = N;
        int count = 0;
        while (temp > 0) {
            int x = temp % 10;
            temp /= 10;
            
            if (N % x == 0) {
                count++;
            }
        } 
        return count;
    }

int main()
{
    int n;
    cin >> n;

    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
    pattern5(n);
    pattern6(n);
    pattern7(n);
    pattern8(n);
    pattern9(n);
    pattern10(n);

    cout << evenlyDivides(n);

    return 0;
}