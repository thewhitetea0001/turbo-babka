#pragma once
#include <concord/discord.h>

void on_interaction(struct discord *client, const struct discord_interaction *event);
