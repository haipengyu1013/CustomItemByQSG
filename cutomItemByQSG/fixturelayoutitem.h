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
public:
    FixtureLayoutItem(QQuickItem *parent = 0);
    ~FixtureLayoutItem();

    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);
    int value() const;
    void setValue(const int &value);
signals:
    void valueChanged();


private:
    int m_Value;
    bool isValueChanged;


};

#endif // FIXTURELAYOUTITEM_H
