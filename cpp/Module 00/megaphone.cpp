#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
    int i = 1;
    (void)argv;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (i < argc)
    {
        int j = 0;
        while (argv[i][j])
        {
            std::cout << (char)std::toupper(argv[i][j]);
            j++;
        }
        if  (i < argc - 1)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return (0);
}