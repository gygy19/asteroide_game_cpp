/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectil.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 01:16:48 by jguyet            #+#    #+#             */
/*   Updated: 2017/04/09 01:16:50 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIL_CLASS_HPP
# define PROJECTIL_CLASS_HPP

#include <iostream>
#include <curses.h>

#define FORM_PROJECTIL "|"

class Projectil {

private:
	int						x;
	int						y;
	int						dir;

public:
	Projectil(int x, int y, int dir);
	~Projectil();

							Projectil(Projectil const &rhs);
	Projectil				&operator=(Projectil const &rhs);

	bool					update(void);
	void					spawn(void);
};

#endif
