/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/03 18:07:00 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("ShrubberyCreationForm"), _target("default")
{ 
    this->_gradeRequiredForSignature = SHRUBERRY_SIGNATURE;
    this->_gradeRequiredForExecution = SHRUBERRY_EXECUTION;
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): Form("ShrubberyCreationForm"), _target(target)
{
    this->_gradeRequiredForSignature = SHRUBERRY_SIGNATURE;
    this->_gradeRequiredForExecution = SHRUBERRY_EXECUTION;
    std::cout << "ShrubberyCreationForm string constructor for target " << target << " called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &copy ): Form("ShrubberyCreationForm"), _target(copy._target)
{
    this->_gradeRequiredForSignature = copy._gradeRequiredForSignature;
    this->_gradeRequiredForExecution = copy._gradeRequiredForExecution;
    *this = copy;
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    return;
}

ShrubberyCreationForm    &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
    Form::operator=(rhs);
	this->_target = rhs._target;
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    std::cout << "ShrubberyCreationForm " << this->getName() << " destructor called" << std::endl;
    return;
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
    return (this->_target);
}

void    ShrubberyCreationForm::beExecuted( Bureaucrat const &executor ) const
{
    (void)executor;
    std::ofstream	outfile (this->_target + "_shrubbery");

    if (outfile.fail())
    {
        std::cout << "Could not open output file" << std::endl;
        return;
    }

    outfile <<
    "                                                         ." << std::endl <<
    "                                      .         ;" << std::endl <<
    "         .              .              ;%     ;;" << std::endl <<
    "          ,           ,                :;%  %;" << std::endl <<
    "			:         ;                   :;%;'     .," << std::endl <<
    "   ,.        %;     %;            ;        %;'    ,;" << std::endl <<
    "	 ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl <<
    "	  %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl <<
    "	   ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl <<
    "		`%;.     ;%;     %;'         `;%%;.%;'" << std::endl <<
    "		 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl <<
    "			`:%;.  :;bd%;          %;@%;'" << std::endl <<
    "			  `@%:.  :;%.         ;@@%;'" << std::endl <<
    "				`@%.  `;@%.      ;@@%;" << std::endl <<
    "				  `@%%. `@%%    ;@@%;" << std::endl <<
    "					;@%. :@%%  %@@%;" << std::endl <<
    "					  %@bd%%%bd%%:;" << std::endl <<
    "						#@%%%%%:;;" << std::endl <<
    "						%@@%%%::;" << std::endl <<
    "						%@@@%(o);  . '" << std::endl <<
    "						%@@@o%;:(.,'" << std::endl <<
    "					`.. %@@@o%::;" << std::endl <<
    "					   `)@@@o%::;" << std::endl <<
    "						%@@(o)::;" << std::endl <<
    "					   .%@@@@%::;" << std::endl <<
    "					   ;%@@@@%::;." << std::endl <<
    "					  ;%@@@@%%:;;;." << std::endl <<
    "				  ...;%@@@@@%%:;;;;,.."
    << std::endl;

    outfile.close();
}

std::ostream &operator<<( std::ostream &o, ShrubberyCreationForm *a )
{
    o << "ShrubberyCreationForm " << a->getName() << " :" << std::endl <<
         "Grade required for signature : " << a->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << a->getGradeRequiredForExecution() << std::endl <<
         "Status : " << a->getIsSigned() << std::endl;
    return (o);
}