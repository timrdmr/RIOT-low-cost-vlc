#ifndef VLC_NETIF_H
#define VLC_NETIF_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Initialize the netif implementation, spawns the netif thread
 *
 * This function is meant to be called once during system initialization, i.e.
 * auto-init.
 */
void vlc_netif_init(void);

#ifdef __cplusplus
}
#endif

#endif /* VLC_NETIF_H */
/** @} */
