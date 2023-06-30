/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:59:04 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/30 17:17:50 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool	_isSigned;
        int		_gradeRequiredForSignature;
		int		_gradeRequiredForExecution;
    public:
        Form( void );
        Form( std::string name );
        Form( Form const &copy );
        Form( &operator=( Form const & rhs ));
        ~Form( void );

		std::string getName( void );
		std::string	getIsSigned( void );
		bool	getIsSignedBool( void );
		void	beSigned( Bureaucrat &bureaucrat );
		int		getGradeRequiredForSignature( void );
		void	setGradeRequiredForSignature( int gradeRequiredForSignature );
		int		getGradeRequiredForExecution( void );
		void	setGradeRequiredForExecution( int gradeRequiredForExecution );
		
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Form *a);