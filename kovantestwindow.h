#ifndef KOVANTESTWINDOW_H
#define KOVANTESTWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFile>
#include "kovantestengine.h"

const char SEQUENCE[] = "132231";

namespace Ui {
class KovanTestWindow;
}

class KovanTestWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit KovanTestWindow(QWidget *parent = 0);
    ~KovanTestWindow();
    void setStatusText(QString *message);
    void setProgressBar(double progress);
    void setProgressText(QString &text);
	void setErrorString(QString &message);
    void addTestLog(QString &message);
	void finishTests(bool successful);

private:
    Ui::KovanTestWindow *ui;
    KovanTestEngine *engine;
	QString errorString;
	unsigned int sequencePosition;
	QString serialLabelString;
	QFile logFile;

	void advanceDebugSequence(const char c);
	void openLogFile();

public slots:

    void onButtonClicked();
    void offButtonClicked();
};

#endif // KOVANTESTWINDOW_H
