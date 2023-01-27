/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:14:37 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/27 18:23:27 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BSP_H__
# define __BSP_H__

# include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* __BSP_H__ */


