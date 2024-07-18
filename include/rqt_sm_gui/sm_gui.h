#ifndef rqt_sm_gui_H
#define rqt_sm_gui_H


#include <rqt_gui_cpp/plugin.h>
#include <ui_sm_gui.h>

#include <image_transport/image_transport.hpp>
#include <image_transport/subscriber.hpp>

#include <sensor_msgs/msg/image.hpp>
#include <geometry_msgs/msg/point.hpp>

#include <opencv2/core/core.hpp>

#include <QAction>
#include <QImage>
#include <QList>
#include <QString>
#include <QSet>
#include <QSize>
#include <QWidget>

#include <vector>
#include <string>


namespace rqt_sm_gui {

const std::string TOPIC_NAME("/image_raw");

class SMGUI : public rqt_gui_cpp::Plugin
{

    Q_OBJECT

public:
    SMGUI();

    virtual void initPlugin(qt_gui_cpp::PluginContext& context);

    virtual void shutdownPlugin();

    virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;

    virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);

protected:

    void callbackImage(const sensor_msgs::msg::Image::ConstSharedPtr& msg);

    QWidget* widget_;
    Ui::SMGUIInterface ui_;
    image_transport::Subscriber subscriber_;
    cv::Mat conversion_mat_;


};



}


#endif
