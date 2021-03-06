(*
 * $Id: wind_sock.mli 1954 2007-10-26 07:51:43Z hecto $
 *
 * Wind sock
 *  
 * Copyright (C) 2007 ENAC
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA. 
 *
 *)

(** [item ?show size_unit group] Length of the wind sock is 6 times
    [size_unit] *)
class item : ?show:bool -> float -> #GnoCanvas.group ->
  object
    method item : GnoCanvas.group
    method label : GnoCanvas.text
    method set_color : string -> unit
  end
	    
