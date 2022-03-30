#include "SnakeSegments.hpp"
#include "SnakeInterface.hpp"

#include <algorithm>
#include <sstream>

#include "EventT.hpp"
#include "IPort.hpp"

bool SnakeSegments::isSegmentAtPosition(int x, int y) const
{
    return m_segments.end() !=  std::find_if(m_segments.cbegin(), m_segments.cend(),
        [x, y](auto const& segment){ return segment.x == x and segment.y == y; });
}

void SnakeSegments::pushSeg(Segment seg)
{
    m_segments.push_back(seg);
}

Snake::DisplayInd SnakeSegments::removeTailSegment()
{
    auto tail = m_segments.back();

    Snake::DisplayInd l_evt;
    l_evt.x = tail.x;
    l_evt.y = tail.y;
    l_evt.value = Snake::Cell_FREE;

    m_segments.pop_back();

    return l_evt;
}

Snake::DisplayInd SnakeSegments::addHeadSegment(Segment const& newHead)
{
    m_segments.push_front(newHead);

    Snake::DisplayInd placeNewHead;
    placeNewHead.x = newHead.x;
    placeNewHead.y = newHead.y;
    placeNewHead.value = Snake::Cell_SNAKE;

    return placeNewHead;
}

/*bool isHorizontal(Snake::Direction direction)
{
    return Snake::Direction_LEFT == direction or Snake::Direction_RIGHT == direction;
}

SnakeSegments::Segment Controller::calculateNewHead() const
{
    Segment const& currentHead = snakesegments.m_segments.front();

    Segment newHead;
    newHead.x = currentHead.x + (isHorizontal(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);
    newHead.y = currentHead.y + (isVertical(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);

    return newHead;
}*/