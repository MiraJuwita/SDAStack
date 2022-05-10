// mengkonversi prefix to Infix
string preToInfix(string pre_exp) {
stack<string> s;

// panjang ekspresi
int length = pre_exp.size();

// baca dari kanan ke kiri
for (int i = length - 1; i >= 0; i--) {

	// cek apakah simbol adalah operator
	if (isOperator(pre_exp[i])) {

	// pop dua operan dari stack
	string op1 = s.top(); s.pop();
	string op2 = s.top(); s.pop();

	// menggabungkan operan dan operator
	string temp = "(" + op1 + pre_exp[i] + op2 + ")";

	// dorong string temp ke stack
	s.push(temp);
	}

	// jika simbol adalah operan
	else {

	// dorong operan ke stack
	s.push(string(1, pre_exp[i]));
	}
}

// Stack sekarang berisi ekspresi Infix 
return s.top();
}


