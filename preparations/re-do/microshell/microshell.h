/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 04:14:08 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/27 05:05:10 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <stdlib.h>

// messages:
# define ERR_FATAL "error: fatal\n"
# define ERR_EXECVE "error: cannot execute "
# define ERR_CD_ARG "error: cd: bad arguments\n"
# define ERR_CD_FAIL "error: cd: cannot change directory to "

#endif
