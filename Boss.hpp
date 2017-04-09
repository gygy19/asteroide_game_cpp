/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 09:49:31 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/09 09:49:32 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_CLASS_HPP
# define BOSS_CLASS_HPP

#include <iostream>
#include <string>
#include <curses.h>

#include "AEntity.hpp"

class Boss : public AEntity {

public:
	Boss(int team, int type, int x, int y, int color);
	~Boss();

							Boss(Boss const &rhs);
	Boss					&operator=(Boss const &rhs);
	void					explode(void);
};

#endif
