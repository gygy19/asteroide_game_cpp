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

Spaceship::Spaceship(int team, int type, int x, int y, std::string symbol, int hit, int color) : AEntity(team, type, x, y, symbol, hit, color) {
	return ;
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

void			Spaceship::explode(void) {

}