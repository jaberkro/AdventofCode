#include <iostream>
#include <fstream>
#include <string>

#define SIZE 5000 //7

void displayArray(long long toPrint[SIZE])
{
	for (int i = 0; i < SIZE; i++)
		std::cout << "[" << toPrint[i] << "]";
	std::cout << "[null]" << std::endl; 
}

int findIndex(long long data, long long mixing[SIZE])
{
	int	i = 0;

	while (mixing[i] != data)
		i++;
	return (i);
}

int main(void)
{
	long long	inputs[SIZE];
	long long	mixing[SIZE];
	long long	indices[SIZE];
	int	index = 0;
	std::ifstream myfile("input.txt");
	std::string line;
	long long	tmp;

	if (myfile.is_open())
	{
		while (getline (myfile,line))
		{
			inputs[index] = stoll(line) * 811589153;
			mixing[index] = stoll(line) * 811589153;
			indices[index] = index;
			index++;
		}
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
	
	for (int k = 0; k < 10; k++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			// std::cout << inputs[i] << std::endl;
			// displayArray(mixing);
			index = findIndex(i, indices);
			if (inputs[i] > 0)
			{
				for (int j = 0; j < inputs[i] % (SIZE - 1); j++)
				{
					tmp = mixing[(index + j) % (SIZE)];
					mixing[(index + j) % (SIZE)] = mixing[(index + j + 1) % (SIZE)];
					mixing[(index + j + 1) % (SIZE)] = tmp;
					tmp = indices[(index + j) % (SIZE)];
					indices[(index + j) % (SIZE)] = indices[(index + j + 1) % (SIZE)];
					indices[(index + j + 1) % (SIZE)] = tmp;
				}
			}
			else if (inputs[i] < 0)
			{
				for (int j = 0; j < abs(inputs[i]) % (SIZE - 1); j++)
				{
					while (index - j < 0 || index - j - 1 < 0)
						index += SIZE;
					tmp = mixing[(index - j) % (SIZE)];
					mixing[(index - j) % (SIZE)] = mixing[(index - j - 1) % (SIZE)];
					mixing[(index - j - 1) % (SIZE)] = tmp;
					tmp = indices[(index - j) % (SIZE)];
					indices[(index - j) % (SIZE)] = indices[(index - j - 1) % (SIZE)];
					indices[(index - j - 1) % (SIZE)] = tmp;
				}
			}
			// displayArray(mixing);
			// std::cout << std::endl;
		}
	}
	index = findIndex(0, mixing);
	std::cout << "index 0: " << index << std::endl;
	std::cout << mixing[(index + 1000) % SIZE] << " + ";
	std::cout << mixing[(index + 2000) % SIZE] << " + ";
	std::cout << mixing[(index + 3000) % SIZE] << " = ";
	std::cout << mixing[(index + 1000) % SIZE] + \
		mixing[(index + 2000) % SIZE] + \
		mixing[(index + 3000) % SIZE] << std::endl;
}
