#include "video_streaming.h"

/* Todo: When we introduce threads we may need to change the logic.
 * Perhaps we will have a "thread_data" struct that will hold these per thread. */
static GstElement *pipeline;
static GstElement *source;          /* Source element that provides video data. */
static GstElement *video_encoder;    /* Encodes the video. */
static GstElement *audio_encoder;    /* Encodes the audio. */
static GstElement *mux;             /* Multiplexes the encoded video and audio streams. */
static GstElement *sink;            /* Used for sending multimedia data over the network via UDP. */

int video_streaming_init()
{
    gst_init(NULL, NULL);

    pipeline = gst_pipeline_new("server-pipeline");

    source = gst_element_factory_make("filesrc", "source");
    g_object_set(source, "location", "./videos/test.mp4", NULL);

    video_encoder = gst_element_factory_make("x264enc", "videoencoder");
    audio_encoder = gst_element_factory_make("voaacenc", "audioencoder");
    mux = gst_element_factory_make("mpegtsmux", "mux");
    sink = gst_element_factory_make("udpsink", "sink");

    if (!pipeline || !source || !video_encoder || !audio_encoder || !mux || !sink) {
        server_log(ERR, "Error encountered during GStreamer initialization.\n");
        return -1;
    }

    /* Set element properties, link them, and add them to the pipeline
     * (Specifics will depend on your use case) */
    if (!gst_element_link(source, video_encoder) || !gst_element_link(video_encoder, mux) ||
        !gst_element_link(audio_encoder, mux) || !gst_element_link(mux, sink)) {
        server_log(ERR, "Failed to link elements.\n");
        return -1;
    }

    if (!gst_element_set_state(pipeline, GST_STATE_PLAYING)) {
        server_log(ERR, "Failed to set state to PLAYING.\n");
        return -1;
    }

    server_log(DBG, "Video streaming initialization complete (pipeline started).\n");
    return 0;
}

void video_streaming_destroy()
{
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(source);
    gst_object_unref(video_encoder);
    gst_object_unref(audio_encoder);
    gst_object_unref(mux);
    gst_object_unref(sink);
    gst_object_unref(pipeline);
    gst_deinit();
    server_log(DBG, "Video streaming destroy completed.\n");
}