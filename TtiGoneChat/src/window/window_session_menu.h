/*****************************************************************//**
 * \file   window_session_menu.h
 * \brief  侧边朋友栏列表弹出菜单
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef WINDOW_FRIEND_MENU_H
#define WINDOW_FRIEND_MENU_H

#include <QStyledItemDelegate>
#include <QListView>

namespace Data
{
class SessionLabelModel;
} // namespace Data

namespace Window {

class SessionLabelDelegate : public QStyledItemDelegate {
  Q_OBJECT
 public:
  SessionLabelDelegate(QObject *parent = nullptr);

 protected:
  // 绘制
  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const override;
  // 大小
  QSize sizeHint(const QStyleOptionViewItem &option,
                 const QModelIndex &index) const override;
};

class SessionMenu : public QListView {
  Q_OBJECT
 public:
  explicit SessionMenu(QWidget *parent = nullptr);
  ~SessionMenu();

 private:
  void init();

 signals:
  void chatChanged(int64_t index);

 private:
  //std::unique_ptr<SessionLabelDelegate> session_label_delegate_;
  //std::unique_ptr<Data::SessionLabelModel> session_label_model_;

  //not_null<SessionLabelDelegate *> session_label_delegate_;
  //not_null<Data::SessionLabelModel *> session_label_model_;

  SessionLabelDelegate * session_label_delegate_;
  Data::SessionLabelModel * session_label_model_;
};

}  // namespace Window

#endif  // WINDOW_FRIEND_MENU_H
