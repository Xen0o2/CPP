/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:47:09 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/12 19:15:38 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook( void )
{
    this->_contactCount = 0;
    return;
}

PhoneBook::~PhoneBook( void )
{
    return;
}

int    PhoneBook::add( void )
{
    if (this->_contactCount == 8)
    {
        std::cout << std::endl << "Nombre maximum de contact atteint !" << std::endl << std::endl;
        return (0);
    }
    
    Contact contact;
    
    std::cout << "Prénom : ";
    std::cin >> contact.firstname;
    std::cout << "Nom : ";
    std::cin >> contact.lastname;
    std::cout << "Surnom : ";
    std::cin >> contact.nickname;
    std::cout << "Numéro de téléphone : ";
    std::cin >> contact.phoneNumber;
    std::cout << "Plus lourd secret : ";
    std::cin >> contact.darkestSecret;
    std::cout << std::endl << "Utilisateur ajouté !" << std::endl << std::endl;
    this->_contact[this->_contactCount++] = contact;
    return (1);
}

void    PhoneBook::_display( void )
{
    for(int i = 0; i < this->_contactCount; i++)
        this->_contact[i].display(i);
}

void    PhoneBook::search( void )
{
    int index;
    
    this->_display();
    if (this->_contactCount == 0)
        std::cout << std::endl << "Le répertoire est vide !" << std::endl << std::endl;
    else
    {
        std::cout << std::endl << "Numéro : ";
        std::cin >> index;
        index--;
        if (index < 0 || index > this->_contactCount || index > 8)
            std::cout << std::endl << "Utilisateur introuvable !" << std::endl << std::endl;
        else
            this->_contact[index].showInformation();
    } 
}
