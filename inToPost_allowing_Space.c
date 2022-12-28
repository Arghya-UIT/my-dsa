#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stk_elem
{
	char op;
	struct stk_elem *next;
};

typedef struct stk_elem *Stack;

int isop(char);
char pop(Stack *);
int prec(char);
void push(Stack *, char);
int underflow(Stack);
void inf2pos(char[], char[]);

#define MAXLEN 1000

int main()
{
	char exp[MAXLEN], pos[MAXLEN];

	fgets(exp, MAXLEN, stdin);
	inf2pos(exp, pos);
	printf("%s\n", pos);
	return 0;
}

void inf2pos(char in[], char pos[])
{
	int i, j;
	char c, tmp;
	Stack stk = NULL;

	i = j = 0;
	while ((c = in[i++]) != '$')
	{
		if (isdigit(c))
		{
			pos[j++] = c;
// 			i++;
			while (isdigit(c = in[i]))
			{
				pos[j++] = c;
				i++;
			}
			pos[j++] = ' ';
		}
		else if (isspace(c))
		{ /* Skip whitespace characters */
			while (isspace(in[i]))
				i++;
		}
		else if (isop(c))
		{
			while (!underflow(stk))
			{
				tmp = pop(&stk);
				if (prec(c) > prec(tmp))
				{
					pos[j++] = tmp;
					pos[j++] = ' ';
				}
				else
				{
					push(&stk, tmp);
					break;
				}
			}
			push(&stk, c);
		}
		else if (c == '(')
			push(&stk, c);
		else if (c == ')')
		{
			while (!underflow(stk))
			{
				tmp = pop(&stk);
				if (tmp == '(')
					break;
				pos[j++] = tmp;
				pos[j++] = ' ';
			}
		}
	}

	while (!underflow(stk))
	{
		pos[j++] = pop(&stk);
		pos[j++] = ' ';
	}

	pos[j++] = '$';
	pos[j++] = '\0';
}

int isop(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void push(Stack *s, char c)
{
	struct stk_elem *newelem;

	newelem = (struct stk_elem *)malloc(sizeof(struct stk_elem));
	newelem->op = c;
	newelem->next = *s;
	*s = newelem;
}

char pop(Stack *s)
{
	char c;
	struct stk_elem *tmp, *top;

	tmp = *s;
	c = tmp->op;
	*s = tmp->next;
	free(tmp);

	return c;
}

int underflow(Stack s)
{
	return (s == NULL);
}

int prec(char c)
{
	switch (c)
	{
	case '(':
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;
	}
}
