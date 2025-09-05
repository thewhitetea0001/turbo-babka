#include "../headers/on_ready.h"
#include <concord/log.h>

#define GUILD_ID 1413262251451744418

void on_ready(struct discord *client, const struct discord_ready *event) {
    struct discord_create_guild_application_command status = {
      .name = "status",
      .description = "Техничиская информация о боте"
    };    
    discord_create_guild_application_command(client, event->application->id,
                                             GUILD_ID, &status, NULL);

    log_info("Logged in as '%s#%s'!", event->user->username, event->user->discriminator);
}
