#include <concord/discord.h>

// events
#include "modules/events/headers/on_ready.h"
#include "modules/events/headers/on_member_add.h"

// commands
#include "modules/commands/headers/status.h"

int main() {
  struct discord *client = discord_config_init("config.json");
  
  discord_set_on_ready(client, &on_ready);
  discord_set_on_guild_member_add(client, &on_member_add);
  discord_set_on_interaction_create(client, &on_interaction);

  discord_run(client);
}
