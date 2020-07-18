#ifndef FIXTURELAYOUTITEM_H
#define FIXTURELAYOUTITEM_H

#include <QQuickItem>
#include <QSGEngine>
#include <QSGSimpleTextureNode>
#include <QSGTexture>

class FixtureLayoutItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(bool enableColor READ enableColor WRITE setEnableColor NOTIFY enableColorChanged)

public:
    FixtureLayoutItem(QQuickItem *parent = 0);
    ~FixtureLayoutItem();

    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

    int value() const;
    void setValue(const int &value);

    QString color() const;
    void setColor(const QString &color);

    bool enableColor() const;
    void setEnableColor(const bool &enableColor);

signals:
    void valueChanged();
    void colorChanged();
    void enableColorChanged();

private:
    int m_Value;
    QString m_color;
    bool isValueChanged;
    bool isColorChanged;

    bool m_EnableColor;
    QSGTexture* m_pTexture;

};

#endif // FIXTURELAYOUTITEM_H
