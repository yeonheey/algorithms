#include <string>
#include <stack>

using namespace std;

bool is_right_parenthesis(string p)
{
	stack<char> stk;

	while (!p.empty())
	{
		if (stk.empty())
		{
			stk.push(p.back());

			if (p.back() != ')') break;
		}
		else if (stk.top() == p.back())
			stk.push(p.back());
		else
			stk.pop();

		p.pop_back();
	}

	return stk.empty();
}

string solution(string p) {
	string answer = "";
	string u = "", v = "";

	if (is_right_parenthesis(p))
		answer = p;
	else if (!p.empty())
	{
		//u, v ºÐ¸®
		for (int i = 0, left_p = 0, right_p = 0; i < p.size(); i++)
		{
			u += p[i];

			if (p[i] == '(') left_p++;
			else right_p++;

			if (left_p == right_p)
			{
				v = p.substr(i + 1);
				break;
			}
		}

		if (is_right_parenthesis(u))
			answer = u + solution(v);
		else
		{
			answer = '(' + solution(v) + ')';

			u = u.substr(1, u.size() - 2);

			for (char ch : u)
			{
				if (ch == '(')
					answer += ')';
				else
					answer += '(';
			}
		}
	}

	return answer;
}