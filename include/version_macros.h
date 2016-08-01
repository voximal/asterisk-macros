/*
 * Asterisk -- An open source telephony toolkit.
 *
 * Copyright (C) 1999 - 2006, Digium, Inc.
 *
 * Mark Spencer <markster@digium.com>
 *
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 */

/*
 * Voximal -- A VoiceXML browser.
 *
 * Copyrigth (C) 2009 - 2016, Ulex Innovative Systems, SARL
 *
 * Authors:
 *   Borja SIXTO (borja.sixto@ulex.fr)
 *   Javier SIXTO (javier.sixto@ulex.fr)
 * See:
 *   https://www.voximal.com
 *   https://github.com/voximal
 *   https://www.ulex.fr
 *
 * Purpose : Macros to help asterisk porting
 */

#ifndef ASTERISK_VERSION_NUM

 #ifdef AST_MAX_UNIQUEID
  //#warning WARNING: DETECT AST_MAX_UNIQUEID
  #ifdef AST_FORMAT_ATTR_SIZE
   //#warning WARNING: DETECT AST_FORMAT_ATTR_SIZE
   #define ASTERISK_VERSION_NUM 120000
  #else
   #define ASTERISK_VERSION_NUM 130000
  #endif
 #endif

 #ifdef DEFAULT_PARKINGLOT
  //#warning WARNING: INCLUDING ast_version.h
  #include <asterisk/ast_version.h>
 #else
  #ifdef AST_JITTERBUFFER_FD
    //#warning WARNING: INCLUDING ast_version.h
    #include <asterisk/ast_version.h>
  #else
    //#warning WARNING: INCLUDING version.h
    #include <asterisk/version.h>
  #endif
 #endif

#endif

#define AST_4       10400
#define AST_6       10600
#define AST_6_1     10601
#define AST_8       10800
#define AST_10		  100000
#define AST_11		  110000
#define AST_12			120000
#define AST_13			130000
#define AST_99			990000

/* Forcing NUM Version ? */
#if ASTERISK_VERSION_NUM_FORCE
  #define ASTERISK_VERSION_NUM ASTERISK_VERSION_NUM_FORCE
  #warning "Compilation Force ASTERISK_VERSION_NUM"
#else
     /* Only videocaps are SVN normaly */
    #if ASTERISK_VERSION_NUM > AST_99
     #undef ASTERISK_VERSION_NUM
     #ifdef AST_FORMAT_SLINEAR16
      #define ASTERISK_VERSION_NUM 10602
     #else
      #define ASTERISK_VERSION_NUM 10499
     #endif
     #undef ASTERISK_VERSION
     #define ASTERISK_VERSION "VideoCaps"
     #warning
     #warning "Compilation for VideoCaps !"
     #warning
    #endif
#endif

#ifndef ASTERISK_VERSION_NUM
#define ASTERISK_VERSION_NUM AST_11
#endif

/* For Asterisk 1.4.x */
#if ASTERISK_VERSION_NUM < AST_6
 #warning
 #warning "Compilation for Asterisk 1.4 !"
 #warning

#elif ASTERISK_VERSION_NUM >= AST_6 && ASTERISK_VERSION_NUM < AST_8
/* For Asterisk 1.6.x */
 #warning
 #warning "Compilation for Asterisk 1.6 !"
 #warning

#elif ASTERISK_VERSION_NUM >= AST_8 && ASTERISK_VERSION_NUM < AST_10
/* For Asterisk 1.8.x */
 #warning
 #warning "Compilation for Asterisk 1.8 !"
 #warning

#elif ASTERISK_VERSION_NUM >= AST_10 && ASTERISK_VERSION_NUM < AST_11
/* For Asterisk 10 */
 #warning
 #warning "Compilation for Asterisk 10 !"
 #warning

#elif ASTERISK_VERSION_NUM >= AST_11 && ASTERISK_VERSION_NUM < AST_12
/* For Asterisk 11 */
 #warning
 #warning "Compilation for Asterisk 11 !"
 #warning

#elif ASTERISK_VERSION_NUM >= AST_12  && ASTERISK_VERSION_NUM < AST_13
/* For Asterisk 12 */
 #warning
 #warning "Compilation for Asterisk 12 !"
 #warning

#else
/* For Asterisk 13 */
 #warning
 #warning "Compilation for Asterisk >= 13 !"
 #warning
#endif

#if ASTERISK_VERSION_NUM < AST_8
/*** Macros in case of Asterisk version < 8  ***/
#include "version_macros_ast_1-6.h"

#elif ASTERISK_VERSION_NUM >= AST_8 && ASTERISK_VERSION_NUM < AST_11
/*** Macros in case of Asterisk version == 8 ***/
#include "version_macros_ast_1-8.h"

#elif ASTERISK_VERSION_NUM >= AST_11  && ASTERISK_VERSION_NUM < AST_12
/*** Macros in case of Asterisk version == 11 ***/
#include "version_macros_ast_11.h"

#elif ASTERISK_VERSION_NUM >= AST_12  && ASTERISK_VERSION_NUM < AST_13
/*** Macros in case of Asterisk version == 12 ***/
#include "version_macros_ast_12.h"

#else
/*** Macros in case of Asterisk version >= 13 ***/
#include "version_macros_ast_13.h"
	
#endif

