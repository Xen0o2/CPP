/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/03 18:06:46 by alecoutr         ###   ########.fr       */
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
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox";
}

std::ostream &operator<<( std::ostream &o, PresidentialPardonForm *a )
{
    o << "PresidentialPardonForm " << a->getName() << " :" << std::endl <<
         "Grade required for signature : " << a->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << a->getGradeRequiredForExecution() << std::endl <<
         "Status : " << a->getIsSigned() << std::endl;
    return (o);
}