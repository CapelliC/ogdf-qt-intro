/*
* ogdf-qt-intro
* @ CapelliC 2017
*/

#include "OgdfScene.h"
#include <QGraphicsItem>

#include <algorithm>
#include <cmath>
using namespace std;

void OgdfScene::draw()
{
    QGraphicsItem* rootNode = writeHeader();

    if (m_clsAttr) {
        drawClusters(rootNode);
    }

    drawEdges(rootNode);
    drawNodes(rootNode);
}

QGraphicsItem* OgdfScene::writeHeader()
{
    DRect box = m_clsAttr ? m_clsAttr->boundingBox() : m_attr.boundingBox();
    double margin = m_settings.margin();
    return addRect(box.p1().m_x - margin, box.p1().m_y - margin,
                   box.width() + 2*margin, box.height() + 2*margin);
}

void OgdfScene::writeDashArray(QGraphicsItem* xmlNode, StrokeType lineStyle, double lineWidth)
{
    Q_UNUSED(xmlNode)

    if (lineStyle != StrokeType::None && lineStyle != StrokeType::Solid) {
        std::stringstream is;

        switch(lineStyle) {
        case StrokeType::Dash:
            is << 4*lineWidth << "," << 2*lineWidth;
            break;
        case StrokeType::Dot:
            is << 1*lineWidth << "," << 2*lineWidth;
            break;
        case StrokeType::Dashdot:
            is << 4*lineWidth << "," << 2*lineWidth << "," << 1*lineWidth << "," << 2*lineWidth;
            break;
        case StrokeType::Dashdotdot:
            is << 4*lineWidth << "," << 2*lineWidth << "," << 1*lineWidth << "," << 2*lineWidth << "," << 1*lineWidth << "," << 2*lineWidth;
            break;
        default:
            // will never happen
            break;
        }

        //xmlNode.append_attribute("stroke-dasharray") = is.str().c_str();
    }
}

void OgdfScene::drawNode(QGraphicsItem* xmlNode, node v)
{
    QAbstractGraphicsShapeItem* shape;

    double x = m_attr.x(v);
    double y = m_attr.y(v);
    double w = m_attr.width(v);
    double h = m_attr.height(v);

    // values are precomputed to save expensive sin/cos calls
    switch (m_attr.shape(v)) {
    case Shape::Ellipse:
        shape = addEllipse(x, y, w, h);
        break;
    case Shape::Triangle:
        shape = drawPolygon(xmlNode, {
                                x,          y - h/2,
                                x - w/2,    y + h/2,
                                x + w/2,    y + h/2
                            });
        break;
    case Shape::InvTriangle:
        shape = drawPolygon(xmlNode, {
                                x,          y + h/2,
                                x - w/2,    y - h/2,
                                x + w/2,    y - h/2
                            });
        break;
    case Shape::Pentagon: {
        const double
                pentagonHalfWidth = 0.475528258147577 * w,
                pentagonSmallHeight = 0.154508497187474 * h,
                pentagonSmallWidth = 0.293892626146236 * w,
                pentagonHalfHeight = 0.404508497187474 * h;
        shape = drawPolygon(xmlNode, {
                                x,                      y - h/2,
                                x + pentagonHalfWidth,  y - pentagonSmallHeight,
                                x + pentagonSmallWidth, y + pentagonHalfHeight,
                                x - pentagonSmallWidth, y + pentagonHalfHeight,
                                x - pentagonHalfWidth,  y - pentagonSmallHeight
                            });
    }
        break;
    case Shape::Hexagon: {
        const double
                hexagonHalfHeight = 0.43301270189222 * h;
        shape = drawPolygon(xmlNode, {
                                x + w/4, y + hexagonHalfHeight,
                                x - w/4, y + hexagonHalfHeight,
                                x - w/2, y,
                                x - w/4, y - hexagonHalfHeight,
                                x + w/4, y - hexagonHalfHeight,
                                x + w/2, y
                            });
    }
        break;
    case Shape::Octagon: {
        const double
                octagonHalfWidth = 0.461939766255643 * w,
                octagonSmallWidth = 0.191341716182545 * w,
                octagonHalfHeight  = 0.461939766255643 * h,
                octagonSmallHeight = 0.191341716182545 * h;

        shape = drawPolygon(xmlNode, {
                                x + octagonHalfWidth,   y + octagonSmallHeight,
                                x + octagonSmallWidth,  y + octagonHalfHeight,
                                x - octagonSmallWidth,  y + octagonHalfHeight,
                                x - octagonHalfWidth,   y + octagonSmallHeight,
                                x - octagonHalfWidth,   y - octagonSmallHeight,
                                x - octagonSmallWidth,  y - octagonHalfHeight,
                                x + octagonSmallWidth,  y - octagonHalfHeight,
                                x + octagonHalfWidth,   y - octagonSmallHeight
                            });
    }
        break;
    case Shape::Rhomb:
        shape = drawPolygon(xmlNode, {
                                x + w/2 , y,
                                x       , y + h/2,
                                x - w/2 , y,
                                x       , y - h/2
                            });
        break;
    case Shape::Trapeze:
        shape = drawPolygon(xmlNode, {
                                x - w/2, y + h/2,
                                x + w/2, y + h/2,
                                x + w/4, y - h/2,
                                x - w/4, y - h/2
                            });
        break;
    case Shape::InvTrapeze:
        shape = drawPolygon(xmlNode, {
                                x - w/2, y - h/2,
                                x + w/2, y - h/2,
                                x + w/4, y + h/2,
                                x - w/4, y + h/2
                            });
        break;
    case Shape::Parallelogram:
        shape = drawPolygon(xmlNode, {
                                x - w/2, y + h/2,
                                x + w/4, y + h/2,
                                x + w/2, y - h/2,
                                x - w/4, y - h/2
                            });
        break;
    case Shape::InvParallelogram:
        shape = drawPolygon(xmlNode, {
                                x - w/2, y - h/2,
                                x + w/4, y - h/2,
                                x + w/2, y + h/2,
                                x - w/4, y + h/2
                            });
        break;

        // unsupported shapes are rendered as rectangle
    case Shape::RoundedRect:
        //shape = addRoundedRect(x - w/2, y - h/2, w, h, w/10, h/10);
        //break;
    default:
        shape = addRect(x - w/2, y - h/2, w, h);
        break;
    }

    if (m_attr.has(GraphAttributes::nodeStyle)) {
        shape->setBrush(QColor(m_attr.fillColor(v).toString().c_str()));
        /*
        shape.append_attribute("fill") = m_attr.fillColor(v).toString().c_str();
        shape.append_attribute("stroke-width") = (to_string(m_attr.strokeWidth(v)) + "px").c_str();
        */

        //StrokeType lineStyle = m_attr.has(GraphAttributes::nodeStyle) ? m_attr.strokeType(v) : stSolid;

        /*if (lineStyle == stNone) {
            shape.append_attribute("stroke") = "none";
        } else {
            shape.append_attribute("stroke") = m_attr.strokeColor(v).toString().c_str();
            writeDashArray(shape, lineStyle, m_attr.strokeWidth(v));
        }*/
    }

    if (m_attr.has(GraphAttributes::nodeLabel)) {
        QFont font;
        font.setFamily(m_settings.fontFamily().c_str());
        font.setPixelSize(m_settings.fontSize());
        QAbstractGraphicsShapeItem* label = addSimpleText(m_attr.label(v).c_str(), font);
        auto bb = label->boundingRect();
        double x = m_attr.x(v) - bb.width()/2, y = m_attr.y(v) - bb.height()/2;
        if (m_attr.has(GraphAttributes::nodeLabelPosition))
            label->setPos(x + m_attr.xLabel(v), y + m_attr.yLabel(v));
        else
            label->setPos(x, y);
        label->setBrush(QColor(m_settings.fontColor().c_str()));
    }
}

void OgdfScene::drawCluster(QGraphicsItem* xmlNode, cluster c)
{
    Q_UNUSED(xmlNode)
    Q_UNUSED(c)

    OGDF_ASSERT(m_clsAttr);

    /*
    QGraphicsItem* cluster;
    if (c == m_clsAttr->constClusterGraph().rootCluster()) {
        cluster = xmlNode;
    } else {
        cluster = xmlNode.append_child("rect");
        cluster.append_attribute("x") = m_clsAttr->x(c);
        cluster.append_attribute("y") = m_clsAttr->y(c);
        cluster.append_attribute("width") = m_clsAttr->width(c);
        cluster.append_attribute("height") = m_clsAttr->height(c);
        cluster.append_attribute("fill") = m_clsAttr->fillPattern(c) == fpNone ? "none" : m_clsAttr->fillColor(c).toString().c_str();
        cluster.append_attribute("stroke") = m_clsAttr->strokeType(c) == stNone ? "none" : m_clsAttr->strokeColor(c).toString().c_str();
        cluster.append_attribute("stroke-width") = (to_string(m_clsAttr->strokeWidth(c)) + "px").c_str();
    }
    */
}

void OgdfScene::drawNodes(QGraphicsItem* xmlNode)
{
    List<node> nodes;
    m_attr.constGraph().allNodes(nodes);

    if (m_attr.has(GraphAttributes::nodeGraphics | GraphAttributes::threeD)) {
        class NodeComparer {
        private:
            const GraphAttributes *m_attr;
        public:
            NodeComparer(const GraphAttributes &attr) : m_attr(&attr) {}
            double compare(const node &v, const node &w) const {
                return m_attr->z(v) - m_attr->z(w);
            }
            OGDF_AUGMENT_COMPARER(node)
        };

        nodes.quicksort(NodeComparer(m_attr));
    }

    for (node v : nodes) {
        drawNode(xmlNode, v);
    }
}

void OgdfScene::drawClusters(QGraphicsItem* xmlNode)
{
    Q_UNUSED(xmlNode)

    OGDF_ASSERT(m_clsAttr);

    /*
    Queue<cluster> queue;
    queue.append(m_clsAttr->constClusterGraph().rootCluster());

    while (!queue.empty()) {
        cluster c = queue.pop();
        drawCluster(xmlNode.append_child("g"), c);

        for (cluster child : c->children) {
            queue.append(child);
        }
    }*/
}

void OgdfScene::drawEdges(QGraphicsItem* xmlNode)
{
    if (m_attr.has(GraphAttributes::edgeGraphics)) {
        auto g = new QGraphicsItemGroup(xmlNode);
        for (edge e : m_attr.constGraph().edges)
            drawEdge(g, e);
    }
}

void OgdfScene::appendLineStyle(QGraphicsItem* line, edge e) {

    StrokeType lineStyle = m_attr.has(GraphAttributes::edgeStyle) ? m_attr.strokeType(e) : StrokeType::Solid;

    if (lineStyle != StrokeType::None) {
        if (m_attr.has(GraphAttributes::edgeStyle)) {
            /*
            line.append_attribute("stroke") = m_attr.strokeColor(e).toString().c_str();
            line.append_attribute("stroke-width") = (to_string(m_attr.strokeWidth(e)) + "px").c_str();
            */
            writeDashArray(line, lineStyle, m_attr.strokeWidth(e));
        } else {
            //line.append_attribute("stroke") = "#000000";
        }
    }
}

QAbstractGraphicsShapeItem* OgdfScene::drawPolygon(QGraphicsItem*, const list<double> points) {

    OGDF_ASSERT(points.size() % 2 == 0);
    QPolygonF poly;

    auto pt = [&](list<double>::const_iterator &i) {
        double x = *i++, y = *i++;
        poly << QPointF(x, y);
    };
    for (auto i = points.begin(); i != points.end(); )
        pt(i);
    auto i = points.begin();
    pt(i);

    QPainterPath path;
    path.addPolygon(poly);
    return addPath(path);
}

double OgdfScene::getArrowSize(edge e, node v) {
    const double minSize = (m_attr.has(GraphAttributes::edgeStyle) ? m_attr.strokeWidth(e) : 1) * 3;
    node w = e->opposite(v);
    return std::max(minSize, (m_attr.width(v) + m_attr.height(v) + m_attr.width(w) + m_attr.height(w)) / 16.0);
}

bool OgdfScene::isCoveredBy(const DPoint &point, edge e, node v) {
    double arrowSize = getArrowSize(e, v);

    return point.m_x >= m_attr.x(v) - m_attr.width(v)/2 - arrowSize
            && point.m_x <= m_attr.x(v) + m_attr.width(v)/2 + arrowSize
            && point.m_y >= m_attr.y(v) - m_attr.height(v)/2 - arrowSize
            && point.m_y <= m_attr.y(v) + m_attr.height(v)/2 + arrowSize;
}

void OgdfScene::drawEdge(QGraphicsItem* xmlNode, edge e) {
    // draw arrows if G is directed or if arrow types are defined for the edge
    bool drawSourceArrow = false;
    bool drawTargetArrow = false;

    if (m_attr.has(GraphAttributes::edgeArrow)) {
        switch (m_attr.arrowType(e)) {
        case EdgeArrow::Undefined:
            drawTargetArrow = m_attr.directed();
            break;
        case EdgeArrow::Last:
            drawTargetArrow = true;
            break;
        case EdgeArrow::Both:
            drawTargetArrow = true;

        [[clang::fallthrough]];
        case EdgeArrow::First:
            drawSourceArrow = true;
            break;
        default:
            // don't draw any arrows
            break;
        }
    }

    auto g = new QGraphicsItemGroup(xmlNode);

    bool drawLabel = m_attr.has(GraphAttributes::edgeLabel) && !m_attr.label(e).empty();
    QGraphicsItem* label;
    if (drawLabel) {
        label = addSimpleText(m_attr.label(e).c_str());
        g->addToGroup(label);
        /*
        label.append_attribute("text-anchor") = "middle";
        label.append_attribute("dominant-baseline") = "middle";
        label.append_attribute("font-family") = m_settings.fontFamily().c_str();
        label.append_attribute("font-size") = m_settings.fontSize();
        label.append_attribute("fill") = m_settings.fontColor().c_str();
        label.text() = m_attr.label(e).c_str();
        */
    }

    DPolyline path = m_attr.bends(e);
    node s = e->source();
    node t = e->target();
    path.pushFront(DPoint(m_attr.x(s), m_attr.y(s)));
    path.pushBack(DPoint(m_attr.x(t), m_attr.y(t)));

    bool drawSegment = false;
    bool finished = false;

    List<DPoint> points;

    for (ListConstIterator<DPoint> it = path.begin(); it.succ().valid() && !finished; it++) {
        DPoint p1 = *it;
        DPoint p2 = *(it.succ());

        // leaving segment at source node ?
        if (isCoveredBy(p1, e, s) && !isCoveredBy(p2, e, s)) {
            if (!drawSegment && drawSourceArrow) {
                drawArrowHead(g, p2, p1, s, e);
            }
            drawSegment = true;
        }

        // entering segment at target node ?
        if (!isCoveredBy(p1, e, t) && isCoveredBy(p2, e, t)) {
            finished = true;

            if (drawTargetArrow) {
                drawArrowHead(g, p1, p2, t, e);
            }
        }

        if (drawSegment && drawLabel) {
            label->setPos((p1.m_x + p2.m_x) / 2, (p1.m_y + p2.m_y) / 2);
            drawLabel = false;
        }

        if (drawSegment) {
            points.pushBack(p1);
        }

        if (finished) {
            points.pushBack(p2);
        }
    }

    if (points.size() < 2) {
        GraphIO::logger.lout() << "Could not draw edge since nodes are overlapping: " << e << endl;
    } else {
        drawCurve(g, e, points);
    }
}

void OgdfScene::drawLine(QGraphicsItem *ss, const DPoint &p1, const DPoint &p2) {
    Q_UNUSED(ss)

    addLine(p1.m_x, p1.m_y, p2.m_x, p2.m_y);
}


void OgdfScene::drawBezier(QGraphicsItem* xmlNode, const DPoint &p1, const DPoint &p2, const DPoint &c1, const DPoint &c2) {
    Q_UNUSED(xmlNode)
    Q_UNUSED(p1)
    Q_UNUSED(p2)
    Q_UNUSED(c1)
    Q_UNUSED(c2)

    //ss << " M" << p1.m_x << "," << p1.m_y << " C" << c1.m_x << "," << c1.m_y << "  " << c2.m_x << "," << c2.m_y << " " << p2.m_x << "," << p2.m_y;
}

void OgdfScene::drawBezierPath(QGraphicsItem* xmlNode, List<DPoint> &points) {
    const double c = m_settings.curviness();
    DPoint cLast = 0.5 * (points.front() + *points.get(1));

    while (points.size() >= 3) {
        const DPoint p1 = points.popFrontRet();
        const DPoint p2 = points.front();
        const DPoint p3 = *points.get(1);

        const DPoint delta = p2 - 0.5 * (p1+p3);
        const DPoint c1 = p1 + c * delta + (1-c) * (p2-p1);
        const DPoint c2 = p3 + c * delta + (1-c) * (p2-p3);

        drawBezier(xmlNode, p1, p2, cLast, c1);

        cLast = c2;
    }

    const DPoint p1 = points.popFrontRet();
    const DPoint p2 = points.popFrontRet();
    const DPoint c1 = 0.5 * (p2 + p1);

    drawBezier(xmlNode, p1, p2, cLast, c1);
}

void OgdfScene::drawRoundPath(QGraphicsItem* xmlNode, List<DPoint> &points) {
    const double c = m_settings.curviness();

    DPoint p1 = points.front();
    DPoint p2 = *points.get(1);

    drawLine(xmlNode, p1, .5 * ((p1+p2) + (1-c) * (p2-p1)));

    while (points.size() >= 3) {
        DPoint p1 = points.popFrontRet();
        DPoint p2 = points.front();
        DPoint p3 = *points.get(1);

        DPoint v1 = (p1 - p2);
        DPoint v2 = (p3 - p2);

        double length = std::min(v1.norm(), v2.norm()) * c / 2;

        v1 *= length / v1.norm();
        v2 *= length / v2.norm();

        DPoint pA = p2 + v1;
        DPoint pB = p2 + v2;

        drawLine(xmlNode, 0.5 * (p1+p2), pA);
        drawLine(xmlNode, 0.5 * (p3+p2), pB);

        DPoint vA = p2 - p1;
        DPoint vB = p3 - p1;
        bool doSweep = vA.m_x*vB.m_y - vA.m_y*vB.m_x > 0;
        Q_UNUSED(doSweep)

        //ss << " M" << pA.m_x << "," << pA.m_y << " A" << length << "," << length << " 0 0 " << (doSweep ? 1 : 0) << " " << pB.m_x << "," << pB.m_y << "";
    }

    p1 = points.popFrontRet();
    p2 = points.popFrontRet();

    drawLine(xmlNode, p2, .5 * ((p1 + p2) + (1-c) * (p1-p2)));
}

void OgdfScene::drawLines(QGraphicsItem* xmlNode, List<DPoint> &points) {
    while (points.size() > 1) {
        DPoint p = points.popFrontRet();
        drawLine(xmlNode, p, points.front());
    }
}

QGraphicsItem* OgdfScene::drawCurve(QGraphicsItem* xmlNode, edge e, List<DPoint> &points) {
    Q_UNUSED(xmlNode)
    OGDF_ASSERT(points.size() >= 2);

    QGraphicsItem* gline = new QGraphicsItemGroup;

    if (points.size() == 2) {
        const DPoint p1 = points.popFrontRet();
        const DPoint p2 = points.popFrontRet();
        drawLine(gline, p1, p2);
    } else {
        if (m_settings.curviness() == 0) {
            drawLines(gline, points);
        } else if (m_settings.bezierInterpolation()) {
            drawBezierPath(gline, points);
        } else {
            drawRoundPath(gline, points);
        }
    }

    //line.append_attribute("fill") = "none";
    //line.append_attribute("d") = ss.str().c_str();
    appendLineStyle(gline, e);
    return gline;
}

void OgdfScene::drawArrowHead(QGraphicsItem* xmlNode, const DPoint &start, DPoint &end, node v, edge e)
{
    const double dx = end.m_x - start.m_x;
    const double dy = end.m_y - start.m_y;
    const double size = getArrowSize(e, v);

    QAbstractGraphicsShapeItem* arrowHead;

    if (dx == 0) {
        int sign = dy > 0 ? 1 : -1;
        double y = m_attr.y(v) - m_attr.height(v)/2 * sign;
        end.m_y = y - sign * size;

        arrowHead = drawPolygon(xmlNode, {
                                    end.m_x, y,
                                    end.m_x - size/4, y - size*sign,
                                    end.m_x + size/4, y - size*sign
                                });
    } else {
        // identify the position of the tip

        double slope = dy / dx;
        int sign = dx > 0 ? 1 : -1;

        double x = m_attr.x(v) - m_attr.width(v)/2 * sign;
        double delta = x - start.m_x;
        double y = start.m_y + delta*slope;

        if (!isCoveredBy(DPoint(x,y), e, v)) {
            sign = dy > 0 ? 1 : -1;
            y = m_attr.y(v) - m_attr.height(v)/2 * sign;
            delta = y - start.m_y;
            x = start.m_x + delta/slope;
        }

        end.m_x = x;
        end.m_y = y;

        // draw the actual arrow head

        double dx2 = end.m_x - start.m_x;
        double dy2 = end.m_y - start.m_y;
        double length = std::sqrt(dx2*dx2 + dy2*dy2);
        dx2 /= length;
        dy2 /= length;

        double mx = end.m_x - size * dx2;
        double my = end.m_y - size * dy2;

        double x2 = mx - size/4 * dy2;
        double y2 = my + size/4 * dx2;

        double x3 = mx + size/4 * dy2;
        double y3 = my - size/4 * dx2;

        arrowHead = drawPolygon(xmlNode, {end.m_x, end.m_y, x2, y2, x3, y3});
    }
    arrowHead->setBrush(QColor("black"));

    appendLineStyle(arrowHead, e);
}
