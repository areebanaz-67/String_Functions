#include<iostream>
#include<iomanip>
#include<conio.h>
#include <windows.h>

using namespace std;
void input(char[]);
void mystrcpy(char[], char[]);
void mystrcat(char[], char[]);
int mystrlen(char[]);
int mystrcompare(char[], char[]);
void search(char[], char[]);
void insert(char[], char[], int);
void remove(char[], char[], int, int);
int main()
{
	int len, lastind;
	char str1[40];
	char str2[40];
	char ch1;
	while (1)
	{
		//system("cls");

		cout << setw(25) << "-------------" << endl

			<< setw(25) << "| MAIN MENU |" << endl

			<< setw(25) << "-------------" << endl << endl

			<< setw(52)

			<< "Please choose one of the options below: "

			<< endl << setw(71)

			<< "--------------------------------------------------------------"

			<< endl << endl



			<< setw(27) << "( I ) INPUT STRING " << endl << endl

			<< setw(28) << "( N ) INSERT STRING " << endl << endl

			<< setw(25) << "( C ) COPY STRING" << endl << endl

			<< setw(32) << "( T ) CONCATINATE STRING" << endl << endl

			<< setw(30) << "( L ) LENGTH OF STRING" << endl << endl

			<< setw(28) << "( P ) COMPARE STRING" << endl << endl

			<< setw(28) << "( S ) SEARCH STRING " << endl << endl

			<< setw(21) << "( R ) REMOVE " << endl << endl

			<< setw(18) << "( Q ) Quit" << endl << endl
			<< setw(30) << "Enter Option      [ ]" << endl << endl;

		cin >> ch1;


		switch (ch1)
		{
		case 'i':
		case 'I':
			input(str1);
			//put(str2);
			cout << "The string 1 is:" << str1 << endl;
			input(str2);
			cout << "The string 2 is:" << str2 << endl;
			break;

		case 'n':
		case 'N':
			cout << "enter the index to insert 2nd string :";
			cin >> len;
			insert(str1 ,str2,len);
			cout << "The string 1 is:" << str1 << endl;
			cout << "The string 2 is:" << str2 << endl;
			break;

		case 'r':
		case 'R':
			cout << "enter the starting index to delete ";
			cin >> len;
			cout << "enter the last index to delete ";
			cin >> lastind;
			remove(str1, str2, len, lastind);
			cout << "The string 1 is:" << str1 << endl;
			cout << "The string 2 is:" << str2 << endl;
			break;
		case 'c':
		case 'C':
			mystrcpy(str1, str2);
			cout << "The string 1 is:" << str1 << endl;
			cout << "The string 2 is:" << str2 << endl;
			break;

		case 'l':
		case 'L':
			len = mystrlen(str1);
			cout << "the length of string 1 is :" << len << endl;
			len = mystrlen(str2);
			cout << "the length of string 2 is :" << len << endl;
			break;
		case 't':
		case 'T':
			mystrcat(str1, str2);
			cout << "The string 1 is:" << str1 << endl;
			cout << "The string 2 is:" << str2 << endl;
			break;
		case 'p':
		case 'P':
			len = mystrcompare(str1, str2);
			//len = _strcmpi(str1, str2);
			if (len == 1)
				cout << "the string 1 is greater than string 2" << endl;
			else if (len == -1)
				cout << "the string 1 is smaller than string 2" << endl;
			else
				cout << "the string 1 is equal to string 2" << endl;
			break;

		case 's':
		case 'S':
			search(str1, str2);
			break;
		case 'q':
		case 'Q':exit(0); break;
		default:
			puts("\n enter only from selection listed");
		} //end switch
	}//end while
	//etch();
	//cdecl _getch();

	system("pause");
	return 0;
}


////////input/////////
void input(char st[])
{
	cin.ignore();
	cout << "Enter the string :";
	cin.getline(st,40);
	//_getch();
}
void mystrcpy(char s1[], char s2[])
{
	//stem("cls");
	int i;
	for (i = 0; s2[i] != '\0'; i++)
	{
		s1[i] = s2[i];
	}
	s1[i] = '\0';
	//_getch();
}
void mystrcat(char s1[], char s2[])
{
	//stem("cls");
	int i, j;
	for (i = 0; s1[i] != '\0'; i++)
	{
	}

	for (j = 0; s2[j] != '\0'; j++, i++)
	{
		s1[i] = s2[j];
	}
	s1[i] = '\0';
	//_getch();
}

int mystrlen(char s[])
{
	//stem("cls");
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return i;
	//_getch();
}

int mystrcompare(char s1[], char s2[])
{
	int l1, l2, i = 0;
	l1 = mystrlen(s1);
	l2 = mystrlen(s2);
	/*if (l1 > l2)
		return 1;
	else if (l1 < l2)
		return -1;
	else
	{*/
		while (s1[i] != '\0') {
			if (s1[i] == s2[i])
				i++;
			else if (s1[i] > s2[i])
				return 1;
			else
				return -1;
		}
		if (s1[i] == s2[i])
			return 0;
		else if (s1[i] > s2[i])
			return 1;
		else
			return -1;
	//}
	//_getch();
}

void search(char s1[], char s2[])
{
	int l1, l2 ,ind=-1 ,i=0 ,j=0;
	l1 = mystrlen(s1);
	l2 = mystrlen(s2);
	if (l2 > l1)
		ind = -1;
	else
		while (i<l1 && j != l2)
		{
			if (s1[i] == s2[j]) {
				j++;
				ind = i;
			}
			else {
				j = 0;
				ind = -1;
			}
			i++;
		}
	if (j == l2)
		cout << "string is found at index " << ind - j +1 <<endl;
	else if (ind == -1 || j != l2)
		cout << "string not found " << endl;
}

void insert(char s1[], char s2[], int ind)
{
	int l1, l2 ,i,j,k,l=ind;
	l1 = mystrlen(s1);
	l2 = mystrlen(s2);
	j = l1-1;
	for (i = l1+ l2-1; j>=ind ; i--,j--)
	{
		s1[i] = s1[j];
	}
	for (k = 0; k < l2; k++ ,l++)
	{
		s1[l] = s2[k];
	}
	s1[l1+l2] = '\0';
}

void remove(char s1[], char s2[], int sind,int lind)
{
	int i, j = sind, l1;
	l1 = mystrlen(s1);
	for (i = lind + 1; i < l1 ;i++ ,j++){
		s1[j] = s1[i];
	}
	s1[l1 - (lind - sind + 1)] = '\0';
}

        