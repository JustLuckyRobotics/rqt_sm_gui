#include "rqt_sm_gui/sm_gui.h"

#include <pluginlib/class_list_macros.hpp>
#include <sensor_msgs/image_encodings.hpp>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>

#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>

namespace rqt_sm_gui
{

    SMGUI::SMGUI()
        : rqt_gui_cpp::Plugin(), widget_(0)
    {
        setObjectName("SM GUI Interface");
    }

    void SMGUI::initPlugin(qt_gui_cpp::PluginContext &context)
    {
        widget_ = new QWidget();

        ui_.setupUi(widget_);

        context.addWidget(widget_);

        // the camera topic name is known  so set it
        const image_transport::TransportHints hints(node_.get(), "compressed");
        auto sub_options = rclcpp::SubscriptionOptions();
        subscriber_ = image_transport::create_subscription(
            node_.get(),
            TOPIC_NAME,
            std::bind(&SMGUI::callbackImage, this, std::placeholders::_1),
            hints.getTransport(),
            rmw_qos_profile_sensor_data,
            sub_options);

        qDebug("SMGUI::init setting image topic to /image_raw/compressed");
    }

    void SMGUI::shutdownPlugin()
    {
        subscriber_.shutdown();
    }

    void SMGUI::saveSettings(qt_gui_cpp::Settings &plugin_settings, qt_gui_cpp::Settings &instance_settings) const
    {
        (void)plugin_settings;
        QString topic = TOPIC_NAME.c_str();
        // qDebug("ImageView::saveSettings() topic '%s'", topic.toStdString().c_str());
        instance_settings.setValue("topic", topic);

    }

    void SMGUI::restoreSettings(const qt_gui_cpp::Settings &plugin_settings, const qt_gui_cpp::Settings &instance_settings)
    {
        (void)plugin_settings;
    }

    void SMGUI::callbackImage(const sensor_msgs::msg::Image::ConstSharedPtr &msg)
    {
        try
        {
            // First let cv_bridge do its magic
            cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8);
            conversion_mat_ = cv_ptr->image;
        }
        catch (cv_bridge::Exception &e)
        {
            try
            {
                // If we're here, there is no conversion that makes sense, but let's try to imagine a few first
                cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(msg);
                if (msg->encoding == "CV_8UC3")
                {
                    // assuming it is rgb
                    conversion_mat_ = cv_ptr->image;
                }
                else if (msg->encoding == "8UC1")
                {
                    // convert gray to rgb
                    cv::cvtColor(cv_ptr->image, conversion_mat_, CV_GRAY2RGB);
                }
                else if (msg->encoding == "16UC1" || msg->encoding == "32FC1")
                {
                    // scale / quantify
                    double min = 0;
                    double max = 10.00;
                    if (msg->encoding == "16UC1")
                        max *= 1000;
                    if (true)
                    {
                        // dynamically adjust range based on min/max in image
                        cv::minMaxLoc(cv_ptr->image, &min, &max);
                        if (min == max)
                        {
                            // completely homogeneous images are displayed in gray
                            min = 0;
                            max = 2;
                        }
                    }
                    cv::Mat img_scaled_8u;
                    cv::Mat(cv_ptr->image - min).convertTo(img_scaled_8u, CV_8UC1, 255. / (max - min));
                    cv::cvtColor(img_scaled_8u, conversion_mat_, CV_GRAY2RGB);
                }
                else
                {
                    qWarning("ImageView.callback_image() could not convert image from '%s' to 'rgb8' (%s)", msg->encoding.c_str(), e.what());
                    ui_.image_frame->setImage(QImage());
                    return;
                }
            }
            catch (cv_bridge::Exception &e)
            {
                qWarning("SMGUI.callback_image() while trying to convert image from '%s' to 'rgb8' an exception was thrown (%s)", msg->encoding.c_str(), e.what());
                ui_.image_frame->setImage(QImage());
                return;
            }
        }

        // image must be copied since it uses the conversion_mat_ for storage which is asynchronously overwritten in the next callback invocation
        QImage image(conversion_mat_.data, conversion_mat_.cols, conversion_mat_.rows, conversion_mat_.step[0], QImage::Format_RGB888);
        ui_.image_frame->setImage(image);
        ui_.image_frame->setInnerFrameFixedSize(ui_.image_frame->getImage().size());
    }

}

// ImageView::ImageView()
//   : rqt_gui_cpp::Plugin()
//   , widget_(0)
//   , num_gridlines_(0)
//   , rotate_state_(ROTATE_0)
// {
//   setObjectName("ImageView");
// }

// void ImageView::initPlugin(qt_gui_cpp::PluginContext& context)
// {
//   widget_ = new QWidget();
//   ui_.setupUi(widget_);

//   if (context.serialNumber() > 1)
//   {
//     widget_->setWindowTitle(widget_->windowTitle() + " (" + QString::number(context.serialNumber()) + ")");
//   }
//   context.addWidget(widget_);

//   updateTopicList();
//   ui_.topics_combo_box->setCurrentIndex(ui_.topics_combo_box->findText(""));
//   connect(ui_.topics_combo_box, SIGNAL(currentIndexChanged(int)), this, SLOT(onTopicChanged(int)));

//   ui_.refresh_topics_push_button->setIcon(QIcon::fromTheme("view-refresh"));
//   connect(ui_.refresh_topics_push_button, SIGNAL(pressed()), this, SLOT(updateTopicList()));

//   ui_.zoom_1_push_button->setIcon(QIcon::fromTheme("zoom-original"));
//   connect(ui_.zoom_1_push_button, SIGNAL(toggled(bool)), this, SLOT(onZoom1(bool)));

//   connect(ui_.dynamic_range_check_box, SIGNAL(toggled(bool)), this, SLOT(onDynamicRange(bool)));

//   ui_.save_as_image_push_button->setIcon(QIcon::fromTheme("document-save-as"));
//   connect(ui_.save_as_image_push_button, SIGNAL(pressed()), this, SLOT(saveImage()));

//   connect(ui_.num_gridlines_spin_box, SIGNAL(valueChanged(int)), this, SLOT(updateNumGridlines()));

//   // set topic name if passed in as argument
//   const QStringList& argv = context.argv();
//   if (!argv.empty()) {
//     arg_topic_name = argv[0];
//     selectTopic(arg_topic_name);
//   }
//   pub_topic_custom_ = false;

//   ui_.image_frame->setOuterLayout(ui_.image_layout);

//   QRegExp rx("([a-zA-Z/][a-zA-Z0-9_/]*)?"); //see http://www.ros.org/wiki/ROS/Concepts#Names.Valid_Names (but also accept an empty field)
//   ui_.publish_click_location_topic_line_edit->setValidator(new QRegExpValidator(rx, this));
//   connect(ui_.publish_click_location_check_box, SIGNAL(toggled(bool)), this, SLOT(onMousePublish(bool)));
//   connect(ui_.image_frame, SIGNAL(mouseLeft(int, int)), this, SLOT(onMouseLeft(int, int)));
//   connect(ui_.publish_click_location_topic_line_edit, SIGNAL(editingFinished()), this, SLOT(onPubTopicChanged()));

//   connect(ui_.smooth_image_check_box, SIGNAL(toggled(bool)), ui_.image_frame, SLOT(onSmoothImageChanged(bool)));

//   connect(ui_.rotate_left_push_button, SIGNAL(clicked(bool)), this, SLOT(onRotateLeft()));
//   connect(ui_.rotate_right_push_button, SIGNAL(clicked(bool)), this, SLOT(onRotateRight()));

//   // Make sure we have enough space for "XXX °"
// #if QT_VERSION >= QT_VERSION_CHECK(5, 11, 0)
//   // QFontMetrics::width(QChar) is deprecated starting from qt version 5.11.0
//   // https://doc.qt.io/qt-5/qfontmetrics.html#horizontalAdvance-1
//   ui_.rotate_label->setMinimumWidth(
//     ui_.rotate_label->fontMetrics().horizontalAdvance("XXX°")
//   );
// #else
//   ui_.rotate_label->setMinimumWidth(
//     ui_.rotate_label->fontMetrics().width("XXX°")
//   );
// #endif

//   hide_toolbar_action_ = new QAction(tr("Hide toolbar"), this);
//   hide_toolbar_action_->setCheckable(true);
//   ui_.image_frame->addAction(hide_toolbar_action_);
//   connect(hide_toolbar_action_, SIGNAL(toggled(bool)), this, SLOT(onHideToolbarChanged(bool)));
// }

// void ImageView::shutdownPlugin()
// {
//   subscriber_.shutdown();
//   pub_mouse_left_.reset();
// }

PLUGINLIB_EXPORT_CLASS(rqt_sm_gui::SMGUI, rqt_gui_cpp::Plugin)
