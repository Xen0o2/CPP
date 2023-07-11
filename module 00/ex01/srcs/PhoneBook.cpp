/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:47:09 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/11 11:30:54 by alecoutr         ###   ########.fr       */
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
    
    Contact     contact;
    std::string tmp = "";

    while (!std::cin.eof() && tmp == "")
    {
        std::cout << "Prénom : ";
        if (getline(std::cin, tmp) && tmp != "")
            contact.setFirstname(tmp);
    }
    tmp = "";
    while (!std::cin.eof() && tmp == "")
    {
        std::cout << "Nom : ";
        if (getline(std::cin, tmp) && tmp != "")
            contact.setLastname(tmp);
    }
    tmp = "";
    while (!std::cin.eof() && tmp == "")
    {
        std::cout << "Surnom : ";
        if (getline(std::cin, tmp) && tmp != "")
            contact.setNickname(tmp);
    }
    tmp = "";
    while (!std::cin.eof() && tmp == "")
    {
        std::cout << "Numéro : ";
        if (getline(std::cin, tmp) && tmp != "")
            contact.setPhoneNumber(tmp);
    }
    tmp = "";
    while (!std::cin.eof() && tmp == "")
    {
        std::cout << "Secret : ";
        if (getline(std::cin, tmp) && tmp != "")
        {
            contact.setDarkestSecret(tmp);
            std::cout << contact.getFirstname() << " a été ajouté avec succès (" << (this->_contactCount + 1) << "/8)" << std::endl;
        }
    }
    
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
    std::string tmp;
    int         index;
    
    this->_display();
    if (this->_contactCount == 0)
        std::cout << std::endl << "Le répertoire est vide !" << std::endl << std::endl;
    else
    {
        std::cout << std::endl << "Numéro : ";
        if (getline(std::cin, tmp))
        {
            try
            {
                index = std::stoi(tmp) - 1;
                if (index < 0 || index > this->_contactCount || index > 8)
                    std::cout << std::endl << "Utilisateur introuvable !" << std::endl << std::endl;
                else
                    this->_contact[index].showInformation();
            }
            catch (std::exception &e)
            {
                (void)e;
                std::cout << std::endl << "Utilisateur introuvable !" << std::endl << std::endl;    
            }
        }
    } 
}
