/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#ifndef OGDFSCENE_H
#define OGDFSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <ogdf/fileformats/GraphIO.h>
#include "OgdfSettings.h"

using namespace ogdf;

class OgdfScene : public QGraphicsScene
{
    Q_OBJECT

public:
    OgdfScene(const GraphAttributes &attr, const OgdfSettings &settings)
        : m_attr(attr)
        , m_clsAttr(nullptr)
        , m_settings(settings)
    {
    }

    OgdfScene(const ClusterGraphAttributes &attr, const OgdfSettings &settings)
        : m_attr(attr)
        , m_clsAttr(&attr)
        , m_settings(settings)
    {
    }

    void draw();

private:

	//! attributes of the graph to be visualized
	const GraphAttributes &m_attr;

	//! attributes of the cluster graph (\a nullptr if no cluster graph)
	const ClusterGraphAttributes *m_clsAttr;

	//! SVG configuration
	const OgdfSettings &m_settings;

	/**
	 * Draws a rectangle for each cluster in the ogdf::ClusterGraph.
	 *
	 * \param xmlNode the XML-node to print to
	 */
	void drawClusters(QGraphicsItem* xmlNode);

	/**
	 * Draws a sequence of lines for each edge in the graph.
	 *
	 * \param xmlNode the XML-node to print to
	 */
	void drawEdges(QGraphicsItem* xmlNode);

	/**
	 * Draws a sequence of lines for an edge.
	 * Arrow heads are added if requested.
	 *
	 * \param xmlNode the XML-node to print to
	 * \param e the edge to be visualized
	 */
	void drawEdge(QGraphicsItem* xmlNode, edge e);

	/**
	 * Draws the curve depicting a particular edge.
	 * Draws a sequence of cubic Bézier curves if requested.
	 * Falls back to straight lines if there are exactly two points or the curviness is set to 0.
	 *
	 * Note that this method clears the list of points.
	 *
	 * \param xmlNode the XML-node to print to
	 * \param points the points along the curve
	 * \param e the edge depicted by the curve
	 * \return the XML-node of the curve
	 */
	QGraphicsItem* drawCurve(QGraphicsItem* xmlNode, edge e, List<DPoint> &points);

	/**
	 * Draws the path corresponding to a single line to the stream.
	 *
	 * \param ss the output stream
	 * \param p1 the first point of the line
	 * \param p2 the second point of the line
	 */
	void drawLine(QGraphicsItem* xmlNode, const DPoint &p1, const DPoint &p2);

	/**
	 * Draws a list of points using cubic Bézier interpolation.
	 *
	 * \param ss the output stream
	 * \param points the points to be connected by lines
	 */
	void drawBezierPath(QGraphicsItem* xmlNode, List<DPoint> &points);

	/**
	 * Draws a list of points as straight lines connected by circular arcs.
	 *
	 * \param ss the output stream
	 * \param points the points to be connected by lines
	 */
	void drawRoundPath(QGraphicsItem* xmlNode, List<DPoint> &points);

	/**
	 * Draws a list of points as straight lines.
	 *
	 * \param ss the output stream
	 * \param points the points to be connected by lines
	 */
	void drawLines(QGraphicsItem* xmlNode, List<DPoint> &points);

	/**
	 * Draws a cubic Bezíer path.
	 *
	 * \param ss the output stream
	 * \param p1 the first point of the line
	 * \param p2 the second point of the line
	 * \param c1 the first control point of the line
	 * \param c2 the second control point of the line
	 */
	void drawBezier(QGraphicsItem* xmlNode, const DPoint &p1, const DPoint &p2, const DPoint &c1, const DPoint &c2);

	/**
	 * Draws all nodes of the graph.
	 *
	 * \param xmlNode the XML-node to print to
	 */
	void drawNodes(QGraphicsItem* xmlNode);

	/**
	 * Writes the header including the bounding box as the viewport.
	 *
	 * \param doc the XML-document
	 * \return the root SVG-node
	 */
	QGraphicsItem* writeHeader();

	/**
	 * Generates a string that describes the requested dash type.
	 *
	 * \param xmlNode the node to append the XML-attribute to
	 * \param lineStyle specifies the style of the dashes
	 * \param lineWidth the stroke width of the respective edge
	 */
	void writeDashArray(QGraphicsItem* xmlNode, StrokeType lineStyle, double lineWidth);

	/**
	 * Draws a single node.
	 *
	 * \param xmlNode the XML-node to print to
	 * \param v the node to be printed
	 */
	void drawNode(QGraphicsItem* xmlNode, node v);

	/**
	 * Draws a single cluster as a rectangle.
	 *
	 * \param xmlNode the XML-node to print to
	 * \param c the cluster to be printed
	 */
	void drawCluster(QGraphicsItem* xmlNode, cluster c);

	/**
	 * Determines whether a candidate arrow tip lies inside the rectangle of the node.
	 *
	 * \param point the candidate arrow tip
	 * \param e the edge of the arrow head
	 * \param v the node the arrow is facing
	 */
	bool isCoveredBy(const DPoint &point, edge e, node v);

	/**
	 * Draws an arrow head at the end of the edge.
	 * Sets the end point of the respective edge segment to the arrow head's tip.
	 *
	 * \param xmlNode the XML-node to print to
	 * \param start the start point of the edge segment the arrow head will be placed on
	 * \param end the end point of the edge segment the arrow head will be placed on, this will usually be modified
	 * \param v the node that the arrow is facing
	 * \param e the edge that the arrow belongs to
	 */
	void drawArrowHead(QGraphicsItem* xmlNode, const DPoint &start, DPoint &end, node v, edge e);

	/**
	 * Returns the size of the arrow.
	 *
	 * \param e the edge that the arrow belongs to
	 * \param v the node that the arrow is facing
	 */
	double getArrowSize(edge e, node v);

	/**
	 * Writes the requested line style to the line's XML-node.
	 *
	 * \param line the XML-node depicting the line
	 * \param e the edge associated with that line
	 */
	void appendLineStyle(QGraphicsItem* line, edge e);

	/**
	 * Draws a polygon with the respective points.
	 *
	 * \param xmlNode the XML-node to print to
	 * \param points the list of coordinates
	 * \return The generated XML-node
	 */
	QAbstractGraphicsShapeItem* drawPolygon(QGraphicsItem* xmlNode, const std::list<double> points);
};

#endif // OGDFSCENE_H
