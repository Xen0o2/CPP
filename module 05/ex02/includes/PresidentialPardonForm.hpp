/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:37:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/03 17:43:20 by alecoutr         ###   ########.fr       */
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