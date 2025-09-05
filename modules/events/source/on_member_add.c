#include <../headers/on_member_add.h>
#include <concord/log.h>

#define MEMBER_ROLE_ID 1413262631485046834

void on_member_add(struct discord *client,
                   const struct discord_guild_member *event) {
    log_info("Added role '%" PRIu64 "' for member '%s'",
             MEMBER_ROLE_ID, event->user->username);
    discord_add_guild_member_role(client,
                                  event->guild_id,
                                  event->user->id,
                                  MEMBER_ROLE_ID,
                                  NULL,
                                  NULL);
}
