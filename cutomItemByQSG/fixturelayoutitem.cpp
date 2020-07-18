#include "fixturelayoutitem.h"
#include <QtQuick/qsgnode.h>
#include <QSGSimpleRectNode>
#include <QQuickWindow>
#include <QSGOpaqueTextureMaterial>
#include <QSGSimpleTextureNode>
#include <QSGRectangleNode>

FixtureLayoutItem::FixtureLayoutItem(QQuickItem *parent)
    : QQuickItem(parent)
    , m_Value(0)
    , isValueChanged(false)

{
    setFlag(ItemHasContents, true);
}

FixtureLayoutItem::~FixtureLayoutItem()
{

}

QSGNode *FixtureLayoutItem::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    QSGSimpleRectNode *node = nullptr;

    if (!oldNode) {
        node = new QSGSimpleRectNode;
        node->setColor(QColor("red"));// 设置属性
        node->setRect(4 , 6 , 16 , m_Value); //设置大小，不设置不显示
        node->setFlag(QSGNode::OwnsGeometry); // 设置flag

    } else {
        node = static_cast<QSGSimpleRectNode *>(oldNode);
    }

    if(isValueChanged){
        node->setRect(4 , 6 , 16 , m_Value);
        isValueChanged = false;
    }
    node->markDirty(QSGNode::DirtyGeometry); //画布脏了重写
    return node;
}

int FixtureLayoutItem::value() const
{
    return m_Value;
}

void FixtureLayoutItem::setValue(const int &value)
{
    if(m_Value == value)
        return;

    m_Value = value;
    emit valueChanged();
    isValueChanged = true;
    update();
}


