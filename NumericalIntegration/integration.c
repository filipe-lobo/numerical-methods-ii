/*
*	Integration Methods: Main File
*	Author: Filipe Lobo - 344066
*/

#include "integration.h"

// Trapezoidal Rule.

float trapezoidal(int m, float* x, float* y)
{
	
	float h = (x[m] - x[0])/m;
	float t = 0;

	if(m == 1)
		t = (h/2) * (y[m] + y[0]);
	else
	{
		t = y[0] + y[m];
		int i;
		for(i = 1; i <= m-1; i++)
			t = t + y[i] * 2;
		t = t * (h/2);
	}

	return t;
}

// Simpson's 1/3 Rule.

float simpsonsThird(int m, float* x, float* y)
{
	float h = (x[m] - x[0])/m;
	float sr = 0;

	if(m == 2)
		sr = (h/3) * (y[0] + 4 * y[1] + y[2]);
	else
	{
		int i;
		for(i = 0; i <= m; i++)
		{
			if(i == 0 || i == m)
				sr = sr + y[i];
			else
			{
				if(i % 2 == 0)
					sr = sr + 2 * y[i];
				else
					sr = sr + 4 * y[i];
			}
		}
		sr = sr * (h/3);
	}

	return sr;
}

// Simpson's 3/8 Rule.

float simpsonsThreeEights(int m, float* x, float* y)
{
	float h = (x[m] - x[0])/m;
	float s2 = 0;

	if(m == 3)
		s2 = h * (3/8) * (y[0] + 3 * y[1] + 3 * y[2] + y[3]);
	else
	{
		int i;
		for(i = 0; i <= m; i++)
		{
			if(i == 0 || i == m)
				s2 = s2 + y[i];
			else
			{
				if(i % 3 == 0)
					s2 = s2 + 2 * y[i];
				else
					s2 = s2 + 3 * y[i];
			}
		}
		s2 = s2 * h * (3/8);
	}

	return s2;
}

// Test method to read the sample text file.

Variables readFile(char* filePath)
{
	FILE* file = fopen (filePath, "r");
	float i = 0;
	float j = 0;
	int counter = 0;
	Variables v;

	fscanf(file, "%f", &i);
	v.m = i;

	float auxX[v.m];
	float auxY[v.m];

	while(!feof(file))
	{
		fscanf(file, "%f\t%f", &i, &j);
		auxX[counter] = i;
		auxY[counter] = j;
		counter++;
	}

	v.x = auxX;
	v.y = auxY;

    fclose (file);

    return v;
}

// Main method

int main()
{

	// All methods are functional. Still working on the main running. 

	system("pause"); // Using to test on a Windows OS.
    return 1;
}
