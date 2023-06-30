/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:49:18 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/30 17:01:17 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new Form();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant");
		a->setGrade(145);
		Bureaucrat *b = new Bureaucrat("CEO");
		b->setGrade(1);
		Form *c = new Form("Rent Contract");
		c->setGradeRequiredForSignature(140);
		c->setGradeRequiredForExecution(100);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;

		// Assistant signs the Form
		try
		{
			// c->beSigned(*a);
			a->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the Form
		std::cout << c;
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << c;

		// try signing the from again
		b->signForm(*c);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Form *a = NULL;

		// sign-grade too high
		try
		{
			a = new Form();
			a->setGradeRequiredForSignature(160);
			a->setGradeRequiredForExecution(145);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too high
		try
		{
			a = new Form();
			a->setGradeRequiredForSignature(145);
			a->setGradeRequiredForExecution(160);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		// sign-grade too low
		try
		{
			a = new Form();
			a->setGradeRequiredForSignature(-15);
			a->setGradeRequiredForExecution(145);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too low
		try
		{
			a = new Form();
			a->setGradeRequiredForSignature(145);
			a->setGradeRequiredForExecution(-15);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		// Deconstruction to prevent unused variable, in this case will never be called
		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	return (0);
}