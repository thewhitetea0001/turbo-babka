#include "../headers/status.h"
#include <string.h>
#include <concord/log.h>

void on_interaction(struct discord *client, const struct discord_interaction *event) {
  if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND) return;
  
  if (strcmp(event->data->name, "status") == 0) {
    struct discord_embed status = {
      .title = "Bot Status",
      .description = "Ping: `n/a`",
      .color = 0xce933b,
    };

    struct discord_interaction_response opts = {
      .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
      .data = &(struct discord_interaction_callback_data){
        .embeds = &(struct discord_embeds){ .size = 1, .array = &status},
      },
    };

    const struct discord_user *u = event->user ? event->user : event->member->user;
    log_info("The command '/status' used by '%s'", u->username);

    discord_create_interaction_response(client, event->id, event->token, &opts, NULL);
  }
}
