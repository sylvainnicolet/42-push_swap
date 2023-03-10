/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:00:46 by synicole          #+#    #+#             */
/*   Updated: 2022/12/23 14:00:48 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Push all element in stack_a to the stack_b,
 * until three elements are left in stack_a.
 *
 * 1. Push the first two elements to stack_b
 * 2. Push the rest until 3 elements are left in stack_a
 * 	  While pushing, we sort the stack_b.
 * 3. Sort the last 3 elements in stack_a
 *
 * Stack_a & stack_b must be sorted
 *
 * @param t_stack **stack_a
 * @param t_stack **stack_b
 * @return void
*/
void	ft_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_push_b(stack_a, stack_b, 1);
	if (ft_stack_size(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_push_b(stack_a, stack_b, 1);
	if (ft_stack_size(*stack_a) > 3 && !ft_check_sorted(*stack_a))
		ft_sort_b_until_3(stack_a, stack_b);
	if (!ft_check_sorted(*stack_a))
		ft_sort_last_three(stack_a);
}

/**
 * Push elements to stack_b until 3 elements are left in stack_a
 * While pushing, we sort the stack_b.
 *
 * 1. Get the best rotation
 * 2. Find the correct apply_method
 * 3. If we don't find the correct apply_method,
 * 	  Jump to the next element
 *
 *
 *
 * @param t_stack **stack_a
 * @param t_stack **stack_b
 * @return void
*/
void	ft_sort_b_until_3(t_stack **stack_a, t_stack **stack_b)
{
	int		rot;
	t_stack	*tmp;

	while (ft_stack_size(*stack_a) > 3 && !ft_check_sorted(*stack_a))
	{
		tmp = *stack_a;
		rot = ft_best_rotations_to_b(*stack_a, *stack_b);
		while (rot >= 0)
		{
			if (rot == ft_solver_b_rarb(*stack_a, *stack_b, tmp->nbr))
				rot = ft_apply_a_rarb(stack_a, stack_b, tmp->nbr);
			else if (rot == ft_solver_b_rrarrb(*stack_a, *stack_b, tmp->nbr))
				rot = ft_apply_a_rrarrb(stack_a, stack_b, tmp->nbr);
			else if (rot == ft_solver_b_rarrb(*stack_a, *stack_b, tmp->nbr))
				rot = ft_apply_a_rarrb(stack_a, stack_b, tmp->nbr);
			else if (rot == ft_solver_b_rrarb(*stack_a, *stack_b, tmp->nbr))
				rot = ft_apply_a_rrarb(stack_a, stack_b, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
}
