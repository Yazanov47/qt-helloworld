#include <QApplication>
#include <QWidget>
#include <QPainter>

class HelloWorldWidget : public QWidget
{
public:
    HelloWorldWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);

        QPainter painter(this);

        // Set the background color to black for the lower half
        painter.fillRect(rect(), Qt::black);

        // Calculate the rectangle size for the upper half
        int rectWidth = width();
        int rectHeight = height() / 2;

        // Calculate the position of the rectangle in the upper half
        int rectX = 0;
        int rectY = 0;

        // Draw the blue rectangle in the upper half
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::blue);
        painter.drawRect(rectX, rectY, rectWidth, rectHeight);

        // Set the font and color for the text in the upper half
        painter.setFont(QFont("Arial", 30, QFont::Bold));
        painter.setPen(Qt::white);

        // Calculate the center position to display the text in the upper half
        QRect textRect = QRect(rectX, rectY, rectWidth, rectHeight).adjusted(10, 10, -10, -10);
        painter.drawText(textRect, Qt::AlignCenter, "Hello World");

        // Calculate the center position to display additional text in the lower half
        int lowerRectY = rectHeight;
        QRect lowerTextRect = QRect(rectX, lowerRectY, rectWidth, rectHeight).adjusted(10, 10, -10, -10);
        painter.drawText(lowerTextRect, Qt::AlignCenter, "Good evening, London!");
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    HelloWorldWidget widget;
    widget.resize(480, 800);
    widget.show();

    return app.exec();
}
