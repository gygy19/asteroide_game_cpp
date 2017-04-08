/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spaceship.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:28:23 by gjensen           #+#    #+#             */
/*   Updated: 2017/04/08 17:28:25 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPACESHIP_CLASS_H
# define SPACESHIP_CLASS_H

#include <iostream>
#include <curses.h>

class Spaceship : public GameEntity {

public:
	Spaceship();
	~Spaceship(void);

	Spaceship(Spaceship const& src);
	Spaceship& 	operator=(Spaceship const & rhs);

};


#endif