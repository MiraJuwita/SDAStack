// mengkonversi infix ke prefix
bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}

string infixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	int l = infix.size();
	stack<char> char_stack;
	string output;

	for (int i = 0; i < l; i++) {

		// jika karakter yang dipindai adalah operan, tambahkan ke output.
		if (isalpha(infix[i]) || isdigit(infix[i]))
			output += infix[i];

		// jika karakter yang dipindai adalah '(', dorong ke stack
		else if (infix[i] == '(')
			char_stack.push('(');

		// jika karakter yang dipindai adalah ')', pop dan keluarkan dari stack hingga '(' ditemukan.
		else if (infix[i] == ')') {
			while (char_stack.top() != '(') {
				output += char_stack.top();
				char_stack.pop();
			}

			// hapus '(' dari stack
			char_stack.pop();
		}

		// operator ditemukan
		else
		{
			if (isOperator(char_stack.top()))
			{
				if(infix[i] == '^')
				{
					while (getPriority(infix[i]) <= getPriority(char_stack.top()))
					{
						output += char_stack.top();
						char_stack.pop();
					}
					
				}
				else
				{
					while (getPriority(infix[i]) < getPriority(char_stack.top()))
					{
						output += char_stack.top();
						char_stack.pop();
					}
					
				}

				// dorong operator barusan ke stack
				char_stack.push(infix[i]);
			}
		}
	}
	while(!char_stack.empty()){
		output += char_stack.top();
		char_stack.pop();
	}
	return output;
}

string infixToPrefix(string infix)
{
	// membalikkan postfix
	int l = infix.size();

	// membalikkan infix
	reverse(infix.begin(), infix.end());

	// ganti ( dengan ) dan sebaliknya
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}

	string prefix = infixToPostfix(infix);

	// membalikkan postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

