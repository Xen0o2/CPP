/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:49:59 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 19:56:50 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const &copy);
		FragTrap	&operator=( FragTrap const &rhs );
		virtual ~FragTrap( void );

		void	highFiveGuys( void );
};


#endif
