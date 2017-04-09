/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectil.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 01:16:48 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/09 01:16:50 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIL_CLASS_HPP
# define PROJECTIL_CLASS_HPP

#include <iostream>
#include <string>
#include <curses.h>

#include "AEntity.hpp"

class Projectil : public AEntity {

public:
	Projectil(int team, int type, int x, int y, int color);
	~Projectil();

							Projectil(Projectil const &rhs);
	Projectil				&operator=(Projectil const &rhs);
	void					explode(void);
};

#endif
