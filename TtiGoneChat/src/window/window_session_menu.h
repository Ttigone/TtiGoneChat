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
private:
  mutable QHash<QString, QPixmap> icon_cache;
};

class SessionMenu : public QListView {
  Q_OBJECT
 public:
  explicit SessionMenu(QWidget *parent = nullptr);
  ~SessionMenu();


 protected:
  bool eventFilter(QObject *watched, QEvent *event) override;

 signals:
  void chatChanged(int64_t index);

private slots:
  void loadMoreData();
  void showScrollBar();
  void hideScrollBar();

 private:
  void init();
  void setupModel();

  std::unique_ptr<SessionLabelDelegate> session_label_delegate_;
  std::unique_ptr<Data::SessionLabelModel> session_label_model_;
  QPointer<QTimer> enterTimer;
  QPointer<QTimer> leaveTimer;
  bool isScrollBarVisible = false;
  int currentPage = 0;
  const int pageSize = 20;  // 每页 20 条数据
};

}  // namespace Window

#endif  // WINDOW_FRIEND_MENU_H
