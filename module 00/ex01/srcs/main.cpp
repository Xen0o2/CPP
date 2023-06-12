/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:57:35 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/12 18:34:42 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	put_length(std::string string)
{
	if (string.size() > 10)
	{
		string.resize(9);
		std::cout << string << ".";
	}
	else
		std::cout << string;
}

int	main( void )
{
	int	run;
	std::string command;
	PhoneBook phonebook;

	run = 1;
	while (run)
	{
		std::cout << "Commande : ";
		std::cin >> command;
		
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			std::cout << "AU REVOIR" << std::endl, run = 0;
	}
}
