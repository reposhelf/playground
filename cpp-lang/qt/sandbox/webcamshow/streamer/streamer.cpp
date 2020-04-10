#include "streamer.h"
#include "previewgraph.h"
#include "youtubegraph.h"
#include "youtubewithpreviewgraph.h"
#include "videotestgraph.h"

#include <unistd.h>
#include <iostream>
#include <string>

enum StreamType
{
    Unknown = 0,
    Preview = 1 << 0,
    Youtube = 1 << 1,
    YoutubeWithPreview = Preview | Youtube
};

Streamer::Streamer(int argc, char **argv)
    : m_graph(nullptr)
{
    char c;
    int winid = 0;
    std::string rtmp_location;

    unsigned stream_type = Unknown;

    while ((c = getopt(argc, argv, "r:p:")) != EOF) {
        switch (c) {
        case 'p':
            winid = std::atoi(optarg);
            stream_type |= Preview;
            break;

        case 'r':
            rtmp_location = optarg;
            stream_type |= Youtube;
            break;

        default:
            break;
        }
    }

    switch (stream_type) {
    case Preview:
        m_graph = new PreviewGraph(winid);
        break;

    case Youtube:
        m_graph = new YoutubeGraph(rtmp_location);
        break;

    case YoutubeWithPreview:
        m_graph = new YoutubeWithPreviewGraph(winid, rtmp_location);
        break;

    case Unknown: // fall down
    default:
        m_graph = new VideoTesGraph();
        break;
    }
}

Streamer::~Streamer()
{
    if (m_graph)
        delete m_graph;
}

int Streamer::exec()
{
    if (!m_graph) {
        std::cout << "ERROR: graph is corrupted" << std::endl;
        return 1;
    }

    if (!m_graph->start()) {
        std::cout << "ERROR: failed to start streaming, pipeline is corrupted" << std::endl;
        return 1;
    }

    while (!waitForInput()) { /* empty */ }

    m_graph->stop();

    return 0;
}

bool Streamer::waitForInput()
{
    char input;
    bool stop = false;

    while (!stop) {
        std::cin >> input;

        switch (input) {
        case 'q':
            stop = true;
            break;
        default:
            break;
        }
    }
    return stop;
}
