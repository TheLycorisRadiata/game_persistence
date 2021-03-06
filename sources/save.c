#include "../headers/save.h"

void save_game(FILE* save_file)
{
    int i;

    fprintf(save_file, "previous_location:%d\n", !PLAYER->previous_location ? -1 : PLAYER->previous_location->id);
    fprintf(save_file, "current_location:%d\n", PLAYER->current_location->id);

    fprintf(save_file, "events:");
    for (i = 0; i < NBR_EVENTS; ++i)
    {
        if (!i)
            fprintf(save_file, "%d", list_events[i]);
        else
            fprintf(save_file, ",%d", list_events[i]);
    }
    fprintf(save_file, "\n");

    fprintf(save_file, "inventory:");
    for (i = 0; i < NBR_ITEMS; ++i)
    {
        if (!PLAYER->inventory[i])
            break;

        if (!i)
            fprintf(save_file, "%d", PLAYER->inventory[i]->id);
        else
            fprintf(save_file, ",%d", PLAYER->inventory[i]->id);
    }
    fprintf(save_file, "\n");

    return;
}

