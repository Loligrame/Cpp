/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armohame <armohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:30:54 by armohame          #+#    #+#             */
/*   Updated: 2025/03/03 14:06:51 by armohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <iostream>
#include <fstream>

std::string replace_line(const std::string &line, const std::string &s1, const std::string &s2)
{
    std::string modified_line = line;
    size_t pos = 0;

    while ((pos = modified_line.find(s1, pos)) != std::string::npos)
    {
        modified_line.erase(pos, s1.length());
        modified_line.insert(pos, s2);
        pos += s1.length();
    }
    return modified_line;
}

void replace_file(std::string filename, std::string s1, std::string s2)
{
    std::ifstream   in;
    std::string     buff;

    in.open(filename.c_str());
    if (!in.is_open()) 
    {
        std::cerr << "Failed to open the file!" << std::endl;
        return ;
    }
    else
    {
        std::string new_file = filename += ".replace";
        std::ofstream out(new_file.c_str());
        if(!out)
        {
            std::cerr << "Can't create file" << std::endl;
            return ;
        }
        while(!in.eof())
        {
            std::getline(in ,buff);
            out << replace_line(buff, s1, s2) << std::endl;
        }
        in.close();
        out.close();
    }
}

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cerr << "Wrong arg number" << std::endl;
        return 1;
    }   
    std::string filename(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);
    replace_file(filename, s1, s2);
    return 0;
}