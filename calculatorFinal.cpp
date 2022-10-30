#include <iostream>
#include <string>

  
using namespace std; 

    int roman_to_integer(string input) {
        int n = int(input.length());
        int result = 0;
        for (int i = 0; i < n; i++) {
            switch (input[i]) {
                case 'I':
                    result += 1;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }

        for (int i = 1; i < n; i++) {
            if ((input[i] == 'V' || input[i] == 'X') && input[i - 1] == 'I') {
                result -= 1 + 1;
            }

            if ((input[i] == 'L' || input[i] == 'C') && input[i - 1] == 'X') {
                result -= 10 + 10;
            }

            if ((input[i] == 'D' || input[i] == 'M') && input[i - 1] == 'C') {
                result -= 100 + 100;
            }
        }
        return result;
    }

 string integer_to_Roman(int n) {

        string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string result = "";

        for ( int i = 0; i < 13; ++i)
        {
            while(n - values[i] >= 0)
            {
                result =  result + str_romans[i];
                n = n - values[i];
            }
        }
        return result;
    }

int main () 
{

int number1 = 0;
string number2;
string sign;		
bool loop = true;

while (loop) {

        cout << "Please enter an operation +, -, *, / or 'exit' to get an answer: ";
        cin >> sign;
       
    
    if (sign=="exit" || sign=="Exit" || sign=="EXIT" )
        {
            cout << "Answer is: " << integer_to_Roman (number1) << "\n"; 
            break;
        }
        cout << "Please enter a number: ";
        cin >> number2;
        

    if (sign != "+" && sign != "-" && sign != "*" && sign != "/" && sign != "Exit" && sign != "exit" && sign != "EXIT")
		{
			cout << "Unknown operator " << sign << '\n';
		}
		else
		{

       if (sign == "+") 
			{
			    number1 += roman_to_integer (number2);
			}
			else
			{
				if (sign == "-")
				{
					number1 -= roman_to_integer (number2);
				}
				else
				{
					if (sign == "*")
					{
						number1 *= roman_to_integer (number2);
					}
					else
					{
						if (sign == "/")
						{
							number1 /= roman_to_integer (number2);
						}
					}
				}
			}
		}       
    }    
}        