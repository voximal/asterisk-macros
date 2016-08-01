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
 * Purpose : Macros to support asterisk <= 1.6
 */

#ifndef __VERSION_MACROS_AST_1_6__
#define __VERSION_MACROS_AST_1_6__

#warning
#warning Loading macros for ASTERISK_VERSION_NUM <= 6
#warning

#define ast_set_read_format_by_id ast_set_read_format

#define ast_set_write_format_by_id ast_set_write_format

#define GET_CHAN_DATASTORES(chan) &chan->datastores

#define GET_CHAN_FLAGS(chan) &chan->flags

#define GET_CHAN_SCHED(chan) chan->sched

#define SET_CHAN_DATA(chan, value) chan->data = value

#define GET_CHAN_WHENTOHANGUP(chan) &chan->whentohangup

#define GET_CHAN_NAME(chan) chan->name

#define GET_CHAN_LANGUAGE(chan) chan->language

#define SET_CHAN_PRIORITY(chan, value) chan->priority = value

#define GET_CHAN_PRIORITY(chan) chan->priority

#define GET_CHAN_CONTEXT(chan) chan->context

#define GET_CHAN_EXTEN(chan) chan->exten

#define GET_CHAN_UNIQUEID(chan) chan->uniqueid

#define SET_CHAN_APPL(chan, value) chan->appl = value

#define SET_CHAN_STREAM(chan, value) chan->stream = value

#define GET_CHAN_NATIVEFORMATS(chan) chan->nativeformats

#define SET_CHAN_NATIVEFORMATS(chan,newnativeformats) chan->nativeformats = newnativeformats

#define GET_CHAN_STATE(chan) chan->_state

#define GET_CHAN_HANGUPCAUSE(chan) chan->hangupcause

#define GET_CHAN_OLDWRITEFORMAT(chan) chan->oldwriteformat

#define GET_AST_REQUEST(pseudo, type, video, chan, data, reason, useRawWr)    \
    pseudo = ast_request2(type, video, chan, data, reason, useRawWr);

/*#define GET_AST_REQUEST(pseudo, type, formats, chan, data, reason) 	\
ast_log(LOG_DEBUG,"rawwriteformat %x\n", chan->rawwriteformat);\
	pseudo = ast_request(type, formats | chan->rawwriteformat, data, reason); 

#define GET_AST_REQUEST_FMTVIDEO(pseudo, type, chan, data, reason) 					\
           GET_AST_REQUEST(pseudo, type, AST_FORMAT_H263 | AST_FORMAT_H263_PLUS | AST_FORMAT_H264, chan, data, reason)
*/

#define AST_COPY_STRING_CDR(attribute)			\
	ast_copy_string(cdr->attribute, chan->cdr->attribute, sizeof(cdr->attribute));	

#define GET_CHAN_AMAFLAGS chan->amaflags	

#define GET_CHAN_CDR(chan) chan->cdr

#define SET_CHAN_CDR(attribute) \
	chan->cdr = attribute;

#define GET_CHAN_STREAM_FMT_EXTS chan->stream->fmt->exts	
	
#define GET_CHAN_STREAM(chan) chan->stream

#define GET_CHAN_VSTREAM(chan) chan->vstream

#define GET_CHAN_STREAM_FMT chan->stream->fmt

#define GET_CHAN_CDR_DSTCHANNEL chan->cdr->dstchannel

#define DECLARE_RFMT \
	int rfmt = 0;
	
// Rev34
// AST_FORMAT_COPY_FROM_CHAN_READFORMAT(&rfmt);
#define AST_FORMAT_COPY_FROM_CHAN_READFORMAT(dest)	\
	dest = chan->readformat;
	
// Rev64
// SET_FAST_FORMAT_WITH_NATIVE(AST_FORMAT_SLINEAR);
#define SET_FAST_FORMAT_WITH_NATIVE(fmt1) 							\
	fast->format = fmt1 | GET_CHAN_NATIVEFORMATS(chan);			
	
#define FROM_READFORMAT_TO_OLDREADFORMAT(chan) chan->readformat

#define GET_CHAN_DIALED_NUMBER_STR chan->dialed.number.str
	
#define STRNCPY_MACROEXTEN strncpy(chan->macroexten, "macroexten", AST_MAX_EXTENSION-1)

#define STRNCPY_MACROCONTEXT strncpy(chan->macrocontext, "macrocontext", AST_MAX_CONTEXT-1)

#define SET_CHAN_RAWWRITEFORMAT(chan, fmt1) \
	chan->rawwriteformat = fmt1;
	
#define ISOLATE_CHAN_NATIVEFORMATS_OR_CLEAN(fmt1)	SET_CHAN_NATIVEFORMATS(chan, GET_CHAN_NATIVEFORMATS(chan) & fmt1)
	
#define ISOLATE_CHAN_NATIVEFORMATS_AUDIO	SET_CHAN_NATIVEFORMATS(chan, GET_CHAN_NATIVEFORMATS(chan) & AST_FORMAT_AUDIO_MASK)
	
#define SET_CHAN_NATIVEFORMAT(chan, fmt1) \
	chan->nativeformats = fmt1;
	
#define ISOLATE_AUDIOFORMATS_AND_FORCE_VIDEOFORMAT(fmt1)	\
	chan->nativeformats = (GET_CHAN_NATIVEFORMATS(chan) & AST_FORMAT_AUDIO_MASK) | fmt1;
	
#define GET_CHAN_TECH_TYPE chan->tech->type

#define GET_CHAN_TECH_FUNC_CHANNEL_WRITE_NOARGS chan->tech->func_channel_write

#define GET_CHAN_TECH_FUNC_CHANNEL_WRITE  chan->tech->func_channel_write(chan, function, data, value)
	
#define GET_AST_PBX_OUTGOING_EXTEN_REV65(result) \
result = ast_pbx_outgoing_exten(tech, AST_FORMAT_SLINEAR | GET_CHAN_NATIVEFORMATS(chan), number, connecttimeout * 1000, application, setvalue, 1, &reason, sync, ctx->remote, NULL, NULL, NULL, &locked_channel);

#define GET_AST_PBX_OUTGOING_EXTEN_REV66(result) \
result = ast_pbx_outgoing_exten(tech, AST_FORMAT_SLINEAR | GET_CHAN_NATIVEFORMATS(chan), number, connecttimeout * 1000, "default", application, 1, &reason, sync, ctx->remote, NULL, NULL, NULL, &locked_channel)

#define ADD_FORMAT_TO_CHAN_NATIVEFORMATS(fmt1) \
	chan->nativeformats |= fmt1;

#define AST_COPY_STRING_TO_CHAN_CDR_ATT(attribute, newString) \
	ast_copy_string(chan->cdr->attribute, #newString, sizeof(chan->cdr->attribute));
	
#define AST_COPY_VAR_TO_CHAN_CDR_ATT(attribute, newString)	\
	ast_copy_string(chan->cdr->attribute, newString, sizeof(chan->cdr->attribute));
		 
#define GET_CHAN_CDR_ATT(attribute) chan->cdr->attribute

#define AST_FORMAT_CAP_ALLOC_NOLOCK ast_format_cap_alloc()
	
#define AST_DEFAULT_AMAFLAGS ast_default_amaflags

#define SET_CDR_USERFIELD(chan,field) ast_cdr_setuserfield(chan, field)

#define SET_ACCOUNT_CODE(chan, code)  ast_cdr_setaccount(chan, code)

#define TCPTLS_SESSION_ADDRESS(remote_address, tmp_address) tmp_address = (int) remote_address.sin_addr.s_addr

#define TCPTLS_LOCK(tcptls_session)	ast_mutex_lock(&tcptls_session->lock)

#define TCPTLS_UNLOCK(tcptls_session)	ast_mutex_unlock(&tcptls_session->lock)

#define GET_CHAN_TECH_PVT(chan) chan->tech_pvt

#define SET_CHAN_READFORMAT(chan, fmt1) ast_set_read_format(chan, fmt1)

#define SET_CHAN_WRITEFORMAT(chan, fmt1) ast_set_write_format(chan, fmt1)

#define GET_CHAN_CALLERID_NUMBER(chan)	chan->cid.cid_num

#define INITIALIZE_SCHED static struct ast_sched_thread *sched

#define DELETE_SCHED_ENTRY(sched, id) 	\
        struct sched_context *__tmp_context = ast_sched_thread_get_context(sched); \
		ast_sched_del(sched,id);
		
#define DELETE_SCHED(sched, id) ast_sched_thread_del(sched, id)

#define AST_SCHED_ADD(context, when, callback, data) ast_sched_thread_add(context, when, callback, data)

#define SET_FRAME_SUBCLASS_FORMAT(frame, fmt1)	frame->subclass = fmt1;

#define SET_FRAME_SUBCLASS_FORMAT_AND_VIDEOMARK(frame, fmt1)	frame->subclass = fmt1 | 1

#define GET_CHAN_CALLERID_NAME(chan)	chan->cid.cid_name

#define SET_CHAN_TECH(chan,value) chan->tech = value

#define SET_CHAN_TECH_PVT(chan, value) chan->tech_pvt = value
	
#define FRAME_SUBCLASS_FORMAT_CLEAR(frame) frame->subclass = 0

#define GET_FRAME_CONTROL_TYPE(frame) frame->subclass

#define GET_FRAME_SUBCLASS_FORMAT(frame)	frame->subclass

#define GET_FRAME_SUBCLASS_FORMAT_ID(frame)	frame->subclass

#define	ALLOCATE_CHANNEL(needqueue, state, cid_num, cid_name, acctcode, exten, context, linkedid, amaflag, param1, param2) ast_channel_alloc(needqueue, state, cid_num, cid_name, acctcode, exten, context, amaflag, param1, param2)

#define SET_CHAN_NATIVEFORMATS2_ASTFORMAT_AND_IDFORMAT(chan, fmt1, fmt2)	chan->nativeformats = fmt1  | fmt2
	
#define SET_CHAN_NATIVEFORMATS1(chan, fmt1)	chan->nativeformats = fmt1

#define GET_CHAN_NATIVEFORMATS_BITFIELD(chan) chan->nativeformats

#define SET_CHAN_RINGS(chan, value) chan->rings =  value

#define SET_CHAN_ADSICPE(chan, value) chan->adsicpe = value

#define SET_CHAN_CALLERID_NUMBER(chan, value)	chan->cid.cid_num = value

#define SET_CHAN_CALLERID_ANI(chan, value)	chan->cid.cid_ani = value

#define COMPARE_VARFORMAT_IDFORMAT(fmt1, fmt2) fmt1 & fmt2

#define SET_CHAN_CALLERID_DNID(chan, value) chan->cid.cid_dnid = value

#define SET_CHAN_CONTEXT(chan, value) ast_copy_string(chan->context, value, sizeof(chan->context))

#define SET_CHAN_EXTEN(chan, value) ast_copy_string(chan->exten, value, sizeof(chan->exten))

#define SET_CHAN_LANGUAGE_RETURN_BOOL(chan, value) ast_string_field_set(chan, language, value)

#define SET_CHAN_HANGUPCAUSE(chan, value) chan->hangupcause = value

#define TEST_FLAG(object, flag) ast_test_flag(object,flag)

#define TCPTLS_SESSION_PORT(address) ntohs(address.sin_port)

#define FORMAT_CAP_AS_BITFIELD(format_cap) format_cap

#define INITIALIZE_CLIENT_AUDIOCODEC int audiocodec

#define FORMAT_FORCE_TO_OLD_BITFIELD(fmt1)	fmt1

#define FORMAT_FORCE_FROM_OLD_BITFIELD(fmt1, format)	fmt1=format

#define FORMAT_CLEAR(fmt1) fmt1 = 0

#define GET_FORMAT_NAME_MULTIPLE(string, size, fmt1) ast_getformatname_multiple(string, size, fmt1)

#define COPY_FORMAT_CAP(dst, src) dst = src

#define CLEAR_CAP_AND_SET_FORMAT(cap, fmt1) cap &= fmt1

#define CHECK_CAP_EMPTY(cap) cap == 0

#define CHECK_FRAME_SUBCLASS_VIDEOMARK(frame) (frame->subclass & 1)

#define SET_FORMAT_FROMID_TOVAR(dest, orig)	dest = orig

#define TCPTLS_SESSION_ADDRESS_FORCE_SOCKADDR_IN(remote_address, addr_in)	addr_in = &remote_address

#define GET_CHAN_TECH(chan) chan->tech

#define ALLOCATE_CAPABILITIES(rtmp_tech) ;

#define ADD_CAPABILITIES5(cap, fmt1, fmt2, fmt3, fmt4, fmt5) cap |= fmt1 | fmt2 | fmt3 | fmt4 | fmt5

#define ADD_CAPABILITIES4(cap, fmt1, fmt2, fmt3, fmt4) cap |= fmt1 | fmt2 | fmt3 | fmt4

#define ADD_CAPABILITIES2(cap, fmt1, fmt2) cap |= fmt1 | fmt2

#define ADD_CAPABILITIES1(cap, fmt1) cap |= fmt1

#define SCHED_CREATE ast_sched_thread_create()

#define AST_MANAGER_REGISTER2(action,auth,func,module,synopsis,description) ast_manager_register2(action,auth,func,synopsis,description)

#define TCPTLS_SESSION_FAMILY(socket_storage) socket_storage.sin_family		

#define SET_TCPTLS_SESSION_FAMILY(sock_address, family) sock_address.sin_family = family		

#define SET_TCPTLS_SESSION_PORT(sock_address, port) sock_address.sin_port = htons(port)

#define SET_ADDRESS_LENGTH(address) ;

#define GET_CHAN_FDNO(chan) chan->fdno

#define SCHED_DESTROY(sched) ast_sched_thread_destroy(sched)

#define SET_FRAME_SUBCLASS_INTEGER(frame, value) frame->subclass = value

#define FORMAT_VAR_TO_ID(fmt1) fmt1

#define GET_FORMAT_NAME(fmt1)	ast_getformatname(fmt1)

#define COMPARE_VARFORMAT_VARFORMAT(fmt1, fmt2) fmt1 & fmt2

#define INITIALIZE_OLDFORMAT int oldformat

#define CALL__RMPT_SHOW_USERS __rtmp_show_users(0, a->fd, a->argc, a->argv)


#endif // __VERSION_MACROS_AST_1_6__
