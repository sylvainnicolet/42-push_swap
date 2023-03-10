/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:29:10 by synicole          #+#    #+#             */
/*   Updated: 2022/11/29 20:29:14 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no element.
 *
 * @param t_stack **stack_a
 * @param int show
 *
 * @return void
*/
void	ft_swap_a(t_stack **stack_a, int show)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (show)
		write(1, "sa\n", 3);
}
