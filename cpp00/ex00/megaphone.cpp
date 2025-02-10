#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **av)
{

    if(ac < 2)
    {
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for(int i = 1; i < ac; i++)
    {
        std::string argv = av[i];
        for(unsigned long int j = 0; j < argv.length() ; j++)
            argv[j] = std::toupper(argv[j]);
        std::cout << argv;
        if(i != ac - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}
