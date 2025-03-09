/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibc_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:19:46 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 09:03:48 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBC_DEFINES_H
# define MYLIBC_DEFINES_H

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 0.0 MACROS															*/
/*#####################################################################	*/

// GARBAGE COLLECTOR
# ifndef MAX_ALLOCATIONS
#  define MAX_ALLOCATIONS 10240
# endif

# include "mylibc.h"

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 0.0 MACROS															*/
/*#####################################################################	*/
// GET NEXT LINE2
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

// Unsigned Int
# ifndef SIZE_MAX
#  define SIZE_MAX INT_MAX
# endif

# ifndef NAME_M
#  define NAME_M "log/2.Memory_Check/allocs/malloc_allocs.txt"
# endif

#endif