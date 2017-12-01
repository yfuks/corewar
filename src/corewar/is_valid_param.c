/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:15:29 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/29 18:38:26 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "tools.h"

t_op op_tab[17];

int  is_valid_param(int cmd_opcode, char encoding)
{
  int   i;
  char  tmp;

  if (!op_tab[cmd_opcode - 1].ocp)
    return (1);
  i = 0;
  while (i < op_tab[cmd_opcode - 1].nb_arg)
  {
      tmp = encoding >> (6 - (i * 2));
      /*
      **    >> permet de décaller en binaire
      **    01 11 10 00 devient (par exemple avec >> 2) 00 01 11 10
      */

      tmp = tmp & 0x3;
      /*
      **    & 0x3 est un masque binaire
      **    permet de garder que les deux dernier bits
      **    00 01 11 10 devient 00 00 00 10
      */
/*      if (op_tab[cmd_opcode - 1].args_types[i] == T_IND)
      {
        if(!(tmp & IND_CODE))
          return (0);
		  } 
      if (!(op_tab[cmd_opcode - 1].args_types[i] & tmp))
	  return (0);*/
	  if ((op_tab[cmd_opcode - 1].args_types[i] & T_IND) && (tmp == IND_CODE))
		  ;
	  else if ((op_tab[cmd_opcode - 1].args_types[i] & T_DIR) && (tmp == DIR_CODE))
		  ;
	  else if ((op_tab[cmd_opcode - 1].args_types[i] & T_REG) && (tmp == REG_CODE))
		  ;
	  else
	  return (0);
      i++;
  }
  return (1);
}
