
#include <iostream>
#include<stack>
#include<cstring>
using namespace std;

void string_reverse(char *str);
void infix_to_postfix(char *in, char* post);
void infix_to_prefix(char *in, char* pre);
bool is_operand(char ch);
int priority(char ch);
int main() {

	char infix[64] = "a*b/c*d+e/f-g*h";
	//char infix[64] = "((a*b)*(c+d))/(e*f-g*h)";
	char postfix[64] = "";
	char prefix[64] = "";
	cout<<"Enter infix expression ";
	cin>>infix;
	infix_to_postfix(infix,postfix);
	cout<<endl;
	cout<<"postfix ";
	cout<<postfix<<endl;
	infix_to_prefix(infix,prefix);
	cout<<"prefix ";
	cout<<prefix;

	return 0;
}



void infix_to_postfix(char *in, char* post)
{
	stack <int> s;
	int j=0;
	for(int i=0;in[i]!='\0';i++)
	{
		if(is_operand(in[i]))
		{
			post[j++]=in[i];
		}
		else
		if( in[i] == '(' )
		{

			s.push(in[i]);
		}
		else
		if( in[i] == ')' )
		{

			while( s.top() != '(' )
			{
				post[j++] = s.top(); s.pop();
			}

			s.pop();
		}
		else
		{
			while(!s.empty() && priority(s.top()) >= priority(in[i]))
			{
				post[j++]=s.top();
				s.pop();
			}
			s.push(in[i]);
		}


	}
	while( !s.empty() )
		{
			post[j++] = s.top(); s.pop();
		}

		post[j] = '\0';
}

void infix_to_prefix(char *in, char* pre)
{
	stack <int> s;
	int j=0;
	for(int i=strlen(in)-1;i>=0;i--)
	{
		if(is_operand(in[i]))
		{
			pre[j++]=in[i];
		}
		else
		{

			while( !s.empty() && priority( s.top() ) > priority(in[i]) )
			{

				pre[j++] = s.top();
				s.pop();
			}

			s.push(in[i]);
		}
	}


	while( !s.empty() )
	{
		pre[j++] = s.top(); s.pop();
	}

	pre[j] = '\0';

	string_reverse(pre);
}






/*void infix_to_postfix(char *in, char* post)
{
	stack <int> s;
	int j=0;
	for(int i=0;in[i]!='\0';i++)
	{
		if(is_operand(in[i]))
		{
			post[j++]=in[i];
		}
		else
		{
			while(!s.empty() && priority(s.top()) >= priority(in[i]))
			{
				post[j++]=s.top();
				s.pop();
			}
			s.push(in[i]);
		}


	}
	while( !s.empty() )
		{
			post[j++] = s.top(); s.pop();
		}

		post[j] = '\0';
}*/

void string_reverse(char *str)
{
	char *left=str;
	char *right=str;

	while(*right)
		right++;

	right--;

	while(left<=right)
	{
		char t=*left;
		*left=*right;
		*right=t;

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
	default:
		break;
	}
}


bool is_operand(char ch)
{
	return ((ch>=48 && ch<=57)||(ch>=65 && ch<=90)||(ch>=97&&ch<=122));
}
