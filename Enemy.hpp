/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 03:48:43 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/09 03:48:44 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include <iostream>
#include <string>
#include <curses.h>

#include "AEntity.hpp"

class Enemy : public AEntity {

public:
	Enemy(int type, int x, int y, int color);
	~Enemy(void);

				Enemy(Enemy const& rhs);
	Enemy&	operator=(Enemy const & rhs);
};

#endif
