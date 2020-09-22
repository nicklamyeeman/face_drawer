/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** main
*/

#include <fstream>
#include <cstring>
#include "Window.hpp"

int display_help()
{
    std::string line;
    std::ifstream helpFile (".help");
    if (helpFile.is_open()) {
        while (std::getline(helpFile,line))
            std::cout << line << std::endl;
        helpFile.close();
    }
    else {
        std::cerr << "Unable to display the help menu, please contact the developer : \"https://github.com/nicklamyeeman\"" << std::endl;
        return (-1);
    }
    return (0);
}

int start_project(int ac, char **av)
{
    std::ifstream in(av[1]);
    if (!in) {
        std::cerr << "Unable to open the file \"" << av[1] << "\"." << std::endl;
        return (-1);
    }
    unsigned int width, height;

    in.seekg(16);
    in.read((char *)&width, 4);
    in.read((char *)&height, 4);

    width = ntohl(width);
    height = ntohl(height);

    Window window(width, height, "Face Drawer window");
    window.startWindow(av[1]);

    if (ac == 3)
        window.exportImage(av[2]);
    return (0);
}
int main(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        std::cerr << "Error : wrong number of arguments." << std::endl;
        std::cerr << "Try with -h or --help" << std::endl;
        return (-1);
    }
    if (strcmp(av[1], "--help") == 0 || strcmp(av[1], "-h") == 0)
        return (display_help());

    return (start_project(ac, av));
}