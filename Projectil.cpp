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

Projectil::Projectil(int team, int type, int x, int y, int range, int color) : AEntity(team, type, x, y, "|", 1, color) {
	this->_range = range;
	return ;
}

Projectil::~Projectil() {
	return ;
}

Projectil::Projectil(Projectil const& rhs) : AEntity(rhs) {
	
	*this = rhs;
	return;
}

Projectil		&Projectil::operator=(Projectil const & rhs) {
	this->x = rhs.x;
	this->y = rhs.y;
	this->_range = rhs._range;
	return *this;
}

int				Projectil::getRange(void) {
	return (this->_range);
}

void			Projectil::explode(void) {
	attron(COLOR_PAIR(this->type));
	mvprintw(this->y, this->x, "-");
	mvprintw(this->y, this->x + this->getWidth(), "-");
	mvprintw(this->y - 1, this->x + (this->getWidth() / 2), "|");
	mvprintw(this->y + 1, this->x + (this->getWidth() / 2), "|");
	attroff(COLOR_PAIR(this->type));
}