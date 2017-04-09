/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 09:49:38 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/09 09:49:39 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"

/*
 ######### 
##  ###  ##
##### #####
##  ###  ##
*/
Boss::Boss(int team, int type, int x, int y, int color) : \
AEntity(team, type, x, y, " ######### \n##  ###  ##\n##### #####\n##  ###  ##", 50, color) {
	return ;
}

Boss::~Boss() {
	return ;
}

Boss::Boss(Boss const& rhs) : AEntity(rhs) {
	
	*this = rhs;
	return;
}

Boss		&Boss::operator=(Boss const & rhs) {
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

void			Boss::explode(void) {
	return ;
}
