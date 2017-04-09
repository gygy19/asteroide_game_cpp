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

#include "AEntity.hpp"

#define FORM "<~!~>"

class Spaceship : public AEntity {

public:
	Spaceship(int x, int y);
	~Spaceship(void);

				Spaceship(Spaceship const& rhs);
	Spaceship&	operator=(Spaceship const & rhs);
	void		spawn(void);
	void		update(bool *keys);
	void		shoot(bool *keys);
};


#endif