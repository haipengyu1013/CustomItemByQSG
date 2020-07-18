import QtQuick 2.12
import FixtureLayoutItem 1.0
import QtGraphicalEffects 1.12

Rectangle {
    id: testRoot
    width: 1920
    height: 1040
    color: "#26282a"

    property int count: 4
    property int count2: 4

    Timer {
        repeat: true
        interval: 50
        running: true
        onTriggered: {
            count++
        }
    }


    Timer {
        repeat: true
        interval: 50
        running: true
        onTriggered: {
            count2++
        }
    }

    //猜测：每个节点有自己触发绘制，若把QSGSimpleTextureNode，放到里面，会一直触发绘制。而把重起一个node可使绘制是独立的，故cpu消耗小
    Repeater {
        id: repeater
        model: 2000

        delegate: FixtureLayoutItem {
            width: 100
            height: 100
            x: parseInt(index % 100) * 100
            y: parseInt(index / 100) * 100
            value: testRoot.count % 100
//            enableColor: false
//            color: parseInt(testRoot.count % 100) ? Qt.rgba(Math.random(), Math.random(), Math.random(), 1 ).toString()
//                                           : Qt.rgba(Math.random(), Math.random(), Math.random(), 1 ).toString()

            color: "white"


                        Image {
                            id: lightIcon
                            x: 5
                            width: 80
                            height: 80
                            source: "qrc:/lightbackground.svg"
                        }

            //            Image {
//                id: lightIcon
//                x: 5
//                width: 80
//                height: 80
//                source: "qrc:/test.png"
//                visible: !overlay.visible
//            }

//            Rectangle {
//                id: overlay
//                anchors.fill: lightIcon
////                visible: false
//                color: count2 % 2 == 1 ? Qt.rgba(Math.random(), Math.random(), Math.random(), 1 ).toString()
//                                       : Qt.rgba(Math.random(), Math.random(), Math.random(), 1 ).toString()
//            }
//            ColorOverlay {
//                id: overlay
//                anchors.fill: lightIcon
//                source: lightIcon
////                visible: false
//                color: count2 % 2 == 1 ? Qt.rgba(Math.random(), Math.random(), Math.random(), 1 ).toString()
//                                       : Qt.rgba(Math.random(), Math.random(), Math.random(), 1 ).toString()
//            }
        }

//        delegate: Item {
//            width: 10
//            height: 10
//            x: parseInt(index % 100) * 10
//            y: parseInt(index / 100) * 10
//            clip: true

//            Rectangle {
//                width: 5
//                height: 10
//                color: "yellow"
//                y: parseInt(testRoot.count % 10)
//            }


//            Image {
//                id: lightIcon
//                width: 10
//                height: 10
//                source: "qrc:/lightbackground.svg"
//                visible: false
//            }

//            ColorOverlay {
//                anchors.fill: lightIcon
//                source: lightIcon
//                color: testRoot.count % 2 == 1 ? Qt.rgba( Math.random(), Math.random(), Math.random(), 1 ).toString()
//                                                : Qt.rgba( Math.random(), Math.random(), Math.random(), 1 ).toString()
//            }
//        }
    }

//    Rectangle {
//        width: 100
//        height: 100
//        color: "black"

//        MouseArea {
//            anchors.fill: parent
//            onClicked: {
//                print("sdfdsf")
//                count++
//            }
//        }
//    }

}
