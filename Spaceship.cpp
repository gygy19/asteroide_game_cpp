/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spaceship.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:28:28 by gjensen           #+#    #+#             */
/*   Updated: 2017/04/08 17:28:29 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Spaceship.hpp"

Spaceship::Spaceship(int x, int y) : AEntity(x, y, 5) {
	this->spawn();
}

Spaceship::~Spaceship() {
 }

Spaceship::Spaceship( Spaceship const& rhs) : AEntity(rhs) {

	*this = rhs;
	return;
}

Spaceship&	Spaceship::operator=(Spaceship const & rhs) {

	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

void		Spaceship::spawn(void) {
	mvprintw(this->y, this->x, FORM);
}


/*
left : 260
right : 261
up : 259
down : 258
*/
void		Spaceship::update(bool *keys) {

	if (keys[68])
		this->x--;
	if (keys[67])
		this->x++;
	if (keys[65])
		this->y--;
	if (keys[66])
		this->y++;
	mvprintw(0, 0, "left : %d\n", KEY_LEFT);
	mvprintw(1, 1, "right : %d\n", KEY_RIGHT);
	mvprintw(2, 2, "up : %d\n", KEY_UP);
	mvprintw(3, 3, "down : %d\n", KEY_DOWN);
	this->spawn();
}