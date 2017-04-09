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

AEntity::AEntity(int type, int x, int y, std::string symbol, int hit_max, int color) {

	this->type		= type;
	this->x			= x;
	this->y			= y;
	this->hit_max	= hit_max;
	this->hit		= this->hit_max;
	this->symbol	= symbol;
	this->color		= color;
	init_pair(this->type, this->color, COLOR_BLACK);
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

int				AEntity::getType(void) {
	return (this->type);
}

int				AEntity::getX(void) {
	return (this->x);
}

int				AEntity::getY(void) {
	return (this->y);
}

int				AEntity::getWidth(void) {
	return (strlen(symbol.c_str()));
}

int				AEntity::getHitPoint(void) {
	return (this->hit);
}

void			AEntity::takeDamage(int damage) {
	this->hit -= damage;
}

void			AEntity::update(void) {
	attron(COLOR_PAIR(this->type));
	mvprintw(this->y, this->x, this->symbol.c_str());
	attroff(COLOR_PAIR(this->type));
}

void			AEntity::move(int x, int y) {
	this->x += x;
	this->y += y;
}