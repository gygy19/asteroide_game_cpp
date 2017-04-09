/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 03:48:37 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/09 03:48:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int type, int x, int y, int color) : AEntity(type, x, y, "<_._>", 1, color) {
	return ;
}

Enemy::~Enemy() {
 }

Enemy::Enemy( Enemy const& rhs) : AEntity(rhs) {

	*this = rhs;
	return;
}

Enemy&	Enemy::operator=(Enemy const & rhs) {

	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}
