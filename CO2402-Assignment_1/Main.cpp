#include "Random.h"
#include "Constants.h"

int main()
{
	// A random number generator actually produces a pseudo-random sequence of numbers.
	// This means that the random number generator will always produce the same sequence of numbers.
	// The generator needs to be "seeded" with a value. You seed the generator with the function srand().
	// If you want to create a different sequence of numbers each time then seed it with the time as follows:
	srand(static_cast<unsigned int> (time(0)));
	// The output of time() is time_t (which is actually an int).
	// static_cast<unsigned int> merely converts the output of time() into an unsigned integer.
	for (int i = 0; i < 10; i++)
	{
		cout << Random() << endl;
	}
	cout << endl;

	// However, if you seed the generator with the same value each time then it will always produce
	// the same sequence of numbers. You want this to occur with the Monopoly program.
	// The next bit of code does this:
	srand(4);
	for (int i = 0; i < 10; i++)
	{
		cout << Random() << endl;
	}
	system("pause");

	/********MAIN GAME NOTES*********/

	//26 square board 
	//2 Players
	//Default - P1 is dog, P2 is car
	//Players recieve 1500£ at beginning of game - the bank has unlimited money
	//Each player having one move is called a round - in a round each player takes 1 turn
		//- rolls the dice, moves clockwise by num of squares.
	//No user input - game is simulation
	//Play for 20 rounds
	//Welcome message - 'Welcome to Monopoly'


	/********END MAIN GAME NOTES*******/




}