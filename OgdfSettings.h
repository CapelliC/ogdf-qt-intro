/*
 * ogdf-qt-intro
 * @ CapelliC 2017
 */

#ifndef OGDFSETTINGS_H
#define OGDFSETTINGS_H

#include <QSettings>
#include <string>

class OgdfSettings : public QSettings
{
    Q_OBJECT

    typedef std::string string;

    double m_margin;
    int    m_fontSize;
    double m_curviness;
    bool m_bezierInterpolation;
    string m_fontColor;
    string m_fontFamily;
    string m_width;
    string m_height;

public:
    OgdfSettings();

    //! Returns whether Bézier-interpolation for curved edges is enabled.
    bool bezierInterpolation() const { return m_bezierInterpolation; }

    //! Returns the size of the margin around the drawing.
    double margin() const { return m_margin; }

    //! Returns the curviness of the edges (value ranges from 0 to 1).
    double curviness() const { return m_curviness; }

    //! Returns the default font size (font height in pixels).
    int fontSize() const { return m_fontSize; }

    //! Returns the default font color.
    const string &fontColor() const { return m_fontColor; }

    //! Returns the default font family.
    const string &fontFamily() const { return m_fontFamily; }

    //! Returns the default width
    const string &width() const { return m_width; }

    //! Returns the default height
    const string &height() const { return m_height; }

    //! Sets the size of the margin around the drawing to \a m.
    void margin(double m) { m_margin = m; }

    //! Sets the curviness of all edges (value ranges from 0 to 1).
    void curviness(double value) {
        if(value > 1 || value < 0) {
            //throw PreconditionViolatedException();
        }

        m_curviness = value;
    }

    //! Enables or disables Bézier-interpolation.
    void bezierInterpolation(bool enable) { m_bezierInterpolation = enable; }

    //! Sets the default font size (font height in pixels) to \a fs.
    void fontSize(int fs) { m_fontSize = fs; }

    //! Sets the default font color to \a fc.
    void fontColor(const string &fc) { m_fontColor = fc; }

    //! Sets the default font family to \a fm.
    void fontFamily(const string &fm) { m_fontFamily = fm; }

    //! Sets the width.
    /**
     * The value should include a unit of measure (e.g., percentage for relative width or pixel values).
     */
    void width(const string &width) { m_width = width; }

    //! Sets the height.
    /**
     * The value should include a unit of measure (e.g., percentage for relative height or pixel values).
     */
    void height(const string &height) { m_height = height; }
};

#endif // OGDFSETTINGS_H
