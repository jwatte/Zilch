/*
 ||
 || @file 		zilch.cpp
 || @version 	0.2
 || @author 	Colin Duffy
 || @contact 	cmduffy@engr.psu.edu
 || @author 	Warren Gay
 || @contact 	ve3wwg@gmail.com
 ||
 || @description
 || Light weight task scheduler library, based off the awesome fibers
 || library by Warren Gay. https://github.com/ve3wwg/teensy3_fibers
 ||
 || @license
 || | Copyright (c) 2014 Colin Duffy, (C) Warren Gay VE3WWG
 || | This library is free software; you can redistribute it and/or
 || | modify it under the terms of the GNU Lesser General Public
 || | License as published by the Free Software Foundation; version
 || | 2.1 of the License.
 || |
 || | This library is distributed in the hope that it will be useful,
 || | but WITHOUT ANY WARRANTY; without even the implied warranty of
 || | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 || | Lesser General Public License for more details.
 || |
 || | You should have received a copy of the GNU Lesser General Public
 || | License along with this library; if not, write to the Free Software
 || | Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 || #
 ||
 */

#ifndef ZILCH_h
#define ZILCH_h
#ifdef __cplusplus

#include "Arduino.h"
#include "utility/task.h"

class Zilch {
private:
public:
    Zilch              ( uint16_t main_stack_size, const uint32_t pattern = 0xA5A5A5A5 ) ;
    TaskState create   ( task_func_t task, size_t stack_size, volatile void *arg ) ;
    TaskState pause    ( task_func_t task ) ;
    TaskState resume   ( task_func_t task ) ;
    TaskState restart  ( task_func_t task ) ;
    TaskState sync     ( task_func_t task ) ;
    TaskState state    ( task_func_t task ) ;
    TaskState state    ( loop_func_t task ) ;
    uint32_t* size     ( task_func_t task ) ;
    uint32_t* size     ( loop_func_t task ) ;
};
#endif
#endif
