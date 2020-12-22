/*
 * main.cpp
 *
 *  Created on: 01-Oct-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<stack>
#include<cstring>

void infix_to_postfix(char *in, char *post);
void infix_to_prefix(char *in, char *pre);
bool is_operand(char ch);
int priority(char opr);
void string_reverse(char *str);
int postfix_evaluation(char *post);
int calculator(int op1, int op2, char opr);


int main(void)
{
	//char infix[64] = "a*b/c*d+e/f-g*h";
	//char infix[64] = "(a*b)*(c+d)/e*f-g*h";
	char infix[64] = "4+5*8/9*7+3*8";

	char postfix[64] = " ";
	//char prefix[64] = " ";

	cout << "infix expression : " << infix << endl;
	infix_to_postfix(infix, postfix);
	//infix_to_prefix(infix, prefix);
	cout << "postfix expression : " << postfix << endl;
	//cout << "prefix expression  : " << prefix << endl;

	cout << "result is: " << postfix_evaluation(postfix) << endl;
	return 0;
}


int postfix_evaluation(char *post)
{
	stack<int> s;
	int res;

	//start scanning postfix string from left to right
	for( int i = 0 ; post[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand( post[i]) )
		{
			//push it into the stack
			s.push(post[i]-'0');
		}
		else//if the cur ele is an operator
		{
			//pop two ele's from the stack
			//first popped ele will be the second operand
			int op2 = s.top(); s.pop();
			//second popped ele will be the first operand
			int op1 = s.top(); s.pop();

			//perform "post[i]" operation on op1 & op2
			res = calculator(op1, op2, post[i]);
			//push result into the stack
			s.push(res);
		}
	}//end of for loop

	//pop the final result from the stack
	res = s.top(); s.pop();
	//return the result to the calling function
	return res;
}


int calculator(int op1, int op2, char opr)
{
	switch(opr)
	{
	case '+': return ( op1 + op2 );
	case '-': return ( op1 - op2 );
	case '*': return ( op1 * op2 );
	case '/': return ( op1 / op2 );
	case '%': return ( op1 % op2 );
	}
}

void infix_to_postfix(char *in, char *post)
{
	stack<int> s;
	int j = 0;

	//start scanning infix string from left to right
	for( int i = 0 ; in[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand( in[i] ) )
		{
			//append it into the postfix string
			post[j++] = in[i];
		}
		else
		if( in[i] == '(' )//if the cur ele is an opening brace
		{
			//push it into the stack
			s.push(in[i]);
		}
		else
		if( in[i] == ')' )//if the cur ele is a closing brace
		{
			//pop all ele's from the stack till its corresponding opening brace
			//do not occures and append them into the postfix string
			while( s.top() != '(' )
			{
				post[j++] = s.top(); s.pop();
			}
			//pop opening brace as well from the stack
			s.pop();
		}
		else//if the cur ele is an operator
		{
			//if stack is not empty && priority topmost ele >= priority of cur ele
			while( !s.empty() && priority( s.top() ) >= priority(in[i]) )
			{
				//pop ele from the stack and append it into the postfix string
				post[j++] = s.top();
				s.pop();
			}
			//push ele into the stack
			s.push(in[i]);
		}
	}//end of for loop -- repeat the above steps till end of infis string

	//pop all remaining ele's from the stack one by one and append them into the
	//postfix string
	while( !s.empty() )
	{
		post[j++] = s.top(); s.pop();
	}

	post[j] = '\0';
}

void infix_to_prefix(char *in, char *pre)
{
	stack<int> s;
	int j = 0;

	//start scanning infix string from right to left
	for( int i = strlen(in)-1 ; i >= 0 ; i-- )
	{
		//if the cur ele is an operand
		if( is_operand( in[i] ) )
		{
			//append it into the prefix string
			pre[j++] = in[i];
		}
		else//if the cur ele is an operator
		{
			//if stack is not empty && priority topmost ele > priority of cur ele
			while( !s.empty() && priority( s.top() ) > priority(in[i]) )
			{
				//pop ele from the stack and append it into the prefix string
				pre[j++] = s.top();
				s.pop();
			}
			//push ele into the stack
			s.push(in[i]);
		}
	}//end of for loop -- repeat the above steps till end of infix string

	//pop all remaining ele's from the stack one by one and append them into the
	//prefix string
	while( !s.empty() )
	{
		pre[j++] = s.top(); s.pop();
	}

	pre[j] = '\0';
	//reverse the string
	string_reverse(pre);
}

/*
void infix_to_postfix(char *in, char *post)
{
	stack<int> s;
	int j = 0;
	//start scanning infix string from left to right
	for( int i = 0 ; in[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand( in[i] ) )
		{
			//append it into the postfix string
			post[j++] = in[i];
		}
		else//if the cur ele is an operator
		{
			//if stack is not empty && priority topmost ele >= priority of cur ele
			while( !s.empty() && priority( s.top() ) >= priority(in[i]) )
			{
				//pop ele from the stack and append it into the postfix string
				post[j++] = s.top();
				s.pop();
			}
			//push ele into the stack
			s.push(in[i]);
		}
	}//end of for loop -- repeat the above steps till end of infis string

	//pop all remaining ele's from the stack one by one and append them into the
	//postfix string
	while( !s.empty() )
	{
		post[j++] = s.top(); s.pop();
	}

	post[j] = '\0';
}
*/


void string_reverse(char *str)
{
	char *left = str;
	char *right = str;

	while( *right )
		right++;

	right--;

	while( left <= right )
	{
		char t = *left;
		*left = *right;
		*right = t;

		left++;
		right--;
	}
}

int priority(char opr)
{
	switch(opr)
	{
	case '*':
	case '/':
	case '%': return 4;

	case '+':
	case '-': return 2;

	case '(': return 0;
	}
}

bool is_operand(char ch)
{
	return ( ( ch >= 48 && ch <= 57 ) || ( ch >= 65 && ch <= 90 ) || ( ch >= 97 && ch <= 122 ) );
}













