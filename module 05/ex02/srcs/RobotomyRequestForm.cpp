/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/03 18:07:11 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): Form("RobotomyRequestForm"), _target("default")
{ 
    this->_gradeRequiredForSignature = ROBOTOMY_SIGNATURE;
    this->_gradeRequiredForExecution = ROBOTOMY_EXECUTION;
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): Form("RobotomyRequestForm"), _target(target)
{
    this->_gradeRequiredForSignature = ROBOTOMY_SIGNATURE;
    this->_gradeRequiredForExecution = ROBOTOMY_EXECUTION;
    std::cout << "RobotomyRequestForm string constructor for target " << target << " called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &copy ): Form("RobotomyRequestForm"), _target(copy._target)
{
    this->_gradeRequiredForSignature = copy._gradeRequiredForSignature;
    this->_gradeRequiredForExecution = copy._gradeRequiredForExecution;
    *this = copy;
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    return;
}

RobotomyRequestForm    &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs )
{
    Form::operator=(rhs);
	this->_target = rhs._target;
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    std::cout << "RobotomyRequestForm " << this->getName() << " destructor called" << std::endl;
    return;
}

std::string RobotomyRequestForm::getTarget( void ) const
{
    return (this->_target);
}

void    RobotomyRequestForm::beExecuted( Bureaucrat const &executor ) const
{
    (void)executor;
    if ((rand() % 100) > 49)
        std::cout << "Target" << this->_target << " has been robotomised successfuly !" << std::endl;
    else
        std::cout << this->_target << " robotomisation has failed !" << std::endl;
}

std::ostream &operator<<( std::ostream &o, RobotomyRequestForm *a )
{
    o << "RobotomyRequestForm " << a->getName() << " :" << std::endl <<
         "Grade required for signature : " << a->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << a->getGradeRequiredForExecution() << std::endl <<
         "Status : " << a->getIsSigned() << std::endl;
    return (o);
}