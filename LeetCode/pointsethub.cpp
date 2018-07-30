#include "pointsethub.h"
#include <vtkRenderWindow.h>
#include <QFileDialog>

PointSetHub::PointSetHub(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    initialVtkWidget();
    connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
    connect(ui.pushButton, SIGNAL(triggered()), this, SLOT(sampleButtonPressed()));
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(button_tets()));
}

PointSetHub::~PointSetHub()
{

}

void PointSetHub::initialVtkWidget()
{
    cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    viewer->addPointCloud(cloud, "cloud");

    ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
    ui.qvtkWidget->update();
}

void PointSetHub::onOpen()
{
    //只能打开Ply文件
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open PointCloud"), ".",
        tr("Open PCD files(*.ply)"));

    if (!fileName.isEmpty())
    {
        std::string file_name = fileName.toStdString();
      
        pcl::io::loadPLYFile(file_name, *cloud);

        viewer->updatePointCloud(cloud, "cloud");
        ui.textEdit->setText("Load succeed");
        viewer->resetCamera();
        ui.qvtkWidget->update();
    }
}


void PointSetHub::sampleButtonPressed()
{
    ui.textEdit->setText("Start to down sample");
    ui.textEdit->setText("The initial point cloud size are:" + cloud->size());
    
  
    new pcl::PCLPointCloud2();
    // 创建滤波器对象
    pcl::VoxelGrid<pcl::PointXYZ> sor;
    sor.setInputCloud(cloud);
    sor.setLeafSize(1.0f,1.0f, 1.0f);
    sor.filter(*cloud);

    viewer->updatePointCloud(cloud, "cloud");
    viewer->resetCamera();
    ui.qvtkWidget->update();

}

void PointSetHub::button_tets()
{
    ui.textEdit->setText("button_tets");


}