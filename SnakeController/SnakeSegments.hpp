#pragma once

#include <list>
#include <memory>
#include <stdexcept>
#include <functional>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"


class Event;
class IPort;

class SnakeSegments{
public:
    bool isSegmentAtPosition(int x, int y) const;
    struct Segment
    {
        int x;
        int y;
    };
    void pushSeg(Segment seg);
    Segment calculateNewHead() const;
    Snake::DisplayInd removeTailSegment();
    Snake::DisplayInd addHeadSegment(Segment const& newHead);
    std::list<Segment> m_segments;
};