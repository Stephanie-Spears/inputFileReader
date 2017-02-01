#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<algorithm>

#define LETTER_RANGE 26


using namespace std;

void GetFileName(string& FileName) //do i need the ref?
{
	string FileType = ".txt";

	cout << "Enter the input file name: ";
	getline(cin, FileName);
	FileName.append(FileType);
	
}

struct Letter_Occurance
{
	int count;
	char c;
};

int main()
{
	string FileName; //is it bad practice to name it the same as the void variable?
	fstream inputfile;

	GetFileName(FileName);

	char c;
	int i;

	Letter_Occurance frequency[LETTER_RANGE];

	inputfile.open(FileName, fstream::in); 

	if (inputfile.fail())
	{
		cout << endl << "Input file name '" << FileName << "' does not exist." << endl;
		inputfile.close();
		return 1;
	}

	//initialize the array of structures 

	for (i = 0; i<LETTER_RANGE; i++) 
	{
		frequency[i].count = 0;
		frequency[i].c = ('A' + i);
	}

	//do till file ends ***but i can't get it to read a file that only has one letter. it loops the count twice, and reports one more letter than is in the file. but ONLY if the file only has one letter.

	while (!inputfile.eof())
	{
		inputfile.get(c);
		
		//increment counter for associated letter and change to upper

		if ('A' <= toupper(c) && toupper(c) <= 'Z')
		{
			frequency[toupper(c) - 'A'].count++;
		}
	}
	inputfile.close();

	//*should i change this into a print function?

	for (i = 0; i<LETTER_RANGE; i++)
	{
		if (frequency[i].count>0) //if i want to list 0 counts in array struct, >= 0 .. or actually just take out  if statement
		{
			cout << frequency[i].c << " " << frequency[i].count << endl;
		}	
	}
	return 0;
}
