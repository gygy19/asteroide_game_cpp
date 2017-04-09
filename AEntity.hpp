/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:22:05 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/08 19:22:07 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_CLASS_H
# define AENTITY_CLASS_H

#include <iostream>
#include <string>
#include <curses.h>

class AEntity {

protected:
	int			x;
	int			y;
	int			hit_max;
	int			hit;
	int			type;
	std::string	symbol;
	int			color;
	int			team;

public:
						AEntity(int team, int type, int x, int y, std::string symbol, int hit_max, int color);
	virtual				~AEntity(void);

						AEntity(AEntity const& rhs);
	AEntity& 			operator=(AEntity const & rhs);

	void				update(void);
	void				move(int x, int y);
	int					getType(void);
	int					getTeam(void);
	int					getX(void);
	int					getY(void);
	int					getWidth(void);
	int					getHeight(void);
	int					getHitPoint(void);
	void				takeDamage(int damage);
	virtual void		explode(void) = 0;
};


#endif
