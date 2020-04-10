#ifndef YOUTUBEWITHPREVIEWGRAPH_H
#define YOUTUBEWITHPREVIEWGRAPH_H

#include "abstractgraph.h"

#include <string>

typedef struct _GstElement GstElement;
class YoutubeWithPreviewGraph : public AbstractGraph
{
public:
    YoutubeWithPreviewGraph();
    YoutubeWithPreviewGraph(int winid, const std::string &rtmp_location = "");
    ~YoutubeWithPreviewGraph();

    bool start();
    void stop();

private:
    void setup();
    void free();
    void cleanup();

    GstElement *m_pipeline;
    int m_winId;
    std::string m_rtmp_location;
};

#endif // YOUTUBEWITHPREVIEWGRAPH_H
