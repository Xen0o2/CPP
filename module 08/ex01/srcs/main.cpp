/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:22:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/08 09:34:53 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	int size = 10000;
	Span span = Span(size);

	for(int i = 0; i < size; i++)
		span.addNumber( rand() % size );
		//span.addNumber( i );
	
	try
	{
		span.addNumber( 100 );
	}
	catch( Span::VectorFullException &e )
	{
		std::cout << "Can't add more number because : " << e.what() << std::endl;
	}

	std::cout << "Shortest span is : " << span.shortestSpan() << std::endl;
	std::cout << "Longest span is : " << span.longestSpan() << std::endl;

	return (0);
}
