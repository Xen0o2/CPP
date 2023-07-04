/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:37:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/04 07:12:41 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        PresidentialPardonForm( void );
        std::string _target;
    public:
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm( PresidentialPardonForm const &copy );
        PresidentialPardonForm &operator=( PresidentialPardonForm const &rhs );
        ~PresidentialPardonForm( void );

        std::string getTarget( void ) const;
        void    beExecuted( Bureaucrat const &executor ) const;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm &form);
