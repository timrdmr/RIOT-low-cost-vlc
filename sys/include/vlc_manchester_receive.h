#ifndef VLC_MANCHESTER_RECEIVE_H
#define VLC_MANCHESTER_RECEIVE_H

#include "net/gnrc/netif.h"

enum edge {
    FALLING = 0, 
    RISING = 1
};

enum receive_state {
    COMPLETE,          // complete bytes were received, but no guarantee that message contains all send bytes
    INCOMPLETE,        // not all bytes were received completely
    // TIMEOUT
};

struct receive_configuration_t
{
    // tolerance of the time where an edge is still identified as a symbol
    unsigned int tolerance;

    // one sync symbol consists of a high and low edge, must be > 0
    unsigned int num_sync_symbols;

    // initialize for synchronous read calls
    unsigned int synchronous;

    struct netdev *netdev;

    unsigned int buffer_size;
};

struct receive_result_meta_t
{
    // TODO: unused if end of transmission is detected by callback method
    enum receive_state state;           // state of received data
    unsigned int num_bytes_read;
    unsigned int data_rate;             // datarate in bits/s
};

// init for receive 
// read process controlled by callback passed by the receive config
void vlc_init_receiver(void *buffer, struct receive_configuration_t config, struct receive_result_meta_t *result_meta);

// reset the receiver after a transmission was finished and the buffer and meta data was saved 
void vlc_reset_receiver(void);

// vlc_init_receiver must be called
// blocking if manchester init was called with synchronous = 1
// returns message and metadata as receive result
// NOTE:    Synchronous read is not needed for the VLC integration into the VLC network stack.
//          It can be e.g. used for testing.   
void manchester_read(struct receive_result_meta_t *result_meta);

void vlc_receiver_run_unit_tests(void);

#endif
