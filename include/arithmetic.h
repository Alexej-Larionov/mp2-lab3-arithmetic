// ���������� ������� � ������� ��� ���������� �������������� ���������

#ifndef _ARITHMETIC_H_
#define _ARITHMETIC_H_
#include <vector>
#include <queue>
#include <map>
#include "stack.h"

using namespace std;

// ������������, ������� �������������� ��� �������� ���� �������
enum Token
{
	NUMBER,
	SIN, COS, EXP, LOG, UNARY_MINUS,
	LP = '(', RP = ')',
	PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
};

// Lexems - �����, ������� ������������ �� ���� ������ ������.
// tokens - ������ � ������ ������, ��� ������ ������� ���� NUMBER
// ���� ���� �������� �������� �� ������� value, ������� �� ��������� 
// ����� ������ ���� ��������, ������� �� ���� ���������� � ������������ Token
class Lexems
{
public:
	queue<double> values;
	vector<Token> tokens;
	bool operator==(const Lexems& lex) const
	{
		return (values == lex.values) && (tokens == lex.tokens);
	}
	void print()
	{
		cout << endl;
		for (size_t i = 0; i < tokens.size(); i++) {
			cout << tokens[i] << " ";
		}
		cout << endl;
		queue<double> vals = values;
		while (!vals.empty()) {
			cout << vals.front();
			vals.pop();
		}
	}
};

extern map<string, double> variables;  //������ ���������� ����������, ���������� �������������

bool isDot(const char& ch);
bool isOperation(const char& ch);
bool isOperation(const Token& tok);
bool isBracket(const char& ch);
bool isFunction(const Token& tok);
bool isFunction(const string& name);

int getPriority(const Token& tok);

double stringToDouble(string str, size_t* pos); // ������� ������� � ������� pos ��������� �� ������ str ����� 

Lexems convertToArrayLexem(string str); // ������� ��������������� ������ � ������ ������

bool isCorrect(const Lexems& lexemsArray); // ������� ��������� �������������� ��������� �� ������������

Lexems convertToRpn(const Lexems& lexemArray); // ������� ����������� ������ ������ � �������� �������� ������

double computeResult(const Lexems& rpn); // ������� ��������� ��������� ��������� �� �������� �������� ������

#endif