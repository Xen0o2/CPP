/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:45:45 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/12 19:08:19 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class	PhoneBook
{
	public:

		PhoneBook ( void );
		~PhoneBook ( void );

		int		add ( void );
		void	search (void);
	
	private:
		Contact	_contact[8];
		int		_contactCount;
		void	_display( void );
};

#endif
