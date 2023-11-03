/*
* This component manages the streaming of video content to connected clients. 
* It should handle video encoding, streaming, and synchronization.
*/

#ifndef VIDEO_STREAMING_H
#define VIDEO_STREAMING_H

#include <gstreamer-1.0/gst/gst.h>

void video_streaming_init(int argc, char *argv[]);

#endif /* VIDEO_STREAMING_H */