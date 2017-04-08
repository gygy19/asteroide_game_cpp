/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:21:51 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/08 19:21:53 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity(int x, int y, int hit_max) {

	this->x			= x;
	this->y			= y;
	this->hit_max	= hit_max;
	this->hit		= this->hit_max;
}

AEntity::~AEntity() {
 }

AEntity::AEntity(AEntity const& rhs) {
	
	*this = rhs;
	return;
}

AEntity&		AEntity::operator=(AEntity const & rhs) {

	this->x			= rhs.x;
	this->y			= rhs.y;
	this->hit_max	= rhs.hit_max;
	this->hit		= rhs.hit;
	return *this;
}

void			AEntity::spawn(void) {

}
