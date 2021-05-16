#ifndef VLC_MANCHESTER_SEND_H
#define VLC_MANCHESTER_SEND_H

// send directly from message string with no extra buffers, reduced memory consumption
int vlc_manchester_send(void *message, int length, int bitrate, int num_sync_symbols);

// needs to be called once before send
// return -1 on error
int vlc_mancheser_init(void);

#endif
