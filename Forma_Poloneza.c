#include<stdio.h>
#include<string.h>
void push(char st[], int *vf, char x)
{
	(*vf)++;
	st[*vf] = x;
}

int pop(char st[], int *vf)
{
	if (*vf > 0)
	{
		int x = st[*vf];
		(*vf)--;
		return x;
	}
	return -1;
}
int prioritate(char c)
{
	switch (c)
	{
	case '(':
	case ')':return 0;
	case '*':
	case '/':return 1;
	case '+':
	case '-':return 2;
	}
}
int peek(char st[], int vf)
{
	if (vf > 0)
		return st[vf];
	return -1; 
}
void afis(char st[], int vf)
{

	for (int i = 1; i <= vf; i++)
	{
		printf("%c", st[i]);
	}
	printf("\n");
	
}
int formaP(char sir[])
{
	int i;
	char st[100], fp[100],v,x,y;
	int vf = 0, vf2 = 0;
	char k[20];
	strcpy(k, "(*+-/ ");
	for (i = 0; i < (int)strlen(sir); i++)
	{
		afis(st, vf);
		afis(fp, vf2);
		if(sir[i]!=')')
			if(strchr(k,sir[i])!=0)
				push(st, &vf, sir[i]);
			else push(fp, &vf2, sir[i]);
		else {
			while (peek(st, vf) != '(')
			{
				v = peek(st, vf);
				push(fp, &vf2, v);
				pop(st, &vf);

			}
			pop(st, &vf);
		}
		
		
		if (vf >= 2)
		{
			x = pop(st, &vf);
			y = pop(st, &vf);
			if (prioritate(x) == 2 && prioritate(y) == 1)
			{
				push(fp, &vf2, y);
				push(st, &vf, x);
			}
			else {
				push(st, &vf, y);
				push(st, &vf, x);

			}
		}

	}

	for (int i = 1; i <= vf2; i++)
	{
		printf("%c", fp[i]);
	}
	printf("\n");
	return 0;
}

int main()
{
	char sir[100];
	printf("introduceti operatia");
	scanf("%s", sir);
	formaP(sir);
	return 0;
	
}