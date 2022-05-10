//Step 1: Put a pointer P at the end of the end
//Step 2: If character at P is an operand push it to Stack
//Step 3: If the character at P is an operator pop two 
//        elements from the Stack. Operate on these elements
//        according to the operator, and push the result 
//        back to the Stack
//Step 4: Decrement P by 1 and go to Step 2 as long as there
//        are characters left to be scanned in the expression.
//Step 5: The Result is stored at the top of the Stack, 
//        return it
//Step 6: End

//Langkah 1: Letakkan pointer P di ujung ujung
//Langkah 2: Jika karakter di P adalah operan, dorong ke Stack
//Langkah 3: Jika karakter di P adalah operator pop two
//         elemen dari Stack. Operasikan pada elemen-elemen ini
//         menurut operator, dan dorong hasilnya
//         kembali ke Stack
//Langkah 4: Kurangi P sebanyak 1 dan lanjutkan ke Langkah 2 selama ada
//         adalah karakter yang tersisa untuk dipindai dalam ekspresi.
//Langkah 5: Hasil disimpan di bagian atas Stack,
//         Kembalikan
//Langkah 6: Akhir

// C++ program to evaluate a prefix expression.
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
	// If the character is a digit then it must
	// be an operand
	return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
	stack<double> Stack;

	for (int j = exprsn.size() - 1; j >= 0; j--) {

		// Push operand to Stack
		// To convert exprsn[j] to digit subtract
		// '0' from exprsn[j].
		if (isOperand(exprsn[j]))
			Stack.push(exprsn[j] - '0');

		else {

			// Operator encountered
			// Pop two elements from Stack
			double o1 = Stack.top();
			Stack.pop();
			double o2 = Stack.top();
			Stack.pop();

			// Use switch case to operate on o1
			// and o2 and perform o1 O o2.
			switch (exprsn[j]) {
			case '+':
				Stack.push(o1 + o2);
				break;
			case '-':
				Stack.push(o1 - o2);
				break;
			case '*':
				Stack.push(o1 * o2);
				break;
			case '/':
				Stack.push(o1 / o2);
				break;
			}
		}
	}

	return Stack.top();
}


