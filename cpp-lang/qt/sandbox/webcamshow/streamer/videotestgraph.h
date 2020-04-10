#ifndef VIDEOTESTGRAPH_H
#define VIDEOTESTGRAPH_H

#include "abstractgraph.h"

typedef struct _GstElement GstElement;
class VideoTesGraph : public AbstractGraph
{
public:
    VideoTesGraph();
    ~VideoTesGraph();

    bool start();
    void stop();

private:
    void setup();
    void free();
    void cleanup();

    GstElement *m_pipeline;
};

#endif // VIDEOTESTGRAPH_H
