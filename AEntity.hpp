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
#include <curses.h>

class AEntity {

protected:
	int			x;
	int			y;
	int			hit_max;
	int			hit;

public:
	AEntity(int x, int y, int hit_max);
	~AEntity(void);

						AEntity(AEntity const& rhs);
	AEntity& 			operator=(AEntity const & rhs);

	virtual void		spawn(void);

};


#endif
