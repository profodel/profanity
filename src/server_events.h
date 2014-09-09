/*
 * server_events.h
 *
 * Copyright (C) 2012 - 2014 James Booth <boothj5@gmail.com>
 *
 * This file is part of Profanity.
 *
 * Profanity is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Profanity is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Profanity.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give permission to
 * link the code of portions of this program with the OpenSSL library under
 * certain conditions as described in each individual source file, and
 * distribute linked combinations including the two.
 *
 * You must obey the GNU General Public License in all respects for all of the
 * code used other than OpenSSL. If you modify file(s) with this exception, you
 * may extend this exception to your version of the file(s), but you are not
 * obligated to do so. If you do not wish to do so, delete this exception
 * statement from your version. If you delete this exception statement from all
 * source files in the program, then also delete it here.
 *
 */

#ifndef SERVER_EVENTS_H
#define SERVER_EVENTS_H

#include "xmpp/xmpp.h"

void handle_login_account_success(char *account_name);
void handle_lost_connection(void);
void handle_failed_login(void);
void handle_software_version_result(const char * const jid, const char * const  presence,
    const char * const name, const char * const version, const char * const os);
void handle_disco_info(const char *from, GSList *identities, GSList *features);
void handle_room_list(GSList *rooms, const char *conference_node);
void handle_disco_items(GSList *items, const char *jid);
void handle_room_invite(jabber_invite_t invite_type,
    const char * const invitor, const char * const room,
    const char * const reason);
void handle_room_broadcast(const char *const room_jid,
    const char * const message);
void handle_room_subject(const char * const room_jid, const char * const subject);
void handle_room_history(const char * const room_jid, const char * const nick,
    GTimeVal tv_stamp, const char * const message);
void handle_room_message(const char * const room_jid, const char * const nick,
    const char * const message);
void handle_room_join_error(const char * const room, const char * const err);
void handle_duck_result(const char * const result);
void handle_incoming_message(char *from, char *message, gboolean priv);
void handle_delayed_message(char *from, char *message, GTimeVal tv_stamp,
    gboolean priv);
void handle_typing(char *from);
void handle_gone(const char * const from);
void handle_subscription(const char *from, jabber_subscr_t type);
void handle_contact_offline(char *contact, char *resource, char *status);
void handle_contact_online(char *contact, Resource *resource,
    GDateTime *last_activity);
void handle_leave_room(const char * const room);
void handle_room_nick_change(const char * const room,
    const char * const nick);
void handle_room_requires_config(const char * const room);
void handle_room_destroy(const char * const room);
void handle_room_roster_complete(const char * const room);
void handle_room_member_presence(const char * const room,
    const char * const nick, const char * const show,
    const char * const status, const char * const caps_str);
void handle_room_member_online(const char * const room, const char * const nick,
    const char * const show, const char * const status,
    const char * const caps_str);
void handle_room_member_offline(const char * const room, const char * const nick,
    const char * const show, const char * const status);
void handle_room_member_nick_change(const char * const room,
    const char * const old_nick, const char * const nick);
void handle_group_add(const char * const contact,
    const char * const group);
void handle_group_remove(const char * const contact,
    const char * const group);
void handle_roster_remove(const char * const barejid);
void handle_roster_add(const char * const barejid, const char * const name);
void handle_autoping_cancel(void);
void handle_message_error(const char * const from, const char * const type,
    const char * const err_msg);
void handle_presence_error(const char *from, const char * const type,
    const char *err_msg);
void handle_xmpp_stanza(const char * const msg);
void handle_ping_result(const char * const from, int millis);
void handle_ping_error_result(const char * const from, const char * const error);
void handle_room_configure(const char * const room, DataForm *form);
void handle_room_configuration_form_error(const char * const from, const char * const message);

#endif
