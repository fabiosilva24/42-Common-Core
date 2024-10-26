#include <iostream>

int main(int argc, char **argv)
{
	(void)argv;

    if (argc != 2)
    std::cerr << "Usage: ./webserv [configuration_file] " << std::endl;
}
