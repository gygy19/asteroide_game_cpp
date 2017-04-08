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

Spaceship::Spaceship() : {
	
}

Spaceship::~Spaceship() {
 }

Spaceship::Spaceship( Spaceship const& src) {
	
	*this = src;
	return;
}

Spaceship& Spaceship::operator=(Spaceship const & rhs) {

	

	return *this;
}