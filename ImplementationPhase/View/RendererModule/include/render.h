#ifndef RENDER_H
#define RENDER_H
#include "contentview.h"
#include <QDialog>
#include "renderer.h"
namespace Ui {
class Render;
}

class Render : public QDialog ,  public ContentView , public Renderer
{
    Q_OBJECT

public:
    explicit Render(QWidget *parent = nullptr);
    ~Render();

private slots:
    void on_start_clicked();

    void on_addImage_clicked();

    void on_save_clicked();

    void on_currentImageStart_clicked();

    void on_trainingbutt_clicked();

    void on_trainingsss_clicked();

private:
    QPixmap* pixmap;
    Ui::Render *ui;
    std::string path;
};

#endif // RENDER_H
