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
        interval: 30
        running: true
        onTriggered: {
            count++
        }
    }



    Repeater {
        id: repeater
        model: 1000

        delegate: FixtureLayoutItem {
            width: 100
            height: 100
            x: parseInt(index % 100) * 100
            y: parseInt(index / 100) * 100
            value: testRoot.count % 100
            //            enableColor: false
            //            color: parseInt(testRoot.count % 100) ? Qt.rgba(Math.random(), Math.random(), Math.random(), 1 ).toString()
            //                                           : Qt.rgba(Math.random(), Math.random(), Math.random(), 1 ).toString()



            Rectangle {
                id: lightIcon
                x: 25
                y: 17
                width: 66
                height: 80
                color: "white"

            }
            Image {
                source: "qrc:/cover.png"
            }
        }

    }


}
