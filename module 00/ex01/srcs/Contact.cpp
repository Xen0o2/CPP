/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:11:54 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/12 18:30:00 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact( void )
{
    return;
}

Contact::~Contact( void )
{
    return;
}

void Contact::display(int index)
{
    std::cout << std::setw(10);
    std::cout << index + 1 << " | ";
    std::cout << std::setw(10);
    put_length(this->firstname);
    std::cout << " | " << std::setw(10);
    put_length(this->lastname);
    std::cout << " | " << std::setw(10);
    put_length(this->nickname);
    std::cout << std::endl;
}

void	Contact::showInformation( void )
{
	std::cout << "Prénom : " << this->firstname << std::endl;
	std::cout << "Nom : " << this->lastname << std::endl;
	std::cout << "Surnom : " << this->nickname << std::endl;
	std::cout << "Numéro de téléphone : " << this->phoneNumber << std::endl;
	std::cout << "Secret le plus lourd : " << this->darkestSecret << std::endl << std::endl;
}
