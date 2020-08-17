/* Copyright (C) 
* 2020 - B Vamsi Krishna <krishna.bv@gmail.com>
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
* 
*/

#ifndef __PROTO_H_
#define __PROTO_H_

#include <stdio.h>
#include <stdlib.h>


typedef enum __opcode_ {
    GET = 0;
    SET = 1;
    UNDEFINED = -1;
}opcode;

typedef enum __type_ {
    INT  = 0;
    CHAR = 1;
    STR  = 2;
    UNDEFINED = -1;
}type;

typedef struct __message_format_ {
    uint8_t SOF;
    opcode opc;
    type typ;
    uint8_t len;
    uint8_t *val;
    uint16_t chksum;
}msg_fmt;




#endif

