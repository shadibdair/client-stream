/*
* This component handles the rendering and display of video frames received from the server. 
* It synchronizes video playback, manages buffering, and updates the GUI with the video content.
*/

#ifndef CLIENT_VIDEO_H
#define CLIENT_VIDEO_H

#include "utils.h"

void video_play(const char *video_data, uint32_t video_length);

#endif /* CLIENT_VIDEO_H */