/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:30:53 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/25 16:17:30 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(void)
{
	printf("\n");
	printf("  **********************************************************\n");
	printf("  ********************** FRACTAL TYPE **********************\n");
	printf("  **                                                      **\n");
	printf("  ** Please choose your fractal by passing as a parameter **\n");
	printf("  **                                                      **\n");
	printf("  ** --> M for Mandelbrot set                             **\n");
	printf("  ** --> J for Julia set                                  **\n");
	printf("  ** --> B for Burning Ship                               **\n");
	printf("  ** --> S for Serpienski's Carpet                        **\n");
	printf("  ** --> C to read available commands                     **\n");
	printf("  **                                                      **\n");
	printf("  **********************************************************\n");
	printf("  **********************************************************\n");
	printf("\n");
}

void	print_commands(void)
{
	printf("\n");
	printf("  **********************************************************\n");
	printf("  ************************ COMMANDS ************************\n");
	printf("  **                                                      **\n");
	printf("  **                || To Change Colors ||                **\n");
	printf("  **                                                      **\n");
	printf("  **       --> Use '1' to '4' keys on keyboard <--        **\n");
	printf("  **                                                      **\n");
	printf("  **                    || To Zoom ||                     **\n");
	printf("  **                                                      **\n");
	printf("  **        --> Use 'O' and 'P' or mouse wheel <--        **\n");
	printf("  **                                                      **\n");
	printf("  **                 || To Move Around ||                 **\n");
	printf("  **                                                      **\n");
	printf("  **   --> Use the arrow keys (not available for S) <--   **\n");
	printf("  **     --> Click to center (not available for S) <--    **\n");
	printf("  **                                                      **\n");
	print_commands2();
}

void	print_commands2(void)
{
	printf("  **             || To Change Resolution ||               **\n");
	printf("  **                                                      **\n");
	printf("  **              --> Use 'R' and 'T' <--                 **\n");
	printf("  **                                                      **\n");
	printf("  **                 || For Julia Set ||                  **\n");
	printf("  **                                                      **\n");
	printf("  **      --> Press 'C' to on/off changes for c <--       **\n");
	printf("  ** --> Use mouse position to change the value of c <--  **\n");
	printf("  **                                                      **\n");
	printf("  **             || Reset All Parameters ||               **\n");
	printf("  **                                                      **\n");
	printf("  **             --> Use the space bar <--                **\n");
	printf("  **                                                      **\n");
	printf("  **********************************************************\n");
	printf("  **********************************************************\n");
	printf("\n");
}

void	print_error_ptr(void)
{
	printf("Failure to generate pointers with mlx");
}
