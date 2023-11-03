# client-stream-vod
Using C language for stream vod

Install SDL Development Libararies:
sudo apt-get install libsdl2-dev


Install GStreamer and its development files:
sudo apt install libgstreamer1.0-0 libgstreamer1.0-dev

Ensure that the following works (GStreamer plugins are installed):
```
gst-inspect-1.0 videotestsrc
gst-inspect-1.0 x264enc
gst-inspect-1.0 voaacenc
gst-inspect-1.0 mpegtsmux
gst-inspect-1.0 udpsink
```

It is common for `mpegtsmux` to be missing, you can install it with the following command:
sudo apt-get install gstreamer1.0-plugins-bad