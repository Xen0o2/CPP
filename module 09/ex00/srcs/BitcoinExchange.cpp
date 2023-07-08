/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:01:03 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/08 12:04:43 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	std::cout << "Default constructor called" << std::endl;

	std::ifstream file ("./data.csv");
	if (!file.is_open())
		throw BitcoinExchange::cantOpenDataException();
	
	std::string line;
	int			i = 1;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		int index = line.find(',');
		if (index == -1)
		{
			std::cerr << "Invalid parameter at line " << i << std::endl;
			continue;
		}
		std::string date = line.substr(0, index);
		float		value;

		try
		{
			value = std::stod(line.substr(index + 1));
		}
		catch(std::exception &e)
		{
			std::cerr << "Couldn't parse value at line " << (i + 1) << std::endl;
			continue;
		}
		this->setData(date, value);
		i++;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

BitcoinExchange	&BitcoinExchange::operator=( BitcoinExchange const &rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_data = rhs._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void )
{
	std::cout << "Destructor called" << std::endl;
}

std::map<std::string, float>	BitcoinExchange::getData( void )
{
	return (this->_data);
}

void	BitcoinExchange::setData( std::string date, float value )
{
	this->_data.insert(std::make_pair(date, value));
}

std::vector<std::string>	BitcoinExchange::split( std::string line )
{
	std::vector<std::string>	result;
	std::string					tmp = "";

	for(int i = 0; i < line.length(); i++)
	{
		if (line[i] != '|')
			tmp += line[i++];
		else
		{
			result.push_back(tmp);
			tmp = "";
			while (line[i] == '|')
				i++;			
		}
	}
	
	result.push_back(tmp);
	return (result);
}

void	BitcoinExchange::readInput( std::string path )
{
	std::ifstream file (path);
	if (!file.is_open())
		throw BitcoinExchange::cantOpenInputFile();

	std::string 				line;
	std::vector<std::string>	lineVector;
	int							i = 1;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		vectorLine = this->split(line);
		if (vectorLine.size() != 2)
		{
			std::cout << "Error: bad input at line " << (i + 1) << std::endl;
			continue;
		}
		
	}
}
