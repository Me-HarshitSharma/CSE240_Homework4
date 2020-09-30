//this is a program to check weather a string is palindrome or not
#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996) // Visual Studio Compiler Directive

// Read before you start:
// Do not modify any part of this program that you are given. Doing so may cause you to fail automated test cases.
// You are given a partially complete program. Your job is to complete the functions in order for this program to work successfully.
// You should complete this homework assignment using Microsoft Visual Studios 2013 (or a later version).
// All instructions are given above the required functions, please read them and follow them carefully. 
// If you modify the function return types or parameters, you will fail the automated test cases.
// You can assume that all inputs are valid. Ex: If prompted for a char, the input will be a char.

// Global Macro Values
#define NUM_STRINGS 5
#define STRING_LENGTH 32

// Forward Declarations

void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void frequency(char[NUM_STRINGS][STRING_LENGTH], char);
void remove_Number(char[NUM_STRINGS][STRING_LENGTH]);
void swapStrings(char[STRING_LENGTH], char[STRING_LENGTH]);
void sortStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
int alpha_Counter(char[STRING_LENGTH]);
int isAPalindrome(char[STRING_LENGTH]);
void addLetter(char[STRING_LENGTH], char, int);

char dummyStringArray[NUM_STRINGS][STRING_LENGTH];

void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH]) {
	char *point = &strings[0][0];
	for (int i = 0; i < NUM_STRINGS; i++) {
		for (int j = 0; j < STRING_LENGTH; j++) {
			*point = '\0';
			point++;
		}
	}
}
// Problem 1: frequency (5 points)
// Rewrite this function to perform the same task as in hw03, using only pointer operations.
// You must use pointer operations only. If you use array operations, you will recieve no credit for this part.
// You may use the code you submitted for hw03 or you may use the solution code for hw03.
// Traverse the 2D array of characters variable 'strings' and check the frequency of a particular letter or a search_alphabetin a string.
// In order to check the frequency, first you need to read the search_alphabet from the user.
// If the string is "hello" and the search_alphabet is l, the code will count the number of 'l's in hello.
// The output of the function for the above mentioned case will be 2.
//append that frequency value at the end of the string
//for hello the new string will be hello2

void frequency(char strings[NUM_STRINGS][STRING_LENGTH], char search_alphabet)
{
	char *frequency; //To count the number of times the char appears in each string
	int amount; //To keep track of where to append the string
	for (int i = 0; i < NUM_STRINGS; i++) {
		//Set these values to 0 for each string in the array
		frequency = &strings[i][0];
		amount = 0;
		//Move through the list until reaching terminating point, counting the amount of times the char given appears.
		while (*frequency != '\0') {
			if (*frequency == search_alphabet) {
				amount++;
			}
			frequency++;
		}
		//Print out the frequency
		printf("The frequency of %c in %s is: %d\n", search_alphabet, &strings[i][0], amount);

		//Append the frequency to the string
		*frequency = amount + '0';
		frequency++;
		*frequency = '\0';
	}

}

// Problem 2: remove_vowel (5 points)
// Rewrite this function to perform the same task as in hw03, using only pointer operations.
// You must use pointer operations only. If you use array operations, you will recieve no credit for this part.
// You may use the code you submitted for hw03 or you may use the solution code for hw03.
//Traverse the 2D array of characters variable 'strings' and remove all vowels from the string.
// In order to remove all vowel characters, you need to check each letter of the string and decide whether its is a vowel. If so then remove it. If not then check the next character.
// If the string is "hello", your result will be hll.
//print the new string without vowel using problem 6.

void remove_vowel(char strings[NUM_STRINGS][STRING_LENGTH])
{
	initializeStrings(dummyStringArray);
	char *copyPointer;
	char *string;
	for (int i = 0; i < NUM_STRINGS; i++) {
		copyPointer = dummyStringArray[i];
		string = strings[i];
		while (*string != '\0') {
			if (*string != 'a' && *string != 'A' && *string != 'e' && *string != 'E' && *string != 'i' && *string != 'I' && *string != 'o' && *string != 'O' && *string != 'u' && *string != 'U') {
				*copyPointer = *string;
				copyPointer++;
			}
			string++;
		}
		string = strings[i];
		copyPointer = dummyStringArray[i];
		strcpy(string, copyPointer);
	}
}

void swapStrings(char string1[STRING_LENGTH], char string2[STRING_LENGTH])
{
	char temp[STRING_LENGTH];
	strcpy(temp,string1);
	strcpy(string1, string2);
	strcpy(string2, temp);
}

// Problem 3: sortStrings (10 points)
// Rewrite this function to perform the same task as in hw03, using only pointer operations.
// You must use pointer operations only. If you use array operations, you will recieve no credit for this part.
// You can use the swapStrings() function if you'd like, but are not required to do so.
// You may use the code you submitted for hw03 or you may use the solution code for hw03.
//
// Sort the 5 strings contained in the 2D character array parameter labeled "strings".
// Sort the strings based on their ASCII character value (use strcmp to compare strings).
// NOTE: You MUST incorporate your "swapStrings" function to recieve full points for this part.
// See the output provided in the word document for example input and output.
void sortStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	initializeStrings(dummyStringArray);
	char *lowestString;
	char *string;
	char *position;
	for (int i = 0; i < NUM_STRINGS - 1; i++) {
		lowestString = &dummyStringArray[i][0];
		string = &strings[i][0];
		position = &strings[i][0];
		strncpy(lowestString, string, STRING_LENGTH);
		for (int j = i; j < NUM_STRINGS-1; j++) {
			string += STRING_LENGTH;
			if (strcmp(lowestString, string) > 0) {
				strncpy(lowestString, string, STRING_LENGTH);
				position = string;
			}
		}
		
		string = &strings[i][0];
		swapStrings(position, string);
	}
}

void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	int i;
	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("%s\n", strings[i]);
	}
}

// Problem 4: vowelCounter (10 points)
// This function accepts an array of characters and returns the number of alphabets in that string (an integer).
// You must use pointer operations only. If you use array operations, you will recieve no credit for this part.
// you should not count any number or special character within the string
int alpha_Counter(char string[STRING_LENGTH])
{
	char *beginning = &string[0];
	int amount = 0;
	while (*beginning != 0) {
		if ((*beginning >= 'a' && *beginning <= 'z') || (*beginning >= 'A' && *beginning <= 'Z')) {
			amount++;
		}
		beginning++;
	}
	return amount;
}

// Problem 5: isAPalindrome (10 points)
// This function accepts an array of characters and returns an integer.
// You must use pointer operations only. If you use array operations, you will recieve no credit for this part.
// This function should return 1 (true) if the parameter 'string' is a palindrome, or 0 (false) if 'string' is not a palindrome.
// A palindrome is a sequence of characters which when reversed, is the same sequence of characters.
// For this assignment, you can assume that 'string' will be a single word containing only lowercase letters and no spaces.
// Example Palindromes: mom, racecar, stats, rotator, deleveled
int isAPalindrome(char string[STRING_LENGTH])
{
	int isPalindrome = 1;

	char *beginning = &string[0];

	while (*beginning != '\0') {
		beginning++;
	}

	char *end = beginning-1;
	beginning = &string[0];

	while (*beginning != '\0') {
		if (*end != *beginning) {
			isPalindrome = 0;
		}
		beginning++;
		end--;
	}
	return isPalindrome;
}

// Problem 6: addLetter (10 points)
// This function accepts an array of characters as well as a character to be added to the existig string and a position where this new letter is to be added.
// You must use pointer operations only. If you use array operations, you will recieve no credit for this part.
// All occurances of the 'letterToBeRemoved' should be removed from character array 'string'
// Example: If string = "letter", and letterToAdd = 'a'; the pos=2 after this function terminates, string should contain "leatter"
void addLetter(char string[STRING_LENGTH], char letterToAdd, int pos)
{
	char *pointer = &string[0];
	int amountOfChars = 0;

	do {
		pointer++;
		amountOfChars++;
	} while (*pointer != '\0');
	while (amountOfChars > pos) {
		*pointer = *(pointer - 1);
		pointer--;
		amountOfChars--;
	}
	*pointer = letterToAdd;
}

// You should study and understand how this main function works.
// Do not modify it in any way, there is no implementation needed here.
void main()
{

	int selection, i;
	char input[STRING_LENGTH];

	printf("Assignment 4: Pointer Operations\n\n");
	printf("Choose one of the following: \n1. Sorting Strings\n2. Alphabet counter\n3. Palindrome\n4. Letter Addition\n\n");
	scanf("%d", &selection); // store integer
	getchar(); // consume newline char

	if (selection == 1)
	{
		char strings[NUM_STRINGS][STRING_LENGTH]; // will store 5 strings each with a max length of 32
		char search_alphabet;

		for (i = 0; i < NUM_STRINGS; i++)
		{
			printf("\nEnter the next String: "); // prompt for string
			fgets(input, sizeof(input), stdin); // store input string
			input[strlen(input) - 1] = '\0'; // convert trailing '\n' char to '\0' (null terminator)
			strcpy(strings[i], input); // copy input to 2D strings array
		}


		printf("Enter a character for checking its frequency: "); // prompt for integer
		scanf("%c", &search_alphabet); // store integer
		frequency(strings, search_alphabet);
		remove_vowel(strings);
		printf("\nThe strings after vowel removal:\n");
		printStrings(strings);
		sortStrings(strings);
		printf("\nSorted Strings:\n");
		printStrings(strings);

	}
	else if (selection == 2)
	{
		printf("\nEnter a String: "); // prompt for string
		fgets(input, sizeof(input), stdin); // store input string
		input[strlen(input) - 1] = '\0'; // convert trailing '\n' char to '\0' (null terminator)

		int numAlpha = alpha_Counter(input);

		printf("\nThere are %d alphabets in \"%s\"", numAlpha, input);
	}
	else if (selection == 3)
	{
		printf("\nEnter a String: "); // prompt for string
		fgets(input, sizeof(input), stdin); // store input string
		input[strlen(input) - 1] = '\0'; // convert trailing '\n' char to '\0' (null terminator)

		int isPalindrome = isAPalindrome(input);

		if (isPalindrome)
			printf("\nThe string \"%s\" is a palindrome", input);
		else
			printf("\nThe string \"%s\" is not a palindrome", input);
	}
	else if (selection == 4)
	{
		printf("\nEnter a String: "); // prompt for string
		fgets(input, sizeof(input), stdin); // store input string
		input[strlen(input) - 1] = '\0'; // convert trailing '\n' char to '\0' (null terminator)

		char letterToAdd;
		int pos;
		printf("\nEnter a letter to be added: "); // prompt for char
		scanf(" %c", &letterToAdd); // store input char
		printf("\nEnter the array position for adding the letter:");
		scanf("%d", &pos);
		addLetter(input, letterToAdd, pos);

		printf("\nResult: %s", input);
	}
	else
	{
		printf("Program terminating...");
	}
}
