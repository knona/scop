/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_uniform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krambono <krambono@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:43:26 by krambono          #+#    #+#             */
/*   Updated: 2020/12/04 11:44:35 by krambono         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	get_uniform_location(GLuint program, const char *uniform_name,
	GLint *location)
{
	*location = glGetUniformLocation(program, uniform_name);
	if (*location == -1)
		return (error_0("Location %s cannot be found", uniform_name));
	return (1);
}

int	uniform_set_mat4x4(GLuint program, const char *uniform_name,
	const t_mat4x4 *mat)
{
	GLint location;

	if (!get_uniform_location(program, uniform_name, &location))
		return (0);
	glUniformMatrix4fv(location, 1, 0, (const float *)mat);
	return (1);
}

int	uniform_set_vec4(GLuint program, const char *uniform_name,
	const t_vec4 *vec)
{
	GLint location;

	if (!get_uniform_location(program, uniform_name, &location))
		return (0);
	glUniform4fv(location, 1, (const float *)vec);
	return (1);
}

int	uniform_set_1i(GLuint program, const char *uniform_name, int value)
{
	GLint location;

	if (!get_uniform_location(program, uniform_name, &location))
		return (0);
	glUniform1i(location, value);
	return (1);
}
