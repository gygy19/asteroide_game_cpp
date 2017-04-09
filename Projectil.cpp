/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectil.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 01:16:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/09 01:16:58 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectil.hpp"

Projectil::Projectil(int x, int y, int dir) {

	this->x			= x;
	this->y			= y;
	this->dir		= dir;
	this->spawn();
}

Projectil::~Projectil() {
	return ;
}

Projectil::Projectil(Projectil const& rhs) {
	
	*this = rhs;
	return;
}

Projectil		&Projectil::operator=(Projectil const & rhs) {
	(void)rhs;
	return *this;
}

void			Projectil::spawn(void)
{
	mvprintw(this->y, this->x, FORM_PROJECTIL);
}

bool			Projectil::update(void)
{
	if (this->dir == -1)
		this->y++;
	if (this->dir == 1)
		this->y--;
	mvprintw(0, 0, "x: %d, y: %d", this->x, this->y);
	this->spawn();
	return (false);
}
