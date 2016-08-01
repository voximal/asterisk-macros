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
 * Voximal -- a VoiceXML browser.
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
 * Purpose : Macros to support asterisk 12
 */

#ifndef __VERSION_MACROS_AST_12__
#define __VERSION_MACROS_AST_12__

#warning
#warning Loading macros for ASTERISK_VERSION_NUM == 12
#warning
	

#define GET_CHAN_DATASTORES(chan) ast_channel_datastores(chan)

#define GET_CHAN_FLAGS(chan) ast_channel_flags(chan)

#define GET_CHAN_SCHED(chan) ast_channel_sched(chan)

#define SET_CHAN_DATA(chan, value) ast_channel_data_set(chan, value)

#define GET_CHAN_WHENTOHANGUP(chan) ast_channel_whentohangup(chan)

#define GET_CHAN_NAME(chan) ast_channel_name(chan)

#define GET_CHAN_LANGUAGE(chan) ast_channel_language(chan)

#define SET_CHAN_PRIORITY(chan,value) ast_channel_priority_set(chan,value)

#define GET_CHAN_PRIORITY(chan) ast_channel_priority(chan)

#define GET_CHAN_CONTEXT(chan) ast_channel_context(chan)

#define GET_CHAN_EXTEN(chan) ast_channel_exten(chan)

#define GET_CHAN_UNIQUEID(chan) ast_channel_uniqueid(chan)

#define SET_CHAN_APPL(chan, value) ast_channel_appl_set(chan,value)

#define SET_CHAN_STREAM(chan, value) ast_channel_stream_set(chan,value)

#define SET_CHAN_VSTREAM(chan, value) ast_channel_vstream_set(chan,value)

#define GET_CHAN_NATIVEFORMATS(chan) ast_channel_nativeformats(chan)

#define SET_CHAN_NATIVEFORMATS(chan,newnativeformats) ast_channel_nativeformats_set(chan, newnativeformats)

#define GET_CHAN_STATE(chan) ast_channel_state(chan)

#define GET_CHAN_HANGUPCAUSE(chan) ast_channel_hangupcause(chan)

#define GET_CHAN_OLDWRITEFORMAT(chan) ast_channel_oldwriteformat(chan)

#define GET_AST_REQUEST(pseudo, type, video, chan, data, reason, useRawWr)    \
    pseudo = ast_request2(type, video, chan, data, reason, useRawWr);
/*
#define GET_AST_REQUEST(pseudo, type, formats, chan, data, reason) 					\
  ast_log(LOG_DEBUG,"rawwriteformat %x\n", ast_channel_rawwriteformat(chan)->id);	\
	struct ast_format_cap *request_formats_cap;										\
	request_formats_cap = ast_format_cap_alloc(AST_FORMAT_CAP_FLAG_NOLOCK);			\
	if (!request_formats_cap) { 													\
        return -1; 																	\
    } 																				\
	struct ast_format request_format;												\
	ast_format_cap_add(request_formats_cap, ast_format_set(&request_format, AST_FORMAT_H263, 0));		\
  ast_format_cap_add(request_formats_cap, ast_format_set(&request_format, AST_FORMAT_H263_PLUS, 0));	\
  ast_format_cap_add(request_formats_cap, ast_format_set(&request_format, AST_FORMAT_H264, 0));		\
	ast_format_cap_add(request_formats_cap, ast_channel_rawwriteformat(chan));							\
	pseudo = ast_request(type, request_formats_cap, NULL, chan, data, reason);

#define GET_AST_REQUEST_FMTVIDEO(pseudo, type, chan, data, reason) 					\
           GET_AST_REQUEST(pseudo, type, AST_FORMAT_H263 | AST_FORMAT_H263_PLUS | AST_FORMAT_H264, chan, data, reason)
*/

#define AST_COPY_STRING_CDR(attribute)		{\
  ast_copy_string(cdr->attribute, ast_channel_cdr(chan)->attribute, sizeof(cdr->attribute));\
}  

#define GET_CHAN_AMAFLAGS ast_channel_amaflags(chan)

#define GET_CHAN_CDR(chan) ast_channel_cdr(chan)

#define SET_CHAN_CDR(attribute) \
	ast_channel_cdr_set(chan, attribute);

#define GET_CHAN_STREAM_FMT_EXTS ast_channel_stream(chan)->fmt->exts

#define GET_CHAN_STREAM(chan) ast_channel_stream(chan)

#define GET_CHAN_VSTREAM(chan) ast_channel_vstream(chan)

#define GET_CHAN_STREAM_FMT ast_channel_stream(chan)->fmt

#define GET_CHAN_CDR_DSTCHANNEL ast_channel_cdr(chan)->dstchannel

#define DECLARE_RFMT \
	struct ast_format rfmt;

#define AST_FORMAT_COPY_FROM_CHAN_READFORMAT(dest)	\
	ast_format_copy(ast_channel_readformat(chan), &dest);
	
#define SET_FAST_FORMAT_WITH_NATIVE(fmt1){ 							\
struct ast_format_cap *temp_cap = GET_CHAN_NATIVEFORMATS(chan);		\
struct ast_format temp_format;											\
ast_format_cap_add(temp_cap, ast_format_set(&temp_format, fmt1, 0));	\
fast->cap = temp_cap;													\
}

#define FROM_READFORMAT_TO_OLDREADFORMAT(chan) ast_format_to_old_bitfield(ast_channel_readformat(chan))

#define GET_CHAN_DIALED_NUMBER_STR ast_channel_dialed(chan)->number.str

#define STRNCPY_MACROEXTEN strncpy((char*)ast_channel_macroexten(chan), "macroexten", AST_MAX_EXTENSION-1)
#define STRNCPY_MACROCONTEXT strncpy((char*)ast_channel_macrocontext(chan), "macrocontext", AST_MAX_CONTEXT-1)

#define SET_CHAN_RAWWRITEFORMAT(chan, fmt1) 	{\
	struct ast_format temp_format;		\
	ast_format_copy(ast_channel_rawwriteformat(chan), ast_format_set(&temp_format, fmt1,0)); \
}

#define ISOLATE_CHAN_NATIVEFORMATS_OR_CLEAN(fmt1) \
	struct ast_format_cap *temp_cap = GET_CHAN_NATIVEFORMATS(chan);								\
	struct ast_format temp_format, *result;															\
	ast_format_set(&temp_format, fmt1, 0);															\
	if(ast_format_cap_get_compatible_format(GET_CHAN_NATIVEFORMATS(chan), &temp_format, result)) \
	{																								\
	ast_format_cap_set(GET_CHAN_NATIVEFORMATS(chan),&temp_format);								\
	SET_CHAN_NATIVEFORMATS(chan, GET_CHAN_NATIVEFORMATS(chan));							\
	}																								\
	else																							\
	{																								\
	ast_format_cap_remove_all(GET_CHAN_NATIVEFORMATS(chan));										\
	SET_CHAN_NATIVEFORMATS(chan, GET_CHAN_NATIVEFORMATS(chan));							\
	}
	
#define ISOLATE_CHAN_NATIVEFORMATS_AUDIO {\
	struct ast_format_cap *temp_cap = GET_CHAN_NATIVEFORMATS(chan);	\
	ast_format_cap_remove_bytype(temp_cap, AST_FORMAT_TYPE_VIDEO);		\
	ast_format_cap_remove_bytype(temp_cap, AST_FORMAT_TYPE_IMAGE); 		\
	ast_format_cap_remove_bytype(temp_cap, AST_FORMAT_TYPE_TEXT); 		\
	SET_CHAN_NATIVEFORMATS(chan, temp_cap);						\
}	

#define SET_CHAN_NATIVEFORMAT(chan, fmt1) {\
	struct ast_format temp_format;													\
	struct ast_format_cap *temp_cap;												\
	ast_format_cap_add(temp_cap, ast_format_set(&temp_format, fmt1,0));	\
	SET_CHAN_NATIVEFORMATS(chan, temp_cap);									\
}

#define ISOLATE_AUDIOFORMATS_AND_FORCE_VIDEOFORMAT(fmt1)	{\
	struct ast_format_cap *temp_cap = GET_CHAN_NATIVEFORMATS(chan);				\
	struct ast_format temp_format;													\
	ast_format_cap_remove_bytype(temp_cap, AST_FORMAT_TYPE_VIDEO); 					\
	ast_format_cap_remove_bytype(temp_cap, AST_FORMAT_TYPE_IMAGE); 					\
	ast_format_cap_remove_bytype(temp_cap, AST_FORMAT_TYPE_TEXT); 					\
	ast_format_cap_add(temp_cap, ast_format_set(&temp_format, fmt1, 0));	\
	SET_CHAN_NATIVEFORMATS(chan, temp_cap);									\
}

#define GET_CHAN_TECH_TYPE ast_channel_tech(chan)->type

#define GET_CHAN_TECH_FUNC_CHANNEL_WRITE_NOARGS ast_channel_tech(chan)->func_channel_write

#define GET_CHAN_TECH_FUNC_CHANNEL_WRITE  ast_channel_tech(chan)->func_channel_write(chan, function, data, value)

// added 0 as value of the argument "early_media"
#define GET_AST_PBX_OUTGOING_EXTEN_REV65(result) {\
	struct ast_format temp_format; \
	struct ast_format_cap *temp_cap = GET_CHAN_NATIVEFORMATS(chan); \
	ast_format_cap_add(temp_cap, ast_format_set(&temp_format, AST_FORMAT_SLINEAR, 0)); \
	result = ast_pbx_outgoing_exten(tech, temp_cap, number, connecttimeout * 1000, "default", application, 1, &reason, sync, ctx->remote, NULL, NULL, NULL, &locked_channel, 0, NULL); \
}

// added 0 as value of the argument "early_media"
#define GET_AST_PBX_OUTGOING_EXTEN_REV66(result) {\
struct ast_format temp_format;	\
struct ast_format_cap *temp_cap = GET_CHAN_NATIVEFORMATS(chan);	\
ast_format_cap_add(temp_cap, ast_format_set(&temp_format, AST_FORMAT_SLINEAR, 0));	\
result = ast_pbx_outgoing_exten(tech, temp_cap, number, connecttimeout * 1000, "default", application, 1, &reason, sync, ctx->remote, NULL, NULL, NULL, &locked_channel, 0, NULL);	\
}

#define ADD_FORMAT_TO_CHAN_NATIVEFORMATS(fmt1) 	{\
	struct ast_format_cap *temp_cap = GET_CHAN_NATIVEFORMATS(chan);				\
	struct ast_format temp_format;													\
	ast_format_cap_add(temp_cap, ast_format_set(&temp_format, fmt1, 0));	\
	SET_CHAN_NATIVEFORMATS(chan,temp_cap);									\
}
	
#define AST_COPY_STRING_TO_CHAN_CDR_ATT(attribute, newString)	\
	ast_copy_string(ast_channel_cdr(chan)->attribute, #newString, sizeof(ast_channel_cdr(chan)->attribute));
	
#define AST_COPY_VAR_TO_CHAN_CDR_ATT(attribute, newString)	\
	ast_copy_string(ast_channel_cdr(chan)->attribute, newString, sizeof(ast_channel_cdr(chan)->attribute));
		 
#define GET_CHAN_CDR_ATT(attribute) ast_channel_cdr(chan)->attribute

#define AST_FORMAT_CAP_ALLOC_NOLOCK ast_format_cap_alloc(AST_FORMAT_CAP_FLAG_NOLOCK)

#define AST_DEFAULT_AMAFLAGS AST_AMA_DOCUMENTATION	// #define DEFAULT_AMA_FLAGS AST_AMA_DOCUMENTATION
													// we can access AST_AMA_DOCUMENTATION but not DEFAULT_AMA_FLAGS

#define SET_CDR_USERFIELD(chan,field) ast_cdr_setuserfield(ast_channel_name(chan), field)

#define SET_ACCOUNT_CODE(chan, code)  ast_channel_accountcode_set(chan, code)

#define TCPTLS_SESSION_ADDRESS(remote_address, tmp_address)		\
	struct sockaddr_in address;						\
	ast_sockaddr_to_sin(&remote_address, &address);	\
	tmp_address = address.sin_addr.s_addr; 		

#define TCPTLS_LOCK(tcptls_session)	ao2_lock(tcptls_session)

#define TCPTLS_UNLOCK(tcptls_session)	ao2_unlock(tcptls_session)

#define GET_CHAN_TECH_PVT(chan)  ast_channel_tech_pvt(chan)

#define SET_CHAN_READFORMAT(chan, fmt1)	ast_set_read_format(chan, &fmt1); 	

#define SET_CHAN_WRITEFORMAT(chan, fmt1)	ast_set_write_format(chan, &fmt1); 	

#define GET_CHAN_CALLERID_NUMBER(chan)	ast_channel_caller(chan)->id.number.str ? ast_channel_caller(chan)->id.number.str : NULL	

#define INITIALIZE_SCHED static struct ast_sched_context *sched

#define DELETE_SCHED_ENTRY(sched, id) 	\
        struct sched_context *__tmp_context = ast_sched_thread_get_context(sched); \
		ast_sched_del(sched,id);

#define DELETE_SCHED(sched, id) AST_SCHED_DEL(sched, id)
		
#define AST_SCHED_ADD(context, when, callback, data) ast_sched_add(context, when, callback, data)

#define SET_FRAME_SUBCLASS_FORMAT(frame, fmt1)	ast_format_set(&frame->subclass.format, fmt1, 0);

#define SET_FRAME_SUBCLASS_FORMAT_AND_VIDEOMARK(frame, fmt1)		\
	ast_format_set(&frame->subclass.format, fmt1, 0);				\
	ast_format_set_video_mark(&frame->subclass.format);

#define GET_CHAN_CALLERID_NAME(chan)	ast_channel_caller(chan)->id.name.str

#define SET_CHAN_TECH(chan,value) ast_channel_tech_set(chan,value)

#define FRAME_SUBCLASS_FORMAT_CLEAR(frame) ast_format_clear(&frame->subclass.format)
	
#define GET_FRAME_CONTROL_TYPE(frame) frame->subclass.integer

#define GET_FRAME_SUBCLASS_FORMAT(frame)	frame->subclass.format

#define GET_FRAME_SUBCLASS_FORMAT_ID(frame)	frame->subclass.format.id

#define	ALLOCATE_CHANNEL(needqueue, state, cid_num, cid_name, acctcode, exten, context, linkedid, amaflag, param1, param2) ast_channel_alloc(needqueue, state, cid_num, cid_name, acctcode, exten, context, linkedid, amaflag, param1, param2)

#define SET_CHAN_NATIVEFORMATS2_ASTFORMAT_AND_IDFORMAT(chan, fmt1, fmt2)	\
	struct ast_format tmp_format;		\
	struct ast_format_cap *tmp_fmt_cap = ast_format_cap_alloc(AST_FORMAT_CAP_FLAG_NOLOCK);	\
    ast_format_cap_add(tmp_fmt_cap, &fmt1);	\
    ast_format_cap_add(tmp_fmt_cap, ast_format_set(&tmp_format, fmt2, 0));	\
	ast_channel_nativeformats_set(chan,tmp_fmt_cap);
	
#define SET_CHAN_NATIVEFORMATS1(chan, fmt1)	\
	struct ast_format_cap *tmp_fmt_cap = ast_format_cap_alloc(AST_FORMAT_CAP_FLAG_NOLOCK);	\
    ast_format_cap_add(tmp_fmt_cap, &fmt1);	\
	ast_channel_nativeformats_set(chan,tmp_fmt_cap)

#define GET_CHAN_NATIVEFORMATS_BITFIELD(chan) (unsigned int)ast_format_cap_to_old_bitfield(ast_channel_nativeformats(chan))

#define SET_CHAN_RINGS(chan, value) ast_channel_rings_set(chan, value)

#define SET_CHAN_ADSICPE(chan, value) ast_channel_adsicpe_set(chan, value)

#define SET_CHAN_TECH_PVT(chan, value) ast_channel_tech_pvt_set(chan, value)

#define SET_CHAN_CALLERID_NUMBER(chan, value)	\
	ast_channel_caller(chan)->id.number.valid = 1;	\
	ast_channel_caller(chan)->id.number.str = value;

#define SET_CHAN_CALLERID_ANI(chan, value) \
	ast_channel_caller(chan)->ani.number.valid = 1;	\
	ast_channel_caller(chan)->ani.number.str = value;
	
#define COMPARE_VARFORMAT_IDFORMAT(ast_fmt1, fmt2) ast_fmt1.id == fmt2

#define SET_CHAN_CALLERID_DNID(chan, value) ast_channel_dialed(chan)->number.str = value

#define SET_CHAN_CONTEXT(chan, value) ast_channel_context_set(chan,value)

#define SET_CHAN_EXTEN(chan, value) ast_channel_exten_set(chan,value)

#define SET_CHAN_LANGUAGE_RETURN_BOOL(chan, value) ast_channel_language_set(chan,value)

#define SET_CHAN_HANGUPCAUSE(chan, value) ast_channel_hangupcause_set(chan,value)

#define TEST_FLAG(object, flag) ast_test_flag(GET_CHAN_FLAGS(object),flag)

#define TCPTLS_SESSION_PORT(address)	_ast_sockaddr_port(&address, __FILE__, __LINE__, __PRETTY_FUNCTION__)

#define INITIALIZE_CLIENT_AUDIOCODEC struct ast_format audiocodec

#define FORMAT_FORCE_TO_OLD_BITFIELD(fmt1)	ast_format_to_old_bitfield(&fmt1)

#define FORMAT_FORCE_FROM_OLD_BITFIELD(fmt1, format)	ast_format_from_old_bitfield(&fmt1, format)

#define FORMAT_CLEAR(fmt1) ast_format_clear(&fmt1)

#define GET_FORMAT_NAME_MULTIPLE(string, size, fmt_cap1)	ast_getformatname_multiple(string, size, fmt_cap1)

#define COPY_FORMAT_CAP(dst, src) ast_format_cap_copy(dst,src)

#define CLEAR_CAP_AND_SET_FORMAT(cap, ast_fmt1)	\
	ast_format_cap_remove_all(cap);				\
	ast_format_cap_add(cap, &ast_fmt1);

#define CHECK_CAP_EMPTY(cap) ast_format_cap_is_empty(cap)
	
#define CHECK_FRAME_SUBCLASS_VIDEOMARK(frame) ast_format_get_video_mark(&frame->subclass.format)

#define SET_FORMAT_FROMID_TOVAR(dest, orig)	ast_format_set(&dest, orig, 0)

#define TCPTLS_SESSION_ADDRESS_FORCE_SOCKADDR_IN(remote_address, addr_in)	ast_sockaddr_to_sin(&remote_address, addr_in)

#define GET_CHAN_TECH(chan) ast_channel_tech(chan)

#define ALLOCATE_CAPABILITIES(capabilities) capabilities = AST_FORMAT_CAP_ALLOC_NOLOCK;

#define ADD_CAPABILITIES5(cap, fmt1, fmt2, fmt3, fmt4, fmt5)	\
	struct ast_format tmp_format;								\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt1, 0));	\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt2, 0));	\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt3, 0));	\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt4, 0));	\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt5, 0));
	
#define ADD_CAPABILITIES4(cap, fmt1, fmt2, fmt3, fmt4)	\
	struct ast_format tmp_format;								\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt1, 0));	\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt2, 0));	\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt3, 0));	\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt4, 0));	

#define ADD_CAPABILITIES2(cap, fmt1, fmt2) 	\
	struct ast_format tmp_format;								\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt1, 0));	\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt2, 0));	
	
#define ADD_CAPABILITIES1(cap, fmt1) 	\
	struct ast_format tmp_format;								\
    ast_format_cap_add(cap, ast_format_set(&tmp_format, fmt1, 0));

#define SCHED_CREATE ast_sched_context_create()

#define AST_MANAGER_REGISTER2(action,auth,func,module,synopsis,description) ast_manager_register2(action,auth,func,module,synopsis,description)

#define SET_ADDRESS_LENGTH(address) address = sizeof(struct sockaddr_in)

#define SET_TCPTLS_SESSION_PORT(sock_address, port)	_ast_sockaddr_set_port(&sock_address, port, __FILE__,__LINE__,__PRETTY_FUNCTION__)

#define SET_TCPTLS_SESSION_FAMILY(sock_address, family) sock_address.ss.ss_family = family		

#define GET_CHAN_FDNO(chan) ast_channel_fdno(chan)

#define SCHED_DESTROY(sched) \
	ast_sched_context_destroy(sched);	\
	sched = NULL;

#define SET_FRAME_SUBCLASS_INTEGER(frame, value) frame->subclass.integer = value

#define FORMAT_VAR_TO_ID(fmt1) fmt1.id

#define GET_FORMAT_NAME(fmt1)	ast_getformatname(&fmt1)

#define COMPARE_VARFORMAT_VARFORMAT(ast_fmt1, ast_fmt2) ast_fmt1.id == ast_fmt2.id

#define INITIALIZE_OLDFORMAT struct ast_format_cap *oldformat = AST_FORMAT_CAP_ALLOC_NOLOCK

#define CALL__RMPT_SHOW_USERS __rtmp_show_users(0, a->fd, a->argc, a->argv)
	
	
#endif // __VERSION_MACROS_AST_12__

