/*
 * $Id: datalink.h 3708 2009-07-15 14:39:59Z poine $
 *  
 * Copyright (C) 2005  Pascal Brisset, Antoine Drouin
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
 */
/** \file datalink.h
 *  \brief Handling of messages coming from ground and other A/Cs
 *
 */

#ifndef DATALINK_H
#define DATALINK_H

#ifdef DATALINK_C
#define EXTERN
#else
#define EXTERN extern
#endif

#include "std.h"
#include "dl_protocol.h"

/** Datalink kinds */
#define PPRZ 1
#define XBEE 2

EXTERN bool_t dl_msg_available;
/** Flag provided to control calls to ::dl_parse_msg. NOT used in this module*/

EXTERN uint16_t datalink_time;

#define MSG_SIZE 128
EXTERN uint8_t dl_buffer[MSG_SIZE]  __attribute__ ((aligned));

EXTERN void dl_parse_msg(void);
/** Should be called when chars are available in dl_buffer */

#if DATALINK == PPRZ

#define DatalinkEvent() {			\
  if (PprzBuffer()) {				\
    ReadPprzBuffer();				\
    if (pprz_msg_received) {			\
      pprz_parse_payload();			\
      pprz_msg_received = FALSE;		\
    }						\
  }						\
  if (dl_msg_available) {			\
    dl_parse_msg();				\
    dl_msg_available = FALSE;			\
  }						\
}

#elif DATALINK == XBEE

#define DatalinkEvent() {			\
  if (XbeeBuffer()) {				\
    ReadXbeeBuffer();				\
    if (xbee_msg_received) {			\
      xbee_parse_payload();			\
      xbee_msg_received = FALSE;		\
    }						\
  }						\
  if (dl_msg_available) {			\
    dl_parse_msg();				\
    dl_msg_available = FALSE;			\
  }						\
}

#else

// Unknown DATALINK
#define DatalinkEvent() {}

#endif /* DATALINK == */

#endif /* DATALINK_H */
