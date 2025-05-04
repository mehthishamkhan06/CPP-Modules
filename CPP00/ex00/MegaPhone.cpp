#include <iostream>

int main(int argc, char *argv[])
{
	int i = 1;
	int j = 0;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
		return (1);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			argv[i][j] = toupper(argv[i][j]);
			j++;
		}
		std::cout << argv[i] ;
		if (argv[i + 1])
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}