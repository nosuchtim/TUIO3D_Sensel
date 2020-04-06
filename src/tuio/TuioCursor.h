/*
 TUIO C++ Library - part of the reacTIVision project
 http://reactivision.sourceforge.net/
 
 Copyright (c) 2005-2009 Martin Kaltenbrunner <mkalten@iua.upf.edu>
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#pragma once

#include <math.h>
#include "TuioContainer.h"

namespace TUIO {
	
	/**
	 * The TuioCursor class encapsulates /tuio/2Dcur TUIO cursors.
	 *
	 * @author Martin Kaltenbrunner
	 * @version 1.4
	 */ 
	class TuioCursor: public TuioContainer {
		
	protected:
		/**
		 * The individual cursor ID number that is assigned to each TuioCursor.
		 */ 
		int cursor_id;
		TuioTime creation_time;
		
	public:
		/**
		 * This constructor takes the provided Session ID, Cursor ID, X and Y coordinate 
		 * and assigs these values to the newly created TuioCursor.
		 *
		 * @param	si	the Session ID  to assign
		 * @param	ci	the Cursor ID  to assign
		 * @param	xp	the X coordinate to assign
		 * @param	yp	the Y coordinate to assign
		 */
		TuioCursor (long si, int ci, float xp, float yp):TuioContainer(si,xp,yp) {
			cursor_id = ci;
			creation_time = TuioTime::getSystemTime();
		};
		
		/**
		 * This constructor takes the atttibutes of the provided TuioCursor 
		 * and assigs these values to the newly created TuioCursor.
		 *
		 * @param	tcur	the TuioCursor to assign
		 */
		TuioCursor (TuioCursor *tcur):TuioContainer(tcur) {
			cursor_id = tcur->getCursorID();
			creation_time = TuioTime::getSystemTime();
		};
		
		/**
		 * The destructor is doing nothing in particular. 
		 */
		~TuioCursor(){};
		
		/**
		 * Returns the Cursor ID of this TuioCursor.
		 * @return	the Cursor ID of this TuioCursor
		 */
		int getCursorID() {
			return cursor_id;
		};

		long getCreationTime() {
			return creation_time.getMilliSeconds();
		};
		
	};
};
