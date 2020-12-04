/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:05:59 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:06:19 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mgl.h"

double	deg_to_rad(double degrees)
{
	return (degrees * M_PI / 180.0);
}

double	rad_to_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}
