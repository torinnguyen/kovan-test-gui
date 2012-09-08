#include <QDebug>
#include <QScrollBar>
#include <QCleanlooksStyle>
#include <QStyle>
#include <QFile>
#include <QDir>

#include "kovantestwindow.h"
#include "ui_kovantestwindow.h"

class BiggerScrollbar : public QCleanlooksStyle {

public:
	int pixelMetric(PixelMetric metric, const QStyleOption *, const QWidget *pWidget = 0) const
	{
		if ( metric == PM_ScrollBarExtent )
		{
		   return 50;
		}
		return  QWindowsStyle::pixelMetric( metric, 0, pWidget );
	}
};

KovanTestWindow::KovanTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KovanTestWindow)
{
	QApplication::setStyle(new BiggerScrollbar);

    this->ui->setupUi(this);

#ifdef linux
	showFullScreen();
#endif

    engine = new KovanTestEngine(this);
    engine->loadAllTests();

    // Wire up all buttons
    connect(this->ui->onButton, SIGNAL(clicked(bool)), this, SLOT(onButtonClicked()));
    connect(this->ui->offButton, SIGNAL(clicked(bool)), this, SLOT(offButtonClicked()));
}

KovanTestWindow::~KovanTestWindow()
{
    delete ui;
}

void KovanTestWindow::onButtonClicked()
{

}

void KovanTestWindow::offButtonClicked()
{

}


