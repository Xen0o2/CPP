/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:37:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/03 18:16:58 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form
{
    private:
        ShrubberyCreationForm( void );
        std::string _target;
    public:
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( ShrubberyCreationForm const &copy );
        ShrubberyCreationForm &operator=( ShrubberyCreationForm const &rhs );
        ~ShrubberyCreationForm( void );

        std::string getTarget( void ) const;
        void    beExecuted( Bureaucrat const &executor ) const;
};