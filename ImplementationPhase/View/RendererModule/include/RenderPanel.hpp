#ifndef RENDERPANEL_H
#define RENDERPANEL_H
#include "ContentView.hpp"
#include <QDialog>
#include "Renderer.hpp"
namespace Ui {
class RenderPanel;
}

class RenderPanel : public QDialog ,  public ContentView , public Renderer
{
    Q_OBJECT

public:
    explicit RenderPanel(QWidget *parent = nullptr);
    ~RenderPanel();

private slots:
    void on_start_clicked();

    void on_addImage_clicked();

    void on_save_clicked();

    void on_currentImageStart_clicked();

    void on_trainingbutt_clicked();

    void on_trainingsss_clicked();

private:
    QPixmap* pixmap;
    Ui::RenderPanel *ui;
    std::string path;
};

#endif // RENDERPANEL_H
