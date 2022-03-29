// реализация пользовательского приложения
#include "arithmetic.h"

string getNewString()
{
	string newString;
	getline(cin, newString);
	return newString;
}

int main()
{
	while (cin) {
		try {
			cout << "Please insert your expression:";
			string str = getNewString();

			Lexems arithmeticExp = convertToArrayLexem(str);

			if (arithmeticExp.tokens.empty())
			{
				cout << endl;
			}
			else if (isCorrect(arithmeticExp))
			{

				Lexems rpn = convertToRpn(arithmeticExp);

				double res = computeResult(rpn);
				cout <<"Result is:"<< res << endl;
			}
		}
		catch (Exception)
		{
			cerr << "press enter and repeat";
		}
	}
	system("pause");
	return 0;
}