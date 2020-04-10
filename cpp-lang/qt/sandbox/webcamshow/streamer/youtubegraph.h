#ifndef YOUTUBEGRAPH_H
#define YOUTUBEGRAPH_H

#include "abstractgraph.h"

#include <string>

typedef struct _GstElement GstElement;
class YoutubeGraph : public AbstractGraph
{
public:
    YoutubeGraph();
    YoutubeGraph(const std::string &rtmp_location = "");
    ~YoutubeGraph();

    bool start();
    void stop();

private:
    void setup();
    void free();
    void cleanup();

    GstElement *m_pipeline;
    std::string m_rtmp_location;
};

#endif // YOUTUBEGRAPH_H
