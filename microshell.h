/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:51:51 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/23 02:35:13 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>

// messages:
# define ERR_FATAL "error: fatal\n"
# define ERR_EXECVE "error: cannot execute "
# define ERR_CD_ARG "error: cd: bad arguments\n"
# define ERR_CD_FAIL "error: cd: cannot change directory to "

#endif
