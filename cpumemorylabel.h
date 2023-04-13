#ifndef CPUMEMORYLABEL_H
#define CPUMEMORYLABEL_H
#include <QLabel>

class QProcess;

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT CpuMemoryLabel : public QLabel
#else
class CpuMemoryLabel : public QLabel
#endif

{
	Q_OBJECT
public:
	CpuMemoryLabel(QWidget *parent = 0);
    ~CpuMemoryLabel();

private:
    quint64 totalNew, idleNew, totalOld, idleOld;
    quint64 cpuPercent;

    quint64 memoryPercent;
    quint64 memoryAll;
    quint64 memoryUse;
    quint64 memoryFree;

	QTimer *timerCPU;       //定时器获取CPU信息
	QTimer *timerMemory;    //定时器获取内存信息
	QProcess *process;      //linux执行命令

private slots:
	void getCPU();          //获取cpu
	void getMemory();       //获取内存
	void readData();        //读取数据
	void setData();         //设置数据

public:
    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
	void start(int interval);
	void stop();

Q_SIGNALS:
	void textChanged(QString text);
    void valueChanged(quint64 cpuPercent, quint64 memoryPercent, quint64 memoryAll, quint64 memoryUse, quint64 memoryFree);
};

#endif // CPUMEMORYLABEL_H
