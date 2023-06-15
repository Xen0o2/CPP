/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:49:18 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/15 21:30:36 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	Bureaucrat *Dustin = new Bureaucrat("Dustin");
	std::cout << Dustin << std::endl;


	Dustin->decreaseGrade();
	std::cout << Dustin << std::endl;
	
	Dustin->increaseGrade();
	std::cout << Dustin << std::endl;

	try
	{
		Dustin->setGrade(0);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Dustin->setGrade(151);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete Dustin;

	return (0);
}
