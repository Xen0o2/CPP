/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/04 07:50:43 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): Form("PresidentialPardonForm"), _target("default")
{ 
    this->_gradeRequiredForSignature = PRESIDENTIAL_SIGNATURE;
    this->_gradeRequiredForExecution = PRESIDENTIAL_EXECUTION;
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): Form("PresidentialPardonForm"), _target(target)
{
    this->_gradeRequiredForSignature = PRESIDENTIAL_SIGNATURE;
    this->_gradeRequiredForExecution = PRESIDENTIAL_EXECUTION;
    std::cout << "PresidentialPardonForm string constructor for target " << target << " called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &copy ): Form("PresidentialPardonForm"), _target(copy._target)
{
    this->_gradeRequiredForSignature = copy._gradeRequiredForSignature;
    this->_gradeRequiredForExecution = copy._gradeRequiredForExecution;
    *this = copy;
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    return;
}

PresidentialPardonForm    &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs )
{
    Form::operator=(rhs);
	this->_target = rhs._target;
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    std::cout << "PresidentialPardonForm " << this->getName() << " destructor called" << std::endl;
    return;
}

std::string PresidentialPardonForm::getTarget( void ) const
{
    return (this->_target);
}

void    PresidentialPardonForm::beExecuted( Bureaucrat const &executor ) const
{
    (void)executor;
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

Form    *PresidentialPardonForm::makeForm( Form *form, std::string const &type, std::string const &target )
{
    if (!form && type == "presidential pardon")
        return (new PresidentialPardonForm(target));
    return (form);
}

std::ostream &operator<<( std::ostream &o, PresidentialPardonForm *form )
{
    o << "PresidentialPardonForm " << form->getName() << " :" << std::endl <<
         "Grade required for signature : " << form->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << form->getGradeRequiredForExecution() << std::endl <<
         "Status : " << form->getIsSigned() << std::endl;
    return (o);
}
