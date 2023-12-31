/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 *****************************************************************************/

/*****************************************************************************
 
  pic.cpp -- Programmable Interrupt Unit.
 
  Original Author: Martin Wang, Synopsys, Inc.
 
 *****************************************************************************/
 
/*****************************************************************************
 
  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.
 
      Name, Affiliation, Date:
  Description of Modification:
 
 *****************************************************************************/

#include "pic.h"

void pic::entry(){

	if (ireq0.read() == true) {
		intreq.write(true);
		vectno.write(0);
	} else if (ireq1.read() == true) {
			intreq.write(true);
			vectno.write(1);
		} else if (ireq2.read() == true) {
				intreq.write(true);
				vectno.write(2);
			} else if (ireq3.read() == true) {
						intreq.write(true);
						vectno.write(2);
				} else {
				} 
	if ((intack_cpu.read() == true) && (cs.read() == true)) {
			intreq.write(false);
	}
  }

// EOF

