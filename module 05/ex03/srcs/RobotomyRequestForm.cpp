/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/04 07:50:51 by alecoutr         ###   ########.fr       */
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

Form    *RobotomyRequestForm::makeForm( Form *form, std::string const &type, std::string const &target )
{
    if (!form && type == "robotomy request")
        return (new RobotomyRequestForm(target));
    return (form);
}

std::ostream &operator<<( std::ostream &o, RobotomyRequestForm *form )
{
    o << "RobotomyRequestForm " << form->getName() << " :" << std::endl <<
         "Grade required for signature : " << form->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << form->getGradeRequiredForExecution() << std::endl <<
         "Status : " << form->getIsSigned() << std::endl;
    return (o);
}
