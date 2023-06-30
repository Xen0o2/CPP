/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/30 17:27:52 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ): _name("default")
{
    this->_isSigned = false;
    this->_gradeRequiredForSignature = 150;
    this->_gradeRequiredForExecution = 150;
    std::cout << "Form default constructor called" << std::endl;
    return;
}

Form::Form( std::string name ): _name(name)
{
    this->_isSigned = false;
    this->_gradeRequiredForSignature = 150;
    this->_gradeRequiredForExecution = 150;
    std::cout << "Form string constructor called" << std::endl;
    return;
}

Form::Form( Form const &copy )
{
    std::cout << "Form copy constructor called" << std::endl;
    *this = copy;
    return;
}

Form    &Form::operator=( Form const &rhs )
{
    this->_isSigned = rhs._isSigned;   
    this->_gradeRequiredForSignature = rhs._gradeRequiredForSignature;
    this->_gradeRequiredForExecution = rhs._gradeRequiredForExecution;
    std::cout << "Form assignment operator called" << std::endl;
    return (*this);
}

Form::~Form( void )
{
    std::cout << "Form destructor called" << std::endl;
    return;
}

std::string Form::getName( void )
{
    return (this->_name);
}



std::string    Form::getIsSigned( void )
{
    if (this->_isSigned)
        return ("Signed");
    else
        return ("Not signed");
}

bool    Form::getIsSignedBool( void )
{
    return (this->_isSigned);
}

void    Form::beSigned( Bureaucrat &bureaucrat )
{
    std::cout << bureaucrat.getName() << " bureaucrat is trying to sign " << this->_name << " Form" << std::endl;
    if (this->_isSigned)
        std::cout << "Form already signed" << std::endl;
    else if (bureaucrat.getGrade() <= this->_gradeRequiredForSignature)
    {
        this->_isSigned = 1;
        std::cout << this->_name << " form signed by " << bureaucrat.getName() << " bureaucrat" << std::endl;
    }
    else
        throw Form::GradeTooLowException();
}

int     Form::getGradeRequiredForSignature( void )
{
    return (this->_gradeRequiredForSignature);
}

void Form::setGradeRequiredForSignature( int gradeRequiredForSignature )
{
    if (gradeRequiredForSignature > 150)
        throw Form::GradeTooLowException();
    else if (gradeRequiredForSignature < 1)
        throw Form::GradeTooHighException();
    else
        this->_gradeRequiredForSignature = gradeRequiredForSignature;
}

int     Form::getGradeRequiredForExecution( void )
{
    return (this->_gradeRequiredForExecution);
}

void Form::setGradeRequiredForExecution( int gradeRequiredForExecution )
{
    if (gradeRequiredForExecution > 150)
        throw Form::GradeTooLowException();
    else if (gradeRequiredForExecution < 1)
        throw Form::GradeTooHighException();
    else
        this->_gradeRequiredForExecution = gradeRequiredForExecution;
}

const char *Form::GradeTooHighException::what( void ) const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
    return ("Grade is too Low");
}

std::ostream &operator<<( std::ostream &o, Form *a )
{
    o << "Form " << a->getName() << " :" << std::endl <<
         "Grade required for signature : " << a->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << a->getGradeRequiredForExecution() << std::endl <<
         "Status : " << a->getIsSigned() << std::endl;
    return (o);
}