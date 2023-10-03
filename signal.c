/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:14:03 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/13 20:14:04 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_exit_code = 1;
	}
	else if (signal == SIGQUIT)
		return ;
}

void	signal_handler2(int signal)
{
	if (signal == SIGINT)
	{
		g_exit_code = 130;
		printf("\n");
	}
}

void	set_signal_handler(int flag)
{
	if (!flag)
		signal(SIGINT, signal_handler);
	else
		signal(SIGINT, signal_handler2);
	signal(SIGQUIT, SIG_IGN);
}

void	hd_sig(int signum)
{
	exit(1);
}

void	set_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
