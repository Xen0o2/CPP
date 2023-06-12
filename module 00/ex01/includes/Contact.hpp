/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:48:57 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/12 18:27:43 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class	Contact
{
	public:
		Contact ( void );
		~Contact ( void );
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

		void	display(int index);
		void	showInformation( void );
};

#endif
