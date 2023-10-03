/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:15:11 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/13 20:15:12 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_redir(t_dlist *curr)
{
	if (curr->next->type == PIPE)
		return (put_syntaxerr_msg(curr->next->token));
	if (curr->next->type == LINE)
		return (put_syntaxerr_msg(curr->next->token));
	if (curr->next->type == BRACKET)
		return (put_syntaxerr_msg("("));
	if (curr->next->type == REDIR)
		return (put_syntaxerr_msg(curr->next->token));
	return (1);
}

int	check_pipe(t_dlist *curr)
{
	if (curr->next->type == PIPE)
		return (put_syntaxerr_msg(curr->next->token));
	if (curr->next->type == LINE)
		return (put_syntaxerr_msg(curr->next->token));
	return (1);
}

int	check_word(t_dlist *curr)
{
	if (curr->next->type == BRACKET)
		return (put_syntaxerr_msg("("));
	return (1);
}

int	check_line(t_dlist *curr)
{
	if (curr->next->type == PIPE)
		return (put_syntaxerr_msg(curr->next->token));
	if (curr->next->type == LINE)
		return (put_syntaxerr_msg(curr->next->token));
	return (1);
}

int	check_bracket(t_dlist *curr)
{
	if (curr->next->type == BRACKET)
		return (put_syntaxerr_msg("("));
	if (curr->next->type == WORD)
		return (put_syntaxerr_msg(curr->next->token));
	return (1);
}
