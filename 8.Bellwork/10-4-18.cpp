
/*Write a function that takes as its parameter an array called input_array of integers,
the array size, and a second array of the same size called output_array.
Fill each statement in the second array to be the value in the same index of input array multiplied by its index in the array./*/
char fillArrays(char inputArray[], char outputArray[])
{
	char A = 0;
	char B = 1;
	char C = 2;
	char tempArray[3] =
	{
		A,B,C,
	};
	for (inputArray = tempArray; tempArray > 0; +0)
	{

		inputArray[1] = tempArray[1];
		inputArray[2] = tempArray[2];
		inputArray[3] = tempArray[3];

		return outputArray[1] = inputArray[1],
			outputArray[2] = inputArray[2],
			outputArray[3] = inputArray[3];
	}

	return outputArray[3];
};
int main()
{
	char inArray[3];
	char outArray[3];
	fillArrays(inArray, outArray);

}