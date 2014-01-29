/* ScummVM - Scumm Interpreter
 * Copyright (C) 2005 The ScummVM project
 * Copyright (C) 2005 Joost Peters PSP Backend
 * Copyright (C) 2005 Thomas Mayer PSP Backend
 * Copyright (C) 2005 Paolo Costabel PSP Backend
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header: /cvsroot/scummvm/scummvm/backends/psp/trace.h,v 1.2 2005/09/03 19:50:08 fingolfin Exp $
 *
 */


#ifndef TRACE_H
#define TRACE_H

#include <stdio.h>
#include <psptypes.h>
#include <pspkernel.h>
#include <stdarg.h>
#include <pspdebug.h>

// #define exit(x) SDL_CloseAudio(); SDL_Quit(); sceGuTerm(); sceKernelExitGame();

void PSPDebugTrace (const char *format, ...);

#endif // TRACE_H

