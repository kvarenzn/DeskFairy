#include "MouseTracker.h"
#include <QMouseEvent>
#include <QCursor>
#include "Logger.h"
#include "Defines.h"

MouseTracker::MouseTracker(QObject* parent)
	: QObject(parent)
{
	_timer = new QTimer(this);
	_timer->start(1000 / Def::mouseTrackTimePerFrame);
	connect(_timer, &QTimer::timeout, this, &MouseTracker::_trackMouse);
}

MouseTracker::~MouseTracker()
{
	
}


void MouseTracker::_trackMouse()
{
	auto pos = QCursor::pos();

	mouseMoveSignal(pos.x(), pos.y());
}