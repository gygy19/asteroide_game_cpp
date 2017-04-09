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

	t_projectil *projectil = this->projectil;

	while (projectil != NULL)
	{
		projectil->projectil->update();
		projectil = projectil->right;
	}
}

void		Spaceship::shoot(bool *keys) {
	if (keys[32] == false)
		return ;
	Projectil *projectil = new Projectil(this->x + 2, this->y - 1, 1);
	this->addProjectil(projectil);
}

/*
left : 260
right : 261
up : 259
down : 258
*/
void		Spaceship::update(bool *keys) {

	if (keys[KEY_LEFT])
		this->x--;
	if (keys[KEY_RIGHT])
		this->x++;
	if (keys[KEY_UP])
		this->y--;
	if (keys[KEY_DOWN])
		this->y++;
	this->shoot(keys);
	this->spawn();
}