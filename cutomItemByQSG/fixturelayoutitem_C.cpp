#include "fixturelayoutitem_C.h"
#include <QtQuick/qsgnode.h>
#include <QSGSimpleRectNode>
#include <QQuickWindow>
#include <QSGOpaqueTextureMaterial>
#include <QSGSimpleTextureNode>
#include <QSGRectangleNode>
#include <QSGImageNode>

FixtureLayoutItem::FixtureLayoutItem(QQuickItem *parent)
    : QQuickItem(parent)
    , m_Value(0)
    , isValueChanged(false)
    , isColorChanged(false)
    , m_EnableColor(true)
    , m_pTexture(nullptr)

{
    setFlag(ItemHasContents, true);
}

FixtureLayoutItem::~FixtureLayoutItem()
{

}

QSGNode *FixtureLayoutItem::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    QSGRectangleNode *node = nullptr;

    if (!oldNode) {
        node = window()->createRectangleNode();
        node->setColor(QColor("red"));// 设置属性
        node->setRect(4 , 6 , 16 , m_Value); //设置大小，不设置不显示
        node->setFlag(QSGNode::OwnsGeometry); // 设置flag

        //目前没有调查出来创建QMl 里rectangle和直接创建的区别,
        //猜测：每个节点有自己触发绘制，若把QSGSimpleTextureNode，放到里面，会一直触发绘制。而把重起一个node可使绘制是独立的，故cpu消耗小

//        QSGRectangleNode* backgroundnode = window()->createRectangleNode();
//        backgroundnode->setColor(QColor("#FFFFFF"));// 设置属性
//        backgroundnode->setRect(25 , 17 , 66 , 80);
//        backgroundnode->setFlag(QSGNode::OwnedByParent);
//        node->appendChildNode(backgroundnode);

//        if(m_EnableColor) {

//            QSGImageNode* textTurenode = window()->createImageNode();
//             if(!m_pTexture)
//            m_pTexture = window()->createTextureFromImage(QImage(":/lightbackground.svg"));
//            textTurenode->setTexture(m_pTexture);
//            textTurenode->setRect(25 , 17 , 66 , 80);
////            textTurenode->setFlag(QSGNode::OwnedByParent);
//            textTurenode->setFlag(QSGNode::UsePreprocess);

//            node->appendChildNode(textTurenode);
//        }

    } else {
        node = static_cast<QSGRectangleNode *>(oldNode);
    }

//    if(isColorChanged && m_EnableColor) {
//        QSGRectangleNode * fistNode = static_cast<QSGRectangleNode *>(node->firstChild());
//        if(fistNode) {
//            fistNode->setColor(QColor(m_color));// 设置颜色
//        }
//        isColorChanged = false;
//    }

    if(isValueChanged){
        node->setRect(4 , 6 , 16 , m_Value);
        isValueChanged = false;
    }

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

QString FixtureLayoutItem::color() const
{
    return m_color;
}

void FixtureLayoutItem::setColor(const QString &color)
{
//    if(m_color == color)
//        return;

//    m_color = color;
//    emit colorChanged();
//    isColorChanged = true;
//    update();
}

bool FixtureLayoutItem::enableColor() const
{
    return m_EnableColor;
}

void FixtureLayoutItem::setEnableColor(const bool &enableColor)
{
    if(m_EnableColor == enableColor)
        return;

    m_EnableColor = enableColor;
    emit enableColorChanged();
}
