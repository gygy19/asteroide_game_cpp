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
	this->projectil	= NULL;
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

void			AEntity::shoot(bool *keys) {
	(void)keys;
}

void			AEntity::addProjectil(Projectil *projectil)
{
	t_projectil *tmp;
	t_projectil *current = new t_projectil;

	current->projectil = projectil;
	current->right = NULL;
	current->left = NULL;
	tmp = this->projectil;
	if (tmp == NULL)
	{
		this->projectil = current;
		return ;
	}
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = current;
	current->left = tmp;
}


void			AEntity::removeProjectil(Projectil *projectil)
{
	t_projectil *tmp;

	tmp = this->projectil;
	while (tmp != NULL)
	{
		if (tmp->projectil == projectil)
		{
			if (tmp->left != NULL && tmp->right != NULL)
			{
				tmp->right->left = tmp->left;
				tmp->left->right = tmp->right;
			}
			else if (tmp->left != NULL)
			{
				tmp->left->right = NULL;
			}
			else if (tmp->right != NULL)
			{
				tmp->right->left = NULL;
			}
			if (this->projectil->projectil == projectil)
			{
				if (tmp->left != NULL)
					this->projectil = tmp->left;
				else
					this->projectil = NULL;
			}
			break ;
		}
		tmp = tmp->right;
	}
	delete tmp;
	delete projectil;
}